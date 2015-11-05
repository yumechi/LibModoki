import os
import time
import random

# 想定される答えを出せるスクリプトを描く
# 引数とかも適宜調整する
# 例：[1, N]の範囲の3または5の倍数の数を答えにした時 (範囲：1<=N<=10*9)
def ansfunc(N):
    return N // 3 + N // 5 - N // 15

def writefiles(dirpath, filename, num):
    filepath = dirpath + "/" + filename
    filewriter = open(filepath, "w")
    filewriter.write(str(num) + "\n")
    filewriter.close()

def createData(number):
    # フォルダ名の設定  ここでは現在時間とした
    rootdir = str(int(time.time()))
    inputdirpath = rootdir + "/input"
    outputdirpath = rootdir + "/output"
    os.makedirs(inputdirpath)
    os.makedirs(outputdirpath)

    for i in range(1, number+1):
        # 入力可能な変数の範囲に合わせて適当に変数を決める
        questionN = int(random.randint(1, 10 ** 9 + 1) // abs(i - number - 1)) // abs(i - number - 1)
        answer = ansfunc(questionN if questionN > 1 else 1)

        inputfilename = "input" + str(i) + ".txt"
        writefiles(inputdirpath, inputfilename, questionN)

        outputfilename = "output" + str(i) + ".txt"
        writefiles(outputdirpath, outputfilename, answer)

def run():
    # 引数に作りたいテストケース数を渡す
    createData(20)

if __name__ == "__main__":
    print("start!")
    run()
    print("end!")
