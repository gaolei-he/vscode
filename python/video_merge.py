# from moviepy.editor import *
# import os

# # 定义一个数组

# # 访问 video 文件夹 (假设视频都放在这里面)
# for root, dirs, files in os.walk("./video"):
#     # 按文件名排序
#     files.sort()
#     # 遍历所有文件
#     for file in files:
#         # 如果后缀名为 .mp4
#         if os.path.splitext(file)[1] == '.mp4':
#             # 拼接成完整路径
#             filePath = os.path.join(root, file)
#             # 载入视频
#             video = VideoFileClip(filePath)
#             video.write_videofile(filePath, fps=24)
#             # 添加到数组

# 拼接视频
# final_clip = concatenate_videoclips(L)

# 生成目标视频文件
# final_clip.to_videofile("./target.mp4", fps=24, remove_temp=False)
import subprocess

c = 'ffmpeg -y -i ' + video_input_path + ' -r 30 -s 112x112 -c:v libx264 -b:v 3M -strict -2 -movflags faststart '+video_output_path

subprocess.call(c, shell=True)