function diag(A)
V=eig(A);
s=0;
for i=1:length(V)
    if abs(imag(V(i)))<1e-15
        s=s+1;
    end
end
fprintf('Matrisen A har %d reella egenvärden',s)