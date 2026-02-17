clc; clear; close all;

% Example sensor data: trash height (IoT system)
x = [6 6 6 6 6 8 8 8 0 0 0 2 3 2 3 3 2 4 3 3 3 3 3 3 3 0 3 3 12 12 12 12 12 12 12];

% Normalize
x_norm = (x - min(x)) / (max(x) - min(x));

% Derivative (rate of change)
dx = [0 diff(x_norm)];

% Complex representation
S = x_norm + 1j * dx;

% Visualization
figure('Name','QAM-Inspired Representation','NumberTitle','off');
subplot(3,1,1); plot(x_norm,'b','LineWidth',1.5); grid on;
title('Normalized Sensor Data'); ylabel('x_{norm}(t)');
subplot(3,1,2); plot(dx,'r','LineWidth',1.5); grid on;
title('Derivative (Rate of Change)'); ylabel('dx/dt');
subplot(3,1,3); plot(real(S),imag(S),'-o','LineWidth',1.5); grid on;
title('QAM-Inspired Complex Trajectory');
xlabel('Normalized Value (I)'); ylabel('Rate of Change (Q)');
axis equal;

% Magnitude and phase
figure('Name','Magnitude and Phase','NumberTitle','off');
subplot(2,1,1); plot(abs(S),'LineWidth',1.5);
title('Magnitude |S(t)|'); grid on;
subplot(2,1,2); plot(angle(S),'LineWidth',1.5);
title('Phase ∠S(t)'); ylabel('radians'); xlabel('Sample Index'); grid on;

% Quantitative metrics
trajectory_length = sum(abs(diff(S)));
avg_phase = mean(angle(S));
stability_index = std(angle(S));
activity_index = mean(abs(dx));
event_count = sum(abs(dx) > 0.1);

fprintf('\n--- Dynamic Metrics from QAM-Inspired Representation ---\n');
fprintf('Trajectory Length : %.4f\n', trajectory_length);
fprintf('Average Phase Direction : %.4f radians\n', avg_phase);
fprintf('Stability Index (σθ) : %.4f\n', stability_index);
fprintf('Activity Index (|dx|avg) : %.4f\n', activity_index);
fprintf('Event Count (>|0.1|) : %d\n', event_count);
