%% input data
data = csvread('data/reality.csv');
% remove header
data(1, :) = [];
f = data(:, 1);
x = data(:, 2);
x /= max(x);
X = 20*log10(x);
fs = 20e3;

%% coefficients generate
% if you use matlab, please comment this line, because matlab has loaded
% this package when it startups. i load this package only when i need fir1()
% in order to save startup time.
pkg load signal;
N = 48;
h = fir1(N, [0.1, 0.2], 'bandpass');
% NOTE: due to precision, the coefficients maybe become different
hm = round(h*fix(32767/max(h)));
% output coefficients
csvwrite('tables/fir.csv', [0:N; hm]');
% remember to add header for the table
% 次数,系数

%% plot amplitude frequency curve
smaple_number = 512;
[H, W] = freqz(hm, 1, smaple_number, [], fs);
% modify freqz_plot()
mag = 20 * log10 (abs (H));
mag -= max(mag);
phase = unwrap (arg (H));
plot (W, mag);
hold on;
plot(f, X);
xlabel('$f$/Hz');
ylabel('$20 \lg A$/dB')
legend('theorem', 'reality');
print -dpdflatexstandalone '/tmp/fir.tex';
