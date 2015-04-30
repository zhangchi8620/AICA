clc;
clear all;

A  = textread('output.csv','%s');
b = cell2mat(A(end));
b = str2num(b);
for i = 0: b
	image=imread(strcat(int2str(i),'.pgm'));
	imwrite(image,strcat(int2str(i),'.jpg'));
    disp(strcat(int2str(i),':Start batch converting.'));
end
disp('End of convertion.');

htmlfile = fopen('display.html', 'w');
fprintf(htmlfile,'%s', '<html>');

for i = 0:b
	str = ['<img src="' num2str(i) '.jpg" height=200 width=200 border=1>']; 
	fprintf(htmlfile, '%s\n', str);
end
fprintf(htmlfile,'%s', '</html>');
fclose(htmlfile);
