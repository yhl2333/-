# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
import matplotlib.pyplot as plt
from queue import Queue
import numpy as np
from keras.models import Sequential
from keras.layers import Dense
from sklearn.preprocessing import MinMaxScaler
from scipy import signal



QUEUESIZE = 12
data = []
filter_data = []
data_error = []
data_butter = []

def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.


def openreadtxt(file_name):
    file = open(file_name, 'r')
    file_data = file.readlines()
    for row in file_data:
        tmp_list = row.split(' ')
        tmp_list[-1] = tmp_list[-1].replace('\n','')
        decimal = int(tmp_list[0], 16)

        if decimal & 0x8000:
            decimal=-((decimal^0xFFFF)+1)
        data.append(decimal)

    return data

def drawpicture(data):
    x = list(range(len(data)))

    # 创建一个新的图表
    plt.figure(figsize=(40, 12))

    # 绘制折线图
    plt.plot(x, data, marker='.', linestyle='-')

    # 添加标题和标签
    plt.title('折线图示例', fontproperties='Microsoft YaHei')
    plt.xlabel('数据点索引', fontproperties='Microsoft YaHei')
    plt.ylabel('数值', fontproperties='Microsoft YaHei')
    # 显示图表
    plt.show()


def draw_dif_pic(data,filter_data):
    x=list(range(len(data)))
    y=list(range(len(filter_data)))

    plt.figure(figsize=(40, 12))

    plt.plot(x,data, marker='.', linestyle='-', color='red',label='Data')
    plt.plot(y,filter_data,marker='.',linestyle='-', color='blue',label='filt_Data')

    # 添加标题和标签
    plt.title('折线图示例', fontproperties='Microsoft YaHei')
    plt.xlabel('数据点索引', fontproperties='Microsoft YaHei')
    plt.ylabel('数值', fontproperties='Microsoft YaHei')

    plt.legend()

    # 显示图表
    plt.show()

def filter(data):
    queue = Queue()

    for weight_data in data:
        if queue.qsize()<QUEUESIZE:
            queue.put(weight_data)
            filter_data.append((weight_data))
        else:
            total_sum = 0
            queue.put(weight_data)
            queue.get()
            queue_list = list(queue.queue)
            for item in queue_list:
                total_sum += item
            filter_data.append(total_sum/QUEUESIZE)

# def butter_wolf(data):
#     data_butter = np.array(data)
#     sos = signal.butter(6, 3, 'hp', fs=60, output='sos')
#     filtered_data = signal.sosfilt(sos, data_butter)
#     plt.figure()
#     plt.plot(data, label='Original Data')
#     plt.plot(filtered_data, label='Filtered Data')
#     plt.xlabel('Sample')
#     plt.ylabel('Value')
#     plt.title('Butterworth High Pass Filter Example for Data')
#     plt.legend()
#     plt.show()


def exp_filter(filter_data):

    for i in range(len(filter_data)):
        if max(filter_data[i:i+40])>300:
            data_error.append((0.1*filter_data[i]+0.1*filter_data[i+10]+0.1*filter_data[i+15]+0.1*filter_data[i+26]+0.1*filter_data[i+35]+0.5*filter_data[i+39])/3000)
        else:
            data_error.append(0)

if __name__ == "__main__":

    #读入数据，将补码转化为数字，绘图
    data = openreadtxt('candou4.txt')
    #drawpicture(data)

    #数据做巴特沃斯高通滤波
    # butter_wolf(data)
    #数据做滑动平均低通滤波
    filter(data)

    draw_dif_pic(data,filter_data)
    exp_filter(filter_data)
    # drawpicture(data_error)
    #给定网络的训练样本和标签
    X_train = []
    for i in range(int(len(filter_data)/2-(len(filter_data)/2)%5)):
        X_train.append((filter_data[i:i+5]))
    scaler = MinMaxScaler()
    X_normalized = scaler.fit_transform(X_train)


    Y_train = data_error[0:int(len(filter_data)/2-(len(filter_data)/2)%5)]

    X_test = []
    for i in range(int(len(filter_data)/2+(len(filter_data)/2)%5),int(len(filter_data)-(len(filter_data))%5)):
        X_test.append((filter_data[i:i+5]))
    X_test_normalized = scaler.fit_transform(X_test)

    # 创建一个Sequential模型
    model = Sequential()

    # 添加输入层和第一个隐藏层
    model.add(Dense(units=128, input_dim=5, activation='sigmoid'))

    # 添加第二个隐藏层
    model.add(Dense(units=64, activation='sigmoid'))

    # 添加输出层
    model.add(Dense(units=1))

    # 编译模型
    model.compile(loss='mean_squared_error', optimizer='adam', metrics=['accuracy'])

    # 输入数据集
    X = np.array(X_normalized)
    # 期望输出数据集
    y = np.array(Y_train)

    X1 = np.array((X_test_normalized))
    # 训练模型
    model.fit(X, y, epochs=220, verbose=0)


    # 测试模型
    predictions = model.predict(X1)

    draw_dif_pic(3000*predictions,data[int(len(filter_data)/2+(len(filter_data)/2)%5):int(len(filter_data)-(len(filter_data))%5)])







# See PyCharm help at https://www.jetbrains.com/help/pycharm/
