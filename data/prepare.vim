let s:sine = readfile('code/LAB9/sine.dat')
call writefile(filter(map(s:sine[1:], {k, v -> join([k, str2nr(v, 16) < 32768 ? str2nr(v, 16) : str2nr(v, 16) - 65536])}), {k, v -> k < 128}), 'data/sine.dat')
call writefile(filter(map(s:sine[1:], {k, v -> join([k, -4 * (str2nr(v, 16) < 32768 ? str2nr(v, 16) : str2nr(v, 16) - 65536)])}), {k, v -> k < 128}), 'data/gain.dat')
