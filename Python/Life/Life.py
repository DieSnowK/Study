# 自主实现一个人生重开模拟器练练手
import random
import sys
import time

print("+--------------------------------------------------------------+")
print("|                                                              |")
print("|                    花有重开日, 人无再少年                        |")
print("|                                                              |")
print("|                    欢迎来到, 人生重开模拟器                       |")
print("|                                                              |")
print("+--------------------------------------------------------------+")

# 设置初始属性
# 颜值，体质，治理，家境，约定每个属性的范围为`[1, 10]`，并且总和不能超过20
# 使用循环，使玩家在输入错误的时候，可以重新输入
while True:
    print("请设置初始属性(可用点数总数为 20)")
    face = int(input("请输入颜值(1~10):"))
    strong = int(input("请输入体质(1~10):"))
    iq = int(input("请输入智力(1~10):"))
    home = int(input("请输入家境(1~10):"))

    # 通过条件语句，对于用户输入的属性做校验检查
    if face < 1 or face > 10:
        print("颜值设置有误")
        continue
    if strong < 1 or strong > 10:
        print("体质设置有误")
        continue
    if iq < 1 or iq > 10:
        print("智力设置有误")
        continue
    if home < 1 or home > 10:
        print("家境设置有误")
        continue
    if face + strong + iq + home > 20:
        print("总数超过20了!")
        continue

    # 如果上面条件都没有触发，则认为输入的数据合法
    # 此时就可以跳出循环
    print("初始属性输入完毕")
    print(f"颜值：{face}，体质：{strong}, 智力：{iq}，家境：{home}")
    break

# 生成角色性别
# 使用random.randint(beg, int)，就能生成[beg, end]的随机整数
point = random.randint(1, 6)
gender = "Secret"
if point % 2 == 0:
    gender = 'Boy'
    print("你是个男孩")
if point % 2 == 1:
    gender = 'Girl'
    print("你是个女孩")

# 设置角色家境
point = random.randint(1, 3) # 掷色子
if home == 10:
    print('你出生在帝都, 你的父母是高官政要')
    home += 1
    iq += 1
    face += 1
elif 7 <= home <= 9:
    if point == 1:
        print('你出生在大城市, 你的父母是公务员')
        face += 2
    elif point == 2:
        print('你出生在大城市, 你的父母是大企业高管')
        home += 2
    else:
        print('你出生在大城市, 你的父母是大学教授')
        iq += 2
elif 4 <= home <= 6:
    if point == 1:
        print('你出生在三线城市, 你的父母是教师')
        iq += 1
    elif point == 2:
        print('你出生在镇上, 你的父母是医生')
        strong += 1
    else:
        print("你出生在镇上, 你的父母是个体户")
        home += 1
else:
    if 1 <= point <= 2:
        print('你出生在村里, 你的父母是辛苦劳作的农民')
        strong += 1
        face -= 2
    elif 3 <= point <= 4:
        print('你出生在穷乡僻壤, 你的父母是无业游民')
        home -= 1
    else:
        print('你出生在镇上, 你父母感情不和')
        strong -= 1

# 幼年经历
for age in range(1, 11):
    # 把一整年的经历都放在一个字符串内，最后统一打印
    info = f'你今年 {age} 岁, '
    point = random.randint(1, 3)

    # 性别触发事件
    if gender == 'Girl' and home <= 3 and point == 1:
        info += '你家里人重男轻女思想非常严重, 你被遗弃了!'
        print(info)
        print("游戏结束!")
        sys.exit(0)
    # 体质触发的事件
    elif strong < 6 and point != 3:
        info += '你生了一场病, '
        if home >= 5:
            info += '在父母的精心照料下恢复了健康'
            strong += 1
            home -= 1
        else:
            info += '你的父母没精力管你, 你的身体状况更糟糕了'
            strong -= 1
    # 颜值触发的事件
    elif face < 4 and age >= 7:
        info += '你因为长的太丑, 别的小朋友不喜欢你, '
        if iq > 5:
            info += '你决定用学习填充自己'
            iq += 1
        else:
            if gender == 'Boy':
                info += '你和别的小朋友经常打架'
                iq -= 1
                strong += 1
            else:
                info += '你经常被别的小朋友欺负'
                strong -= 1
    # 智商触发的事件
    elif iq < 5:
        info += '你看起来傻傻的, '
        if home >= 8 and age >= 6:
            info += '你的父母给你送到更好的学校学习'
        elif 4 <= home <= 7:
            if gender == 'boy':
                info += '你的父母鼓励你多运动, 加强身体素质'
                strong += 1
            else:
                info += '你的父母鼓励你多打扮自己'
                face += 1
        else:
            info += '你的父母为此经常吵架'
            if point == 1:
                strong -= 1
            elif point == 2:
                iq -= 1
    # 健康成长
    else:
        info += '你健康成长, '
        if point == 1:
            info += '看起来更聪明了'
            iq += 1
        elif point == 2:
            info += '看起来更好看了'
            face += 1
        else:
            info += '看起来更结实了'
            strong += 1

    print('-------------------------------------------')
    print(info)
    print(f'strong={strong}, face={face}, iq={iq}, home={home}')
    time.sleep(1)
