function varargout = ComAssignment1(varargin)
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ComAssignment1_OpeningFcn, ...
                   'gui_OutputFcn',  @ComAssignment1_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
function ComAssignment1_OpeningFcn(hObject, ~, handles, varargin)
handles.output = hObject;
guidata(hObject, handles);
function varargout = ComAssignment1_OutputFcn(~, ~, handles) 
varargout{1} = handles.output;
function equation_CreateFcn(hObject, ~, ~)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
function xlower_CreateFcn(hObject, ~, ~)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
function xupper_CreateFcn(hObject, ~, ~)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
function startvalue_CreateFcn(hObject, ~, ~)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
function maxiters_CreateFcn(hObject, ~, ~)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
function maxerror_CreateFcn(hObject, ~, ~)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
function edit8_CreateFcn(hObject, ~, ~)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
function equation_Callback(~, ~, ~)
function xlower_Callback(~, ~, ~)
function xupper_Callback(~, ~, ~)
function startvalue_Callback(~, ~, ~)
function maxiters_Callback(~, ~, ~)
function maxerror_Callback(~, ~, ~)

function submit_Callback(~, ~, handles)
clc;
format long;

switch get(get(handles.methodgroup, 'SelectedObject'), 'Tag')
      case 'method1'
          bisection(handles);
      case 'method2'
          falseposition(handles);
      case 'method3'
          modfalseposition(handles);
      case 'method4'
          newtonraphson(handles);
      case 'method5'
          secant(handles);
end

set(handles.methodgroup, 'Visible', 'off');
set(handles.methodvalues, 'Visible', 'off');
set(handles.equationpanel, 'Visible', 'off');
set(handles.submit, 'Visible', 'off');
set(handles.axes1, 'Visible', 'on');
set(handles.axes2, 'Visible', 'on');

function back_Callback(~, ~, handles)
set(handles.methodgroup, 'Visible', 'on');
set(handles.methodvalues, 'Visible', 'on');
set(handles.equationpanel, 'Visible', 'on');
set(handles.submit, 'Visible', 'on');
set(handles.axes1, 'Visible', 'off');
set(handles.axes2, 'Visible', 'off');

% Bisection Method

function bisection(handles)
l = eval(get(handles.xlower, 'string'));
u = eval(get(handles.xupper, 'string'));
maxiters = eval(get(handles.maxiters, 'string'));
maxerror = eval(get(handles.maxerror, 'string'));

syms f(x)
f(x) = sym(get(handles.equation, 'string'));

axes(handles.axes1);
ezplot(f, [l u]), grid;

x = l;
errors = [];
clc

for n = 1:maxiters
    x0 = x;
    x = (l+u)/2;
    y = eval(f(x));

    fl = eval(f(l));
    
    e = (x - x0)/x*100;
    errors = [errors e];
    
    if y*fl == 0
        break
    elseif y*fl > 0
        l = x;
    else
        u = x;
    end
    
    if (abs(e) < maxerror || y == 0)
        break;
    end
end

axes(handles.axes2);
plot(errors), grid;

set(handles.solution, 'String', x);

% False-Position Method

function falseposition(handles)
x0 = eval(get(handles.xlower, 'string'));
u = eval(get(handles.xupper, 'string'));
maxiters = eval(get(handles.maxiters, 'string'));
maxerror = eval(get(handles.maxerror, 'string'));

syms f(x)
f(x) = sym(get(handles.equation, 'string'));

fu = eval(f(u));
y = eval(f(x0));

axes(handles.axes1);
ezplot(f, [x0 u]), grid;
errors = [];
clc

for n = 1:maxiters
    x = u - fu * (u - x0) / (fu - y);
    y = eval(f(x));
    
    e = (x - x0)/x*100;
    errors = [errors e];
    
    if (abs(e) < maxerror || y == 0)
        break;
    end
    x0 = x;
end

axes(handles.axes2);
plot(errors), grid;

set(handles.solution, 'String', x);

% Modified-False Position Method

function modfalseposition(handles)
x0 = eval(get(handles.xlower, 'string'));
u = eval(get(handles.xupper, 'string'));
maxiters = eval(get(handles.maxiters, 'string'));
maxerror = eval(get(handles.maxerror, 'string'));

syms f(x)
f(x) = sym(get(handles.equation, 'string'));

fu = eval(f(u));
y = eval(f(x0));

axes(handles.axes1);
ezplot(f, [x0 u]), grid;
errors = [];
c = 0;
clc

for n = 1:maxiters
    x = u - fu * (u - x0) / (fu - y);
    y = eval(f(x));
    
    e = (x - x0)/x*100;
    errors = [errors e];
    
    if (abs(e) < maxerror || y == 0)
        break;
    end
    x0 = x;
    
    if (c == 2)
        c = 0;
        fu = fu / 2;
    else
        c = c + 1;
    end
end

axes(handles.axes2);
plot(errors), grid;

set(handles.solution, 'String', x);

% Newton-Raphson Method

function newtonraphson(handles)
maxiters = eval(get(handles.maxiters, 'string'));
maxerror = eval(get(handles.maxerror, 'string'));

syms f(x)
f(x) = sym(get(handles.equation, 'string'));
f1(x) = diff(f);

x0 = eval(get(handles.startvalue, 'string'));
x = x0;
y = eval(f(x0));

axes(handles.axes1);
ezplot(f, [x0-0.5 x0+0.5]), grid;
errors = [];
clc

for n = 1:maxiters
    x = x - y/eval(f1(x));
    y = eval(f(x));
    
    e = (x - x0)/x*100;
    errors = [errors e];
    
    if (abs(e) < maxerror || y == 0)
        break;
    end
    x0 = x;
end

axes(handles.axes2);
plot(errors), grid;

set(handles.solution, 'String', x);

% Secant Method

function secant(handles)
maxiters = eval(get(handles.maxiters, 'string'));
maxerror = eval(get(handles.maxerror, 'string'));

syms f(x)
f(x) = sym(get(handles.equation, 'string'));

x0 = eval(get(handles.xlower, 'string'));
x = eval(get(handles.xupper, 'string'));
y0 = eval(f(x0));
y = eval(f(x));

axes(handles.axes1);
ezplot(f, [x0 x]), grid;
errors = [];
clc

for n = 1:maxiters
    t = x;
    x = x-y*(x-x0)/(y-y0);
    x0 = t;
    y0 = y;
    y = eval(f(x));
    
    e = (x - x0)/x*100;
    errors = [errors e];
    
    if (abs(e) < maxerror || y == 0)
        break;
    end
end

axes(handles.axes2);
plot(errors(2:length(errors))), grid;

set(handles.solution, 'String', x);