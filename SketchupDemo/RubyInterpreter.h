#pragma once
#include<ruby.h>
#include<string>
#include<vector>

class RubyResult {
public:
	RubyResult(int state, VALUE err_info);
	~RubyResult();

	std::string ToString();
	std::string GetErrorMsg();
	std::vector<std::string> GetErrorBacktrace();

	int m_state;
private:
	VALUE m_err_info_or_result;
};

class RubyRecord {
public:
	std::string m_eval_str;
	RubyResult m_eval_res;
};

class RubyInterpreter
{
public:
	RubyInterpreter();
	~RubyInterpreter();

	RubyResult EvalString(std::string ruby_str);
private:
	std::vector<RubyRecord> m_eval_res;
	std::vector<std::string> m_history_strs;
};