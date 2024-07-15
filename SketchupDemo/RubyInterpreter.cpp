#include "RubyInterpreter.h"



RubyInterpreter::RubyInterpreter()
{
	// 初始化 Ruby 解释器
	//ruby_init();
	// 加载 Ruby 标准库
	//ruby_script("embedded_ruby");
}

RubyInterpreter::~RubyInterpreter()
{
	// 清理 Ruby 解释器
	//ruby_cleanup(0);
}

RubyResult RubyInterpreter::EvalString(std::string ruby_str)
{
	int state;
	VALUE res = rb_eval_string_protect(ruby_str.c_str(),&state);
	if (state) {
		return RubyResult(state, res);
	}
	else {
		return RubyResult(state, rb_errinfo());
	}

}

RubyResult::RubyResult(int state, VALUE err_info_or_result)
	: m_state(state),m_err_info_or_result(err_info_or_result)
{
}

RubyResult::~RubyResult()
{
}

std::string RubyResult::ToString()
{
	if (m_state) {

		VALUE str = rb_inspect(m_err_info_or_result);
		return std::string(StringValueCStr(str));
	}
	else {
		VALUE error_type = rb_type(m_err_info_or_result);
		std::string res = "Error: #<";
		res.append(rb_class2name(error_type));
		res.append(":")
			.append(GetErrorMsg())
			.append("\n");
		for(std::string backtrace : GetErrorBacktrace())
			res.append(backtrace).append("\n");
		return res;
	}
}

std::string RubyResult::GetErrorMsg()
{
	if (m_state) return std::string();
	VALUE err_msg = rb_funcall(m_err_info_or_result, rb_intern("message"), 0);
	return std::string(StringValueCStr(err_msg));
}

std::vector<std::string> RubyResult::GetErrorBacktrace()
{
	std::vector<std::string> backtraces;
	if (m_state) backtraces;
	VALUE err_backtrace = rb_funcall(m_err_info_or_result, rb_intern("backtrace"), 0);
	if (RB_TYPE_P(err_backtrace, T_ARRAY)) {
		for (int i = 0; i < rb_array_len(err_backtrace); i++) {
			VALUE entry = rb_ary_entry(err_backtrace, i);
			backtraces.push_back(StringValueCStr(entry));
		}
	}
	return backtraces;
}
