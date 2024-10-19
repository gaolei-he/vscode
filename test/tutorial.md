1. 首先是对定理文件进行拆分，拆分长度超过4096字节的定理文件
```bash
python divide.py
```
随后输入将要拆分的定理文件的路径，程序会自动拆分该路径下所有长度超过4096字节的定理文件，并在定理路径下生成一个`filter_list.txt`文件，其中包含了已被拆分的文件，以便接下来处理不在转换这些拆分前的文件

2. 将拆分后的定理文件转换成json格式
需要更改`Lean4client.py`中的`work_dir`和`repl_path`变量，然后运行
```bash
pytho Lean4client.py
```
随后输入定理文件所在目录，程序会读取目录下`filter_list.txt`文件，自动跳过拆分前的定理文件，将剩余的定理文件转换成json格式

3. 将各个json文件合并成可训练的数据集
```bash
python merge_json.py
```

4. 编辑`LLaMA-Factory/data/dataset_info.json`文件，将新生成的数据集信息添加到该文件中（合并后的数据集放置在`LLaMA-Factory/data/`目录下）
需要添加一项，格式如下

```json
"mathlib4": { // 数据集名称，用于后续训练时指定数据集
    "file_name": "mathlib4.json", // 数据集文件名，即合并后的数据集文件名
    "columns": {
      "prompt": "instruction",
      "query": "input",
      "response": "output",
      "history": "history"
    }
  }
```

5. 修改训练脚本`LLaMA-Factory/examples/train_lora/llama3_lora_sft_ds0.yaml`，以下是一个例子
```yaml
### model
model_name_or_path: /data/wangjianlin/hgl/LLaMA-Factory/models/llama3_lora_sft_data_adalean_out_part  ## 基础模型路径

### method
stage: sft
do_train: true
finetuning_type: lora
lora_target: all
deepspeed: examples/deepspeed/ds_z0_config.json

### dataset
dataset: data_valid56_adamcts_withoutv ## 使用哪个数据集训练基础模型，即上一步中添加的数据集名称
template: llama3
cutoff_len: 2048
max_samples: 1000000
overwrite_cache: true
preprocessing_num_workers: 16

### output
output_dir: saves/llama3-8b-lora-data_valid56_adamcts_withoutv ## 模型训练结果保存路径
logging_steps: 10
save_steps: 50
plot_loss: true
overwrite_output_dir: true

### train
per_device_train_batch_size: 4
gradient_accumulation_steps: 4
learning_rate: 1.0e-4
num_train_epochs: 200
lr_scheduler_type: cosine
warmup_ratio: 0.1
bf16: true
ddp_timeout: 180000000

### eval
# val_size: 0.1
# per_device_eval_batch_size: 1
# eval_strategy: steps
# eval_steps: 500
```

6. 训练模型
可以指定使用哪几个GPU，修改`CUDA_VISIBLE_DEVICES`环境变量，例如使用第0、1、2、3号GPU
```bash
export CUDA_VISIBLE_DEVICES=0,1,2,3
```
然后运行训练脚本（需在`LLaMA-Factory`目录下运行）
```bash
llamafactory-cli train examples/train_lora/llama3_lora_sft_ds0.yaml
```

7. 训练完毕，导出模型
首先修改`LLaMA-Factory/examples/merge_lora/llama3_lora_sft.yaml`文件，以下是一个例子
```yaml
### Note: DO NOT use quantized model or quantization_bit when merging lora adapters

### model
model_name_or_path: /data/wangjianlin/hgl/LLaMA-Factory/models/llama3_lora_sft_data_adalean_out_part # 基础模型路径，即在该模型上微调，则以该模型为基础进行导出
adapter_name_or_path: /data/wangjianlin/hgl/LLaMA-Factory/saves/llama3-8b-lora-data_valid56_bfs_clear/checkpoint-4000 # 选取模型训练结果目录下最新的checkpoint
template: llama3
finetuning_type: lora

### export
export_dir: models/llama3_lora_sft_data_valid56_bfs_clear # 导出最终模型的路径（相对于LLaMA-Factory目录）
export_size: 10
export_device: cpu
export_legacy_format: false
```