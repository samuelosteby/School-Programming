function powerm = power_method(A)
i = 1;
B = A ^ i;
C = A ^ (i + 1);
while isequal(B,C) == 0
    i = i + 1;
    B = A ^ i;
    C = A ^ (i + 1);
end
B
i
end