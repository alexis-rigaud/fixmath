%  Copyright (C) 2005-2011, Axis Communications AB, LUND, SWEDEN
%  Copyright (C) 2024, Alexis Rigaud
%
%  SPDX-License-Identifier: LGPL-3.0-or-later
%  SPDX-License-Identifier: GFDL-1.3-or-later
%
%
% Remez' algorithm for function approximation.
%
% poly = remez(x, y, order, verbose)
%
%   x       An array of evenly distributed sample points of the function f.
%   y       An array of sampled function values.
%   order   The order of the polynom to approximate the function.
%   verbose Verbosity boolean. Supply a non-zero value to step
%           interactivly through the iterations and plot data.
%   poly    The computed approximation polygon coefficients.

function [poly, err] = remez(x, y, order, verbose)

    % Create the initial distribution of control points
    p = round(linspace(1, length(x), order + 2));

    % Initialize error variables
    err = 1;
    old = 0;

    while abs(err - old) > 1e-15
        % Save the old error
        old = err;

        % Compute the approximating polynomial from the control points
        [poly, eps] = solve(x(p), y(p));
        res = y - polyval(poly, x);

        % Find the extreme points on the residual curve
        ext = extrema(res);

        % Find the maximum absolute error
        [err, i] = max(abs(res(2:(end - 1))));
        i = i + 1;

        % Locate the closest extreme point
	[q, j] = min(abs(ext - i));

        % Move the corresponding control point
        p(j) = i;

        if verbose
            % Plot the data
            hold off
            plot(x, res)
            hold on
            plot(x(p), zeros(size(p)), 'ko')
            plot([x(1) x(end)],  [ eps  eps], 'g--')
            plot([x(1) x(end)],  [-eps -eps], 'g--')
            plot(x(i + 1), res(i + 1), 'r*')
            plot(x(p(j + 1)), 0, 'r*')
            xlabel('x')
            ylabel('error')
            printf('error=%e\n', err)
            pause
        end
    end


function pos = extrema(y)
    dy = diff(y);
    pos = find(xor(dy(1:(end - 1)) > 0, dy(2:end) > 0));
    pos = [1 pos length(y)];


function [poly, eps] = solve(xp, yp, mask)
    len = length(xp);
    sys = [];
    for k = 1:len
        row = [(-1)^k 1];

        for i = 1:(len - 2)
            row = [row xp(k)^i];
        end

        sys = [sys; row];
    end

    sol  = sys \ yp(:);
    eps  = abs(sol(1));
    poly = sol(end:-1:2);
