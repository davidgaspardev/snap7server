#ifndef LOGS_H_
#define LOGS_H_

void log_breakline();

void logging_info(const char *msg, ...);
void log_info(const char *msg, ...);
void logging_ok(const char *msg, ...);
void log_ok(const char *msg, ...);
void logging_err(const char *msg, ...);
void log_err(const char *msg, ...);

#endif