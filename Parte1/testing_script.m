fprintf('Testing script\n\n');

fprintf('div_t(%d)=%.8f\n', 5, div_t(5));
fprintf('div_t(%d)=%.8f\n', 10, div_t(10));
#fprintf('div_t(0)=\n');
#fprintf(div_t(0));

fprintf('\nsin_t(%d)=%.8f\n', pi, sin_t(pi));
fprintf('sin_t(%d)=%.8f\n', pi/2, sin_t(pi/2));

fprintf('\ntan_t(%d)=%.8f\n', pi, tan_t(pi));
fprintf('tan_t(%d)=%.8f\n', 2, tan_t(2));
#fprintf('tan_t(pi/2)=\n');
#fprintf(tan_t(pi/2));

fprintf('\nlog_t(%d, %d)=%.8f\n', 2, 8, log_t(2,8));
fprintf('log_t(%d, %d)=%.8f\n', 1, 10, log_t(1,10));

#fprintf('log_t(10,0)=\n');
#fprintf(log_t(10,0));

#fprintf('log_t(0,10)=\n');
#fprintf(log_t(0,10));

fprintf('\nsinh_t(%d)=%.8f\n', pi, sinh_t(pi));
fprintf('sinh_t(%d)=%.8f\n', pi/2, sinh_t(pi/2));

fprintf('\ntanh_t(%d)=%.8f\n', 0.3, tanh_t(0.3));
fprintf('tanh_t(%d)=%.8f\n', 5, tanh_t(5));
fprintf('tanh_t(%d)=%.8f\n', -15, tanh_t(-15));

fprintf('\nroot_t(%d, %d)=%.8f\n', 16, 2, root_t(16,2));
fprintf('root_t(%d, %d)=%.8f\n', 3, 2, root_t(3,2));
fprintf('root_t(%d, %d)=%.8f\n', 3, 5, root_t(3,5));
#fprintf('root_t(-1,2)=\n');
#fprintf(root_t(-1,2));

fprintf('\natan_t(%d)=%.8f\n', 0.5, atan_t(0.5));
fprintf('atan_t(%d)=%.8f\n', -0.5, atan_t(-0.5));
#fprintf('atan_t(-2)=\n');
#fprintf(atan_t(-2));



