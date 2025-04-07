from selenium.webdriver.common.by import By

from common.Utils import BlogDriver
#博客首页测试用例
class BlogList:
    url = ""
    driver = ""
    def __init__(self):
        self.url = "http://192.168.47.135:8653/blog_system/blog_list.html"
        self.driver = BlogDriver.driver
        self.driver.get(self.url)
    #测试首页(登录情况下）
    def ListTestByLogin(self):
        #测试博客标题是否存在
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.right > div:nth-child(1) > div.title")
        #测试博客内容是否存在
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.right > div:nth-child(1) > div.desc")
        #测试按钮是否存在
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.right > div:nth-child(1) > a")

        #个人信息-检查昵称是否存在
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.left > div > h3")
        #添加屏幕截图
        BlogDriver.getScreeShot()

    #测试首页(未登录情况下）

