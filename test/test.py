#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''开机自动登录校园网'''

import asyncio
import pyppeteer
import time
tmp_dir = '/tmp'  # 临时文件夹
chrome_path = '/usr/bin/google-chrome'  # chrome浏览器路径
async def f():
    width, height = 1400, 800 # 窗口大小
    browser = await pyppeteer.launch(headless=False,
                                    userdataDir = tmp_dir,
                                    executablePath = chrome_path,
                                        args=[f'--window-size={width},{height}'])
    for i in range(11, 13):
        page = await browser.newPage()
        await page.setViewport({'width': width, 'height': height})
        url = "https://www.baidu.com"
        await page.goto(url)

    time.sleep(1)
asyncio.get_event_loop().run_until_complete(f())