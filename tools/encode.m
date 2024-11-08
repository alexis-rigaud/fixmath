%  Copyright (C) 2005-2011, Axis Communications AB, LUND, SWEDEN
%  Copyright (C) 2024, Alexis Rigaud
%
%  SPDX-License-Identifier: LGPL-3.0-or-later
%  SPDX-License-Identifier: GFDL-1.3-or-later
%
%
% Encode polynomial coefficients in mantissa and exponent format.
%
% encode(poly)
%
%   poly  Polynomial coefficients obtained e.g. output from Remez' algorithm
%

function encode(vals)
     logv = log2(abs(vals));
     expn = floor(logv);
     logm = logv - expn;
     mant = 2 .^ logm;

     printf('\n        value       factor  sh\n')
     printf('-------------------------------\n')

     for k = 1:length(vals)

         printf('% e  ', vals(k))

         if vals(k) < 0
             printf('-')
         else
	     printf(' ')
         end

         m32 = round((2^31)*mant(k));

         printf('%#x%x  %d\n', m32 / 16, rem(m32, 16), 31 - expn(k))
     end

     printf('\n')
