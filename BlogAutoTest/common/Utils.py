
#创建一个浏览器对象
import datetime
import os.path
import sys

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager

class Driver:
    driver = ""

    def __init__(self):
        options = webdriver.ChromeOptions()
        self.driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=options)
        self.driver.implicitly_wait(2)

    def GetScreeShot(self):
        dirname = datetime.datetime.now().strftime("%Y-%m-%d")

        #判断dirname文件夹是否已经存在，若不存在则创建文件夹
        if not os.path.exists("../images/" + dirname):
            os.mkdir("../images/" + dirname)

        filename = sys._getframe().f_back.f_code.co_name+"-"+datetime.datetime.now().strftime("%Y-%m-%d-%H%M%S")+".png"
        self.driver.save_screenshot("../images/"+dirname+"/"+filename)

BlogDriver = Driver() # 单例模式