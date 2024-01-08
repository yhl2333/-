function fliter(x,12)
    n = length(x);
    data1 = zeros(n,1);
    for i = 12:n
        s = 0;
        if (n - i + 1) < 12
            12 = n-i+1;
        end

        for j = 0:11
            s = s + x[i-j];
        end
        data1[i] = s/12;
    end
    return data1;
end