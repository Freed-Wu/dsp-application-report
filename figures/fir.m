%% input data
% two-column dat file will be import as a complex
data = csvread('data/reality.dat');
F = real(data);
x = imag(data)/max(imag(data));

%% coefficient generate
% if you use matlab, please comment this line
pkg load signal;
N = 48;
fs = 20e3;
f = [1:N/2]*fs/N;
h = fir1(N, [0.1, 0.2], 'bandpass');
% NOTE: due to precision, the coefficient maybe become different
hm = round(h*fix(32768/max(h)));
y = abs(fft(hm)(1:N/2));
y = y/max(y);
Y = interp1(f, y, F, 'spline');
for i = 1:length(Y)
    if isnan(Y(i)) || Y(i) < 0
        Y(i) = 0;
    end
end
plot(F, Y);
hold on;
plot(F, x);
err = abs(Y-x);
plot(F, err);
xlabel('$f$/Hz');
legend('therom', 'reality', 'error');
print -dpdflatexstandalone '/tmp/fir.tex';
