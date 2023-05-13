import asyncio
import pyppeteer
async def loginfunction(lgoinUrl: str):
    width, height = 1400, 800
    browser = await pyppeteer.launch(headless=False,
                                    userdataDir = '/tmp',
                                     args=[f'--window-size={width},{height}'])
    page = await browser.newPage()
    await page.setViewport({'width': width, 'height': height})
    await page.goto(lgoinUrl)
    element = await page.querySelector("#username")
    await element.type("2112080029")
    element = await page.querySelector("#password")
    await element.type("5he2gao1leiH")
    element = await page.querySelector("#login-account")
    element.click()
    await browser.close()

def main():
    url = 'http://172.22.255.18/srun_portal_pc?ac_id=1&theme=pro'
    loop = asyncio.get_event_loop()
    loop.run_until_complete(loginfunction(url))
main()