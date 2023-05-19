import asyncio
import pyppeteer
import requests
import time

async def loginfunction(loginUrl: str):
    width, height = 1400, 800
    browser = await pyppeteer.launch(headless=False,
                                    userdataDir = '/tmp',
                                    executablePath = '/usr/bin/google-chrome',
                                     args=[f'--window-size={width},{height}'])
    page = await browser.newPage()
    await page.setViewport({'width': width, 'height': height})
    await page.goto(loginUrl)
    await page.waitForSelector("#normal_use_menu > ul > li:nth-child(1) > a", timeout=30000)
    element = await page.querySelector("#normal_use_menu > ul > li:nth-child(1) > a")
    await element.click()
    # element = await page.waitForSelector('#theOptArea > tbody > tr > td:nth-child(2) > a', timeout=30000)
    element = await page.querySelector("#reportArea > tbody > tr:nth-child(1) > td:nth-child(2) > a")
    await element.click()
    while True:
        pass


def main():
    url = 'https://xk.henu.edu.cn/cas/login.action'
    asyncio.get_event_loop().run_until_complete(loginfunction(url))


if __name__ == '__main__':
    main()
