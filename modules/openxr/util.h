/*************************************************************************/
/*  util.h                                                               */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef UTIL_H
#define UTIL_H

#define UNPACK(...) __VA_ARGS__

#define INIT_XR_FUNC_V(openxr_api, name)                                                                              \
	do {                                                                                                              \
		XrResult get_instance_proc_addr_result;                                                                       \
		get_instance_proc_addr_result = openxr_api->get_instance_proc_addr(#name, (PFN_xrVoidFunction *)&name##_ptr); \
		ERR_FAIL_COND_V(XR_FAILED(get_instance_proc_addr_result), false);                                             \
	} while (0)

#define EXT_INIT_XR_FUNC_V(name) INIT_XR_FUNC_V(openxr_api, name)
#define OPENXR_API_INIT_XR_FUNC_V(name) INIT_XR_FUNC_V(this, name)

#define INIT_XR_FUNC(openxr_api, name)                                                                                \
	do {                                                                                                              \
		XrResult get_instance_proc_addr_result;                                                                       \
		get_instance_proc_addr_result = openxr_api->get_instance_proc_addr(#name, (PFN_xrVoidFunction *)&name##_ptr); \
		ERR_FAIL_COND(XR_FAILED(get_instance_proc_addr_result));                                                      \
	} while (0)

#define EXT_INIT_XR_FUNC(name) INIT_XR_FUNC(openxr_api, name)
#define OPENXR_API_INIT_XR_FUNC(name) INIT_XR_FUNC(this, name)

#define EXT_PROTO_XRRESULT_FUNC1(func_name, arg1_type, arg1)                \
	PFN_##func_name func_name##_ptr = nullptr;                              \
	XRAPI_ATTR XrResult XRAPI_CALL func_name(UNPACK arg1_type arg1) const { \
		if (!func_name##_ptr) {                                             \
			return XR_ERROR_HANDLE_INVALID;                                 \
		}                                                                   \
		return (*func_name##_ptr)(arg1);                                    \
	}

#define EXT_PROTO_XRRESULT_FUNC2(func_name, arg1_type, arg1, arg2_type, arg2)                      \
	PFN_##func_name func_name##_ptr = nullptr;                                                     \
	XRAPI_ATTR XrResult XRAPI_CALL func_name(UNPACK arg1_type arg1, UNPACK arg2_type arg2) const { \
		if (!func_name##_ptr) {                                                                    \
			return XR_ERROR_HANDLE_INVALID;                                                        \
		}                                                                                          \
		return (*func_name##_ptr)(arg1, arg2);                                                     \
	}

#define EXT_PROTO_XRRESULT_FUNC3(func_name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3)                            \
	PFN_##func_name func_name##_ptr = nullptr;                                                                            \
	XRAPI_ATTR XrResult XRAPI_CALL func_name(UNPACK arg1_type arg1, UNPACK arg2_type arg2, UNPACK arg3_type arg3) const { \
		if (!func_name##_ptr) {                                                                                           \
			return XR_ERROR_HANDLE_INVALID;                                                                               \
		}                                                                                                                 \
		return (*func_name##_ptr)(arg1, arg2, arg3);                                                                      \
	}

#define EXT_PROTO_XRRESULT_FUNC4(func_name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4)                                  \
	PFN_##func_name func_name##_ptr = nullptr;                                                                                                   \
	XRAPI_ATTR XrResult XRAPI_CALL func_name(UNPACK arg1_type arg1, UNPACK arg2_type arg2, UNPACK arg3_type arg3, UNPACK arg4_type arg4) const { \
		if (!func_name##_ptr) {                                                                                                                  \
			return XR_ERROR_HANDLE_INVALID;                                                                                                      \
		}                                                                                                                                        \
		return (*func_name##_ptr)(arg1, arg2, arg3, arg4);                                                                                       \
	}

#define EXT_PROTO_XRRESULT_FUNC5(func_name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4, arg5_type, arg5)                                        \
	PFN_##func_name func_name##_ptr = nullptr;                                                                                                                          \
	XRAPI_ATTR XrResult XRAPI_CALL func_name(UNPACK arg1_type arg1, UNPACK arg2_type arg2, UNPACK arg3_type arg3, UNPACK arg4_type arg4, UNPACK arg5_type arg5) const { \
		if (!func_name##_ptr) {                                                                                                                                         \
			return XR_ERROR_HANDLE_INVALID;                                                                                                                             \
		}                                                                                                                                                               \
		return (*func_name##_ptr)(arg1, arg2, arg3, arg4, arg5);                                                                                                        \
	}

#define EXT_PROTO_XRRESULT_FUNC6(func_name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4, arg5_type, arg5, arg6_type, arg6)                                              \
	PFN_##func_name func_name##_ptr = nullptr;                                                                                                                                                 \
	XRAPI_ATTR XrResult XRAPI_CALL func_name(UNPACK arg1_type arg1, UNPACK arg2_type arg2, UNPACK arg3_type arg3, UNPACK arg4_type arg4, UNPACK arg5_type arg5, UNPACK arg6_type arg6) const { \
		if (!func_name##_ptr) {                                                                                                                                                                \
			return XR_ERROR_HANDLE_INVALID;                                                                                                                                                    \
		}                                                                                                                                                                                      \
		return (*func_name##_ptr)(arg1, arg2, arg3, arg4, arg5, arg6);                                                                                                                         \
	}

#endif // UTIL_H
