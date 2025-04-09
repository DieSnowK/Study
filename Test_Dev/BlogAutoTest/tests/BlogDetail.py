from selenium.webdriver.common.by import By

from common.Utils import BlogDriver
#测试博客详情页
class BlogDeail:
    url = ""
    driver = ""
    def __init__(self):
        self.url = "http://192.168.47.135:8653/blog_system/blog_detail.html?blogId=16"
        self.driver = BlogDriver.driver
        self.driver.get(self.url)

    #登陆状态下博客详情页的测试
    def DetailTestByLogin(self):
        #检查标题
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.right > div > h3")
        #检查时间
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.right > div > div.date")
        #检查内容
        self.driver.find_element(By.CSS_SELECTOR,"#content > p")
        #屏幕截图
        BlogDriver.getScreeShot()