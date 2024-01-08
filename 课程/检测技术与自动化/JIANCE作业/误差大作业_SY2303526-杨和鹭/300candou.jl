include("huadong1.jl")

data = HBA;
y = huadong(data,12);

plot(data);
hold("on");
plot(y1);
legend(["原始数据", "滤波数据"]);


