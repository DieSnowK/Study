from tests import BlogLogin
from tests import BlogList
from tests import BlogDetail
from tests import BlogEdit
from common.Utils import BlogDriver

# 项目中程序的执行入口
if __name__ == "__main__":
    BlogLogin.BlogLogin().LoginFailTest()
    BlogLogin.BlogLogin().LoginSucTest()
    # #登陆成功之后就可以调用博客首页测试首页的用例（登陆状态）
    BlogList.BlogList().ListTestByLogin()
    # #测试登录状态下的博客详情页
    BlogDetail.BlogDeail().DetailTestByLogin()
    #博客编辑页面
    BlogEdit.BlogEdit().EditSucTestByLogin()
    #指定浏览器的退出
    BlogDriver.driver.quit()