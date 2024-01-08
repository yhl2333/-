clc
clear()


fid=fopen("candou.txt");

n=8238;

for i=1:n
    a{i}=fgetl(fid);


end

fclose(fid);