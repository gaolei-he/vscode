#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''开机自动登录校园网'''

import asyncio
import pyppeteer
import requests
import time


async def loginfunction(loginUrl: str):

    start_time = time.time()
    while True:
        if time.time() - start_time > 60:
            return  # 超时未连接到校园网，退出
        try:
            response = requests.get(loginUrl, timeout=5)
            if response.status_code == 200:
                break  # 连接到校园网，准备登录
        except KeyboardInterrupt as e:
            return
        except:
            pass  # 未连接到网络，继续尝试

    width, height = 1400, 800
    browser = await pyppeteer.launch(headless=False,
                                    userdataDir = '/tmp',
                                    executablePath = '/usr/bin/google-chrome',
                                     args=[f'--window-size={width},{height}'])
    page = await browser.newPage()
    await page.setViewport({'width': width, 'height': height})
    await page.goto(loginUrl)
    element = await page.querySelector("#username")
    await element.type("******")
    element = await page.querySelector("#password")
    await element.type("******")
    element = await page.querySelector("#login-account")
    await element.click()
    await page.waitForSelector("body > div.success > p", timeout=30000)
    await browser.close()


def main():
    url = 'http://172.22.255.18/srun_portal_pc?ac_id=1&theme=pro'
    asyncio.get_event_loop().run_until_complete(loginfunction(url))


if __name__ == '__main__':
    main()
