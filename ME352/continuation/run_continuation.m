function run_continuation(fname,N)

global globalsolution continuationfname

continuationfname=fname;

for k=1:N
    Xg=2*globalsolution(:,end)-globalsolution(:,end-1);
    Xg=newton('intermed',Xg);
    globalsolution=[globalsolution,Xg];
end

