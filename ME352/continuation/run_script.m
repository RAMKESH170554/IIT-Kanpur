% circle continuation example
close all
clear all
clc

global gp globalsolution

gp=0; newton('circplt',[0;2])
globalsolution=[ans;gp];

gp=0.02; newton('circplt',[0;2])
globalsolution=[globalsolution,[ans;gp]]


run_continuation('circplt',560)
%globalsolution
plot(globalsolution(1,:),globalsolution(2,:)); axis('image')
 