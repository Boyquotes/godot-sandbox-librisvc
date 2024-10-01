#include "sandbox.h"

#include <unordered_set>

using namespace godot;
static const std::unordered_set<std::string_view> exclude_functions{
	/* C and C++ runtime functions */
	"main",
	"_Exit",
	"_dlerror_run",
	"_dlfo_process_initial",
	"_dlfo_sort_mappings",
	"_dlfo_sort_mappings.part.0",
	"_exit",
	"_fitoa_word",
	"_flushlbf",
	"_itoa_word",
	"_pthread_cleanup_pop",
	"_pthread_cleanup_push",
	"_setjmp",
	"_start",
	"_Fork",
	"_int_free",
	"_int_free_create_chunk",
	"_int_free_maybe_consolidate.part.0",
	"_int_free_merge_chunk",
	"_int_malloc",
	"_int_memalign",
	"_int_realloc",
	"_longjmp",
	"_longjmp_unwind",
	"_mid_memalign.isra.0",
	"_res_hconf_init",
	"_res_hconf_reorder_addrs",
	"_res_hconf_trim_domain",
	"_res_hconf_trim_domains",
	"btree_node_update_separator_after_split",
	"frame_downheap",
	"version_lock_lock_exclusive",
	"read_encoded_value_with_base",
	"fde_unencoded_extract",
	"fde_radixsort",
	"fde_unencoded_compare",
	"version_lock_unlock_exclusive",
	"btree_allocate_node",
	"btree_handle_root_split.part.0",
	"btree_insert.isra.0",
	"btree_release_tree_recursively",
	"btree_destroy",
	"get_cie_encoding",
	"btree_remove",
	"fde_mixed_encoding_extract",
	"classify_object_over_fdes",
	"get_pc_range",
	"fde_single_encoding_extract",
	"fde_single_encoding_compare",
	"fde_mixed_encoding_compare",
	"add_fdes.isra.0",
	"linear_search_fdes",
	"release_registered_frames",
	"deregister_tm_clones",
	"register_tm_clones",
	"frame_dummy",
	"d_make_comp",
	"d_number",
	"d_call_offset",
	"d_discriminator",
	"d_count_templates_scopes",
	"d_pack_length",
	"d_index_template_argument.part.0",
	"d_growable_string_callback_adapter",
	"next_is_type_qual.isra.0",
	"d_append_char",
	"d_lookup_template_argument",
	"d_find_pack",
	"d_append_string",
	"d_template_param",
	"d_append_num",
	"d_print_lambda_parm_name",
	"d_source_name",
	"d_substitution",
	"d_maybe_module_name",
	"d_type",
	"d_cv_qualifiers",
	"d_function_type",
	"d_name",
	"d_expression_1",
	"d_template_args_1",
	"d_parmlist",
	"d_bare_function_type",
	"d_template_parm",
	"d_template_head",
	"d_operator_name",
	"d_unqualified_name",
	"d_exprlist",
	"d_prefix",
	"d_expr_primary",
	"d_special_name",
	"d_encoding.part.0",
	"d_template_arg",
	"d_print_comp_inner",
	"d_print_comp",
	"d_print_mod",
	"d_print_array_type",
	"d_print_expr_op",
	"d_print_subexpr",
	"d_maybe_print_fold_expression",
	"d_maybe_print_designated_init",
	"d_print_function_type",
	"d_print_mod_list",
	"d_demangle_callback.constprop.0",
	"init_dwarf_reg_size_table",
	"uw_install_context_1",
	"read_encoded_value",
	"execute_stack_op",
	"uw_update_context_1",
	"execute_cfa_program_specialized",
	"execute_cfa_program_generic",
	"uw_frame_state_for",
	"uw_init_context_1",
	"call_fini",
	"check_one_fd",
	"new_do_write",
	"mmap_remap_check",
	"decide_maybe_mmap",
	"flush_cleanup",
	"save_for_backup",
	"enlarge_userbuf",
	"malloc_printerr",
	"int_mallinfo",
	"alloc_perturb",
	"munmap_chunk",
	"detach_arena.part.0",
	"unlink_chunk.isra.0",
	"malloc_consolidate",
	"ptmalloc_init.part.0",
	"alloc_new_heap",
	"new_heap",
	"arena_get2",
	"arena_get_retry",
	"sysmalloc_mmap_fallback.constprop.0",
	"sysmalloc_mmap.isra.0",
	"systrim.constprop.0",
	"sysmalloc",
	"tcache_init.part.0",
	"two_way_long_needle",
	"next_line",
	"read_sysfs_file",
	"get_nproc_stat",
	"do_tunable_update_val",
	"tunable_initialize",
	"parse_tunables",
	"elf_machine_matches_host",
	"free_derivation",
	"free_modules_db",
	"derivation_compare",
	"find_derivation",
	"insert_module",
	"add_module",
	"add_alias2.part.0",
	"read_conf_file.isra.0",
	"find_module_idx",
	"find_module.constprop.0",
	"known_compare",
	"do_release_shlib",
	"do_release_all",
	"new_composite_name",
	"free_category",
	"plural_eval",
	"transcmp",
	"alias_compare",
	"read_alias_file",
	"do_swap",
	"msort_with_tmp.part.0",
	"indirect_msort_with_tmp",
	"read_int",
	"outstring_converted_wide_string",
	"group_number",
	"printf_positional",
	"read_int",
	"save_for_wbackup",
	"adjust_wide_data",
	"clear_once_control",
	"opendir_tail",
	"trecurse",
	"trecurse_r",
	"tdestroy_recurse",
	"maybe_split_for_insert.isra.0",
	"fatal_error",
	"length_mismatch",
	"is_dst",
	"is_trusted_path_normalize",
	"add_path.constprop.0.isra.0",
	"add_name_to_object.isra.0",
	"open_verify.constprop.0",
	"open_path.isra.0",
	"elf_machine_matches_host",
	"expand_dynamic_string_token",
	"fillin_rpath.isra.0",
	"decompose_rpath",
	"check_match",
	"do_lookup_x",
	"elf_machine_matches_host",
	"elf_machine_matches_host",
	"search_cache",
	"do_dlopen",
	"dlerror_run",
	"do_dlsym_private",
	"do_dlsym",
	"do_dlvsym",
	"do_dlclose",
	"free_slotinfo",
	"gconv_parse_code",
	"hack_digit",
	"two_way_long_needle",
	"remove_slotinfo",
	"call_dl_init",
	"add_to_global_update",
	"dl_open_worker",
	"dl_open_worker_begin",
	"add_to_global_resize_failure.isra.0",
	"add_to_global_resize",
	"elf_machine_matches_host",
	"dfs_traversal.part.0",
	"dlinfo_doit",
	"dlmopen_doit",
	"dlopen_doit",
	"dlsym_doit",
	"dlvsym_doit",
	"openaux",
	"call_init",
	"check_match",
	"call_dl_lookup",
	"do_sym",
	"base_of_encoded_value",
	"read_encoded_value_with_base",
	"stpcpy",
	"tsearch",
	"clock_gettime",
	"secure_getenv",
	"strcpy",
	"unsetenv",
	"gsignal",
	"bcmp",
	"setjmp",
	"getrlimit",
	"ioctl",
	"dlerror",
	"fstatat",
	"strtok_r",
	"dlinfo",
	"sysconf",
	"vsprintf",
	"getdtablesize",
	"fdopendir",
	"strtoull_l",
	"pthread_rwlock_rdlock",
	"memrchr",
	"strndup",
	"argz_add_sep",
	"stat64",
	"memmove",
	"pthread_rwlock_init",
	"getauxval",
	"snprintf",
	"munmap",
	"sched_getparam",
	"malloc_stats",
	"strtoimax",
	"getenv",
	"wcslen",
	"memmem",
	"wmempcpy",
	"getpid",
	"getpagesize",
	"arc4random",
	"qsort",
	"dlmopen",
	"getrlimit64",
	"memcpy",
	"strtoll_l",
	"rewinddir",
	"malloc",
	"isatty",
	"openat64",
	"sched_setscheduler",
	"sysinfo",
	"vsnprintf",
	"strtoll",
	"register_printf_modifier",
	"strtoumax",
	"strtoul",
	"sched_getscheduler",
	"pthread_rwlock_unlock",
	"readdir",
	"pvalloc",
	"dladdr",
	"lseek",
	"wmemcpy",
	"clearenv",
	"mmap",
	"strtol_l",
	"dlclose",
	"abort",
	"fstat64",
	"tdelete",
	"strtoq",
	"strtol",
	"strnlen",
	"strrchr",
	"calloc",
	"strcasecmp_l",
	"malloc_usable_size",
	"tdestroy",
	"rindex",
	"write",
	"dladdr1",
	"wmemchr",
	"fstat",
	"dcgettext",
	"pthread_once",
	"madvise",
	"mremap",
	"getdelim",
	"memchr",
	"tfind",
	"lstat",
	"strstr",
	"pthread_kill",
	"read",
	"getentropy",
	"strncmp",
	"dlopen",
	"wcsrtombs",
	"getdents64",
	"pthread_rwlock_wrlock",
	"get_avphys_pages",
	"setenv",
	"sched_get_priority_max",
	"funlockfile",
	"pthread_sigmask",
	"realloc",
	"readdir64",
	"wcsnlen",
	"register_printf_specifier",
	"memcmp",
	"sched_get_priority_min",
	"malloc_trim",
	"lstat64",
	"sigaction",
	"twalk_r",
	"dlsym",
	"sbrk",
	"strdup",
	"strtoull",
	"index",
	"fopen",
	"memset",
	"get_phys_pages",
	"mallinfo2",
	"mallopt",
	"fclose",
	"open64",
	"malloc_info",
	"tcgetattr",
	"opendir",
	"strcmp",
	"pthread_mutex_unlock",
	"register_printf_function",
	"strtoul_l",
	"getcwd",
	"fstatat64",
	"memalign",
	"asprintf",
	"strerror_r",
	"strcspn",
	"setlocale",
	"mmap64",
	"strsep",
	"valloc",
	"dlvsym",
	"fputc",
	"register_printf_type",
	"mallinfo",
	"pthread_self",
	"twalk",
	"argz_create_sep",
	"stat",
	"fast_exit",
	"wmemmove",
	"fwrite",
	"qsort_r",
	"strtouq",
	"pthread_mutex_lock",
	"gettext",
	"get_nprocs",
	"exit",
	"brk",
	"openat",
	"fgets_unlocked",
	"strspn",
	"strlen",
	"lseek64",
	"open",
	"strchr",
	"arc4random_buf",
	"fputs",
	"mprotect",
	"closedir",
	"vasprintf",
	"strchrnul",
	"get_nprocs_conf",
	"aligned_alloc",
	"posix_memalign",
	"wcrtomb",
	"close",
	"raise",
	"free",
	"sigprocmask",
	"fopen64",
	"accept4",
	"action_list_add__",
	"add_prefixlist",
	"arg_bool",
	"arg_trimdomain_list",
	"array_add__",
	"binary_hnok",
	"bind",
	"bsd_signal",
	"btowc",
	"canonicalize_file_name",
	"char_buffer_add_slow",
	"chdir",
	"chmod",
	"chown",
	"chroot",
	"cleanup",
	"clock_nanosleep",
	"clone",
	"clone3",
	"conf_decrement.part.0",
	"connect",
	"context_reuse",
	"context_send_common",
	"convert_hostent_to_gaih_addrtuple",
	"create_thread",
	"decrement_at_index.part.0",
	"dirfd",
	"dl_iterate_phdr",
	"dn_expand",
	"dn_skipname",
	"do_init",
	"dup2",
	"execve",
	"execvp",
	"execvpe",
	"faccessat",
	"fchdir",
	"fchmod",
	"fchown",
	"fcntl",
	"fcntl64",
	"fdatasync",
	"fgetgrent_r",
	"fgetpos",
	"fgetpos64",
	"fgetpwent_r",
	"fileno",
	"fileno_unlocked",
	"fork",
	"freeaddrinfo",
	"freeifaddrs",
	"fseeko",
	"fseeko64",
	"fsetpos",
	"fsetpos64",
	"fsync",
	"ftello",
	"ftello64",
	"ftruncate",
	"ftruncate64",
	"functions_allocate",
	"functions_deallocate",
	"futimens",
	"gai_strerror",
	"gaiconf_init",
	"gaih_getanswer_slice.isra.0",
	"gaih_inet_serv",
	"get_locked_global",
	"get_next_alias",
	"get_scope",
	"getaddrinfo",
	"getanswer_r",
	"getanswer_r.constprop.0",
	"getanswer_r_store_alias",
	"getegid",
	"geteuid",
	"getgid",
	"getgroups",
	"gethostbyname2_r",
	"gethostbyname3_context",
	"gethostbyname3_multi",
	"gethostname",
	"gethosts",
	"getifaddrs",
	"getifaddrs_internal",
	"getline",
	"getpeername",
	"getpgid",
	"getppid",
	"getpwuid_r",
	"getservbyname_r",
	"getsockname",
	"getsockopt",
	"getuid",
	"global_state_allocate",
	"gnu_get_libc_release",
	"gnu_get_libc_version",
	"group_member",
	"if_freenameindex",
	"if_indextoname",
	"if_nameindex",
	"if_nametoindex",
	"in6aicmp",
	"inet_addr",
	"inet_aton",
	"inet_aton_end",
	"inet_makeaddr",
	"inet_network",
	"inet_pton",
	"inet_pton4",
	"inet_pton6",
	"internal_getent",
	"internal_getent",
	"internal_getent",
	"internal_getent",
	"internal_getent",
	"internal_getent",
	"internal_getent",
	"internal_getent",
	"internal_getent",
	"internal_getent",
	"kill",
	"lchown",
	"linkat",
	"listen",
	"locked_vfxprintf",
	"longjmp",
	"match_prefix",
	"maybe_init",
	"maybe_script_execute",
	"mbrlen",
	"mbrtowc",
	"mbsrtowcs",
	"mkdir",
	"module_load",
	"module_load_builtin",
	"name_to_database_index",
	"nameserver_list_emplace",
	"nanosleep",
	"ns_name_compress",
	"ns_name_ntop",
	"ns_name_pack",
	"ns_name_pton",
	"ns_name_skip",
	"ns_name_uncompress",
	"ns_name_unpack",
	"nscd_gethst_r",
	"nscd_getpw_r",
	"nscd_getserv_r",
	"nss_database_check_reload_and_get",
	"nss_files_global_allocate",
	"open_socket",
	"pause",
	"pipe2",
	"poll",
	"posix_spawn_file_actions_adddup2",
	"posix_spawn_file_actions_destroy",
	"posix_spawn_file_actions_init",
	"posix_spawnattr_destroy",
	"posix_spawnattr_init",
	"posix_spawnattr_setflags",
	"posix_spawnattr_setpgroup",
	"posix_spawnattr_setsigdefault",
	"posix_spawnp",
	"prctl",
	"pread",
	"pread64",
	"preadv",
	"preadv64",
	"prefixcmp",
	"pthread_attr_destroy",
	"pthread_attr_getguardsize",
	"pthread_attr_getstack",
	"pthread_attr_init",
	"pthread_attr_setaffinity_np",
	"pthread_attr_setstacksize",
	"pthread_cancel",
	"pthread_create",
	"pthread_detach",
	"pthread_getaffinity_np",
	"pthread_getattr_default_np",
	"pthread_getattr_np",
	"pthread_getspecific",
	"pthread_join",
	"pthread_key_create",
	"pthread_key_delete",
	"pthread_mutex_trylock",
	"pthread_setcancelstate",
	"pthread_setname_np",
	"pthread_setspecific",
	"ptrlist_add__",
	"pwrite",
	"pwrite64",
	"pwritev",
	"pwritev64",
	"readlink",
	"readv",
	"realpath",
	"recv",
	"recvfrom",
	"recvmsg",
	"rename",
	"reopen",
	"res_dnok",
	"res_hnok",
	"res_mailok",
	"res_mkquery",
	"res_nmkquery",
	"res_nquery",
	"res_nquerydomain",
	"res_nsearch",
	"res_nsend",
	"res_ownok",
	"res_query",
	"res_querydomain",
	"res_search",
	"res_send",
	"res_setoptions",
	"resolv_conf_matches",
	"rewind",
	"rfc3484_sort",
	"rmdir",
	"round_and_return",
	"round_and_return",
	"round_and_return",
	"round_away",
	"round_away",
	"round_away",
	"rust_begin_unwind",
	"rust_eh_personality",
	"rust_panic",
	"same_address",
	"sched_getaffinity",
	"sched_setparam",
	"sched_yield",
	"scopecmp",
	"search_list_add__",
	"send",
	"send_dg",
	"send_vc",
	"sendfile",
	"sendfile64",
	"sendmmsg",
	"sendmsg",
	"sendto",
	"setgid",
	"setgroups",
	"setpgid",
	"setsid",
	"setsockopt",
	"setuid",
	"setxid_error",
	"setxid_mark_thread.isra.0",
	"setxid_signal_thread",
	"setxid_unmark_thread.isra.0",
	"sgetsgent_r",
	"sgetspent_r",
	"shutdown",
	"sigaddset",
	"sigaltstack",
	"sigcancel_handler",
	"sigemptyset",
	"siglongjmp",
	"signal",
	"sock_eq",
	"socket",
	"socketpair",
	"splice",
	"ssignal",
	"start_thread",
	"str_to_mpn.part.0.constprop.0",
	"str_to_mpn.part.0.constprop.0",
	"str_to_mpn.part.0.constprop.0",
	"strcasecmp",
	"strip_whitespace",
	"strncasecmp",
	"strncasecmp_l",
	"strncpy",
	"strpbrk",
	"strtod",
	"strtod_l",
	"strtof",
	"strtof128",
	"strtof128_l",
	"strtof32",
	"strtof32_l",
	"strtof32x",
	"strtof32x_l",
	"strtof64",
	"strtof64_l",
	"strtof64x",
	"strtof64x_l",
	"strtof_l",
	"strtold",
	"strtold_l",
	"symlink",
	"syscall",
	"tcsetpgrp",
	"towctrans",
	"uname",
	"ungetc",
	"unlink",
	"unlinkat",
	"unwind_cleanup",
	"unwind_stop",
	"utimensat",
	"wait4",
	"wait_on_socket",
	"waitid",
	"waitpid",
	"wcschrnul",
	"wctrans",
	"wmemset",
	"writev",
	"powf",
	"powf32",
	"sinf",
	"sinf32",
	"cosf",
	"cosf32",
	"sincosf",
	"sincosf32",
	"with_errnof",
	"xflowf",
	"floor",
	"floorf32x",
	"floorf64",
	"_i18n_number_rewrite",
	"_quicksort",
	"add_fdes",
	"buffer_free",
	"buffered_vfprintf",
	"buffered_vfprintf",
	"execute_cfa_program",
	"fflush",
	"frame_heapsort",
	"free_mem",
	"get_nprocs_cpu_online",
	"outstring_func.part.0",
	"profil",
	"pthread_testcancel",
	"rawmemchr",
	"search_object",
	"setitimer",

	/* Zig standard library */
	"OUTLINED_FUNCTION_0",
	"OUTLINED_FUNCTION_1",
	"OUTLINED_FUNCTION_10",
	"OUTLINED_FUNCTION_11",
	"OUTLINED_FUNCTION_12",
	"OUTLINED_FUNCTION_13",
	"OUTLINED_FUNCTION_14",
	"OUTLINED_FUNCTION_15",
	"OUTLINED_FUNCTION_16",
	"OUTLINED_FUNCTION_17",
	"OUTLINED_FUNCTION_18",
	"OUTLINED_FUNCTION_19",
	"OUTLINED_FUNCTION_2",
	"OUTLINED_FUNCTION_20",
	"OUTLINED_FUNCTION_21",
	"OUTLINED_FUNCTION_22",
	"OUTLINED_FUNCTION_23",
	"OUTLINED_FUNCTION_24",
	"OUTLINED_FUNCTION_25",
	"OUTLINED_FUNCTION_26",
	"OUTLINED_FUNCTION_27",
	"OUTLINED_FUNCTION_28",
	"OUTLINED_FUNCTION_29",
	"OUTLINED_FUNCTION_3",
	"OUTLINED_FUNCTION_30",
	"OUTLINED_FUNCTION_31",
	"OUTLINED_FUNCTION_32",
	"OUTLINED_FUNCTION_33",
	"OUTLINED_FUNCTION_34",
	"OUTLINED_FUNCTION_35",
	"OUTLINED_FUNCTION_36",
	"OUTLINED_FUNCTION_37",
	"OUTLINED_FUNCTION_38",
	"OUTLINED_FUNCTION_39",
	"OUTLINED_FUNCTION_4",
	"OUTLINED_FUNCTION_40",
	"OUTLINED_FUNCTION_41",
	"OUTLINED_FUNCTION_42",
	"OUTLINED_FUNCTION_43",
	"OUTLINED_FUNCTION_44",
	"OUTLINED_FUNCTION_45",
	"OUTLINED_FUNCTION_46",
	"OUTLINED_FUNCTION_47",
	"OUTLINED_FUNCTION_48",
	"OUTLINED_FUNCTION_49",
	"OUTLINED_FUNCTION_5",
	"OUTLINED_FUNCTION_50",
	"OUTLINED_FUNCTION_51",
	"OUTLINED_FUNCTION_52",
	"OUTLINED_FUNCTION_53",
	"OUTLINED_FUNCTION_6",
	"OUTLINED_FUNCTION_7",
	"OUTLINED_FUNCTION_8",
	"OUTLINED_FUNCTION_9",
	"Thread.Mutex.lock",
	"Thread.Mutex.unlock",
	"array_hash_map.ArrayHashMapUnmanaged(u64,dwarf.CommonInformationEntry,array_hash_map.AutoContext(u64),false).checkedHash__anon_8120",
	"array_hash_map.ArrayHashMapUnmanaged(u64,dwarf.CommonInformationEntry,array_hash_map.AutoContext(u64),false).getIndexAdapted__anon_6462",
	"array_hash_map.capacityIndexSize",
	"array_list.ArrayListAligned(dwarf.Abbrev,null).deinit",
	"array_list.ArrayListAligned(dwarf.Abbrev.Attr,null).deinit",
	"array_list.ArrayListAligned(dwarf.FileEntry,null).append",
	"array_list.ArrayListAligned(dwarf.FileEntry,null).deinit",
	"array_list.ArrayListAligned(dwarf.FileEntry,null).ensureTotalCapacity",
	"array_list.ArrayListAligned(dwarf.FileEntry,null).ensureUnusedCapacity",
	"array_list.ArrayListAlignedUnmanaged(dwarf.Func,null).append",
	"array_list.growCapacity",
	"builtin.default_panic",
	"compress.flate.CircularBuffer.writeMatch",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).alignToByte",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).readF__anon_8289",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).readN__anon_8326",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).read__anon_8245",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).read__anon_8255",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).read__anon_8257",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).read__anon_8273",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).read__anon_8285",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).shift",
	"compress.flate.inflate.Inflate(.zlib,u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).decodeDistance",
	"compress.zlib.decompressor__anon_5691",
	"debug.DebugInfo.lookupModuleDl__struct_5094.callback",
	"debug.DebugInfo.lookupModuleNameDl__struct_8137.callback",
	"debug.StackIterator.next_internal",
	"debug.panicExtra__anon_3473",
	"debug.panicImpl",
	"debug.panic__anon_3459",
	"debug.printLineInfo__anon_6571",
	"debug.printSourceAtAddress__anon_4391",
	"debug.printUnknownSource__anon_6467",
	"debug.readElfDebugInfo",
	"dwarf.Abbrev.deinit",
	"dwarf.Die.getAttr",
	"dwarf.Die.getAttrAddr",
	"dwarf.Die.getAttrRef",
	"dwarf.Die.getAttrString",
	"dwarf.DwarfInfo.DebugRangeIterator.init",
	"dwarf.DwarfInfo.DebugRangeIterator.next",
	"dwarf.DwarfInfo.getAbbrevTable",
	"dwarf.DwarfInfo.getLineString",
	"dwarf.DwarfInfo.getString",
	"dwarf.DwarfInfo.parseDie",
	"dwarf.DwarfInfo.readDebugAddr",
	"dwarf.DwarfInfo.section",
	"dwarf.DwarfInfo.sectionVirtualOffset",
	"dwarf.FixedBufferReader.readAddress",
	"dwarf.FixedBufferReader.readBytes",
	"dwarf.FixedBufferReader.readBytesTo__anon_6531",
	"dwarf.FixedBufferReader.readIleb128__anon_6026",
	"dwarf.FixedBufferReader.readInt__anon_5852",
	"dwarf.FixedBufferReader.readInt__anon_5853",
	"dwarf.FixedBufferReader.readInt__anon_5855",
	"dwarf.FixedBufferReader.readInt__anon_5856",
	"dwarf.FixedBufferReader.readInt__anon_6341",
	"dwarf.FixedBufferReader.readInt__anon_7985",
	"dwarf.FixedBufferReader.readUleb128__anon_5974",
	"dwarf.FixedBufferReader.readUleb128__anon_6340",
	"dwarf.FixedBufferReader.readUleb128__anon_6439",
	"dwarf.FixedBufferReader.readUleb128__anon_6441",
	"dwarf.FixedBufferReader.readUleb128__anon_6533",
	"dwarf.FormValue.getString",
	"dwarf.FormValue.getUInt__anon_6322",
	"dwarf.FormValue.getUInt__anon_6543",
	"dwarf.LineNumberProgram.checkLineMatch",
	"dwarf.getStringGeneric",
	"dwarf.openDwarfDebugInfo",
	"dwarf.parseFormValue",
	"dwarf.pcRelBase",
	"dwarf.readEhPointer",
	"dwarf.readUnitHeader",
	"dynamic_library.linkmap_iterator",
	"fmt.formatBuf__anon_3840",
	"fmt.formatType__anon_7951",
	"fmt.formatType__anon_8140",
	"fs.Dir.openFile",
	"fs.Dir.openFileZ",
	"fs.File.read",
	"fs.File.write",
	"fs.path.join",
	"hash.wyhash.Wyhash.hash",
	"hash_map.HashMapUnmanaged(usize,*debug.ModuleDebugInfo__struct_4192,hash_map.AutoContext(usize),80).putAssumeCapacityNoClobberContext",
	"hash_map.getAutoHashFn__struct_7613.hash",
	"heap.PageAllocator.alloc",
	"heap.PageAllocator.free",
	"heap.PageAllocator.resize",
	"heap.arena_allocator.ArenaAllocator.alloc",
	"heap.arena_allocator.ArenaAllocator.createNode",
	"heap.arena_allocator.ArenaAllocator.free",
	"heap.arena_allocator.ArenaAllocator.resize",
	"io.GenericReader(*compress.flate.inflate.Inflate(.zlib,u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))),error{EndOfStream,BadGzipHeader,BadZlibHeader,WrongGzipChecksum,WrongGzipSize,WrongZlibChecksum,InvalidCode,OversubscribedHuffmanTree,IncompleteHuffmanTree,MissingEndOfBlockCode,InvalidMatch,InvalidBlockType,WrongStoredBlockNlen,InvalidDynamicBlockHeader},(function 'read')).typeErasedReadFn",
	"io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read')).typeErasedReadFn",
	"io.GenericWriter(*io.buffered_writer.BufferedWriter(4096,io.GenericWriter(fs.File,error{DiskQuota,FileTooBig,InputOutput,NoSpaceLeft,DeviceBusy,InvalidArgument,AccessDenied,BrokenPipe,SystemResources,OperationAborted,NotOpenForWriting,LockViolation,WouldBlock,ConnectionResetByPeer,Unexpected},(function 'write'))),error{DiskQuota,FileTooBig,InputOutput,NoSpaceLeft,DeviceBusy,InvalidArgument,AccessDenied,BrokenPipe,SystemResources,OperationAborted,NotOpenForWriting,LockViolation,WouldBlock,ConnectionResetByPeer,Unexpected},(function 'write')).typeErasedWriteFn",
	"io.GenericWriter(*io.fixed_buffer_stream.FixedBufferStream([]u8),error{NoSpaceLeft},(function 'write')).typeErasedWriteFn",
	"io.GenericWriter(fs.File,error{DiskQuota,FileTooBig,InputOutput,NoSpaceLeft,DeviceBusy,InvalidArgument,AccessDenied,BrokenPipe,SystemResources,OperationAborted,NotOpenForWriting,LockViolation,WouldBlock,ConnectionResetByPeer,Unexpected},(function 'write')).typeErasedWriteFn",
	"io.Reader.readAll",
	"io.Reader.readNoEof",
	"io.Writer.writeAll",
	"io.Writer.writeBytesNTimes",
	"io.buffered_writer.BufferedWriter(4096,io.GenericWriter(fs.File,error{DiskQuota,FileTooBig,InputOutput,NoSpaceLeft,DeviceBusy,InvalidArgument,AccessDenied,BrokenPipe,SystemResources,OperationAborted,NotOpenForWriting,LockViolation,WouldBlock,ConnectionResetByPeer,Unexpected},(function 'write'))).flush",
	"io.tty.Config.setColor__anon_7444",
	"mem.Allocator.alignedAlloc__anon_6448",
	"mem.Allocator.alignedAlloc__anon_7981",
	"mem.Allocator.alignedAlloc__anon_7983",
	"mem.Allocator.allocBytesWithAlignment__anon_7926",
	"mem.Allocator.allocWithSizeAndAlignment__anon_7984",
	"mem.Allocator.allocWithSizeAndAlignment__anon_8110",
	"mem.Allocator.allocWithSizeAndAlignment__anon_8112",
	"mem.Allocator.alloc__anon_5692",
	"mem.Allocator.alloc__anon_6121",
	"mem.Allocator.destroy__anon_6398",
	"mem.Allocator.free__anon_5398",
	"mem.Allocator.free__anon_5836",
	"mem.Allocator.free__anon_6123",
	"mem.Allocator.free__anon_6449",
	"mem.Allocator.free__anon_7977",
	"mem.Allocator.free__anon_7978",
	"mem.Allocator.free__anon_8044",
	"mem.Allocator.resize__anon_7980",
	"mem.Allocator.resize__anon_7982",
	"mem.eql__anon_5097",
	"mem.indexOfScalarPos__anon_6542",
	"mem.indexOfScalar__anon_7449",
	"mem.indexOfSentinel__anon_8101",
	"mem.replaceScalar__anon_7450",
	"mem.sliceTo__anon_5096",
	"mem.sliceTo__anon_5399",
	"multi_array_list.MultiArrayList(array_hash_map.ArrayHashMapUnmanaged(u64,dwarf.CommonInformationEntry,array_hash_map.AutoContext(u64),false).Data).ensureTotalCapacity",
	"multi_array_list.MultiArrayList(array_hash_map.ArrayHashMapUnmanaged(u64,dwarf.CommonInformationEntry,array_hash_map.AutoContext(u64),false).Data).slice",
	"os.linux.riscv64.restore_rt",
	"posix.abort",
	"posix.getenv",
	"posix.mmap",
	"posix.raise",
	"posix.realpath",
	"posix.sigaction",
	"process.getBaseAddress",
	"sort.heap__anon_8281",
	"sort.heap__anon_8281.Context.lessThan",
	"sort.pdq.sort3__anon_8431",
	"sort.siftDown__anon_8429",
	"sort.siftDown__anon_8502",
	"start.noopSigHandler",
	"start.posixCallMainAndExit",
};

static bool is_excluded_function(const std::string_view function) {
	// API syscall wrappers: "sys_"
	if (function.size() >= 4 && function[0] == 's' && function[1] == 'y' && function[2] == 's' && function[3] == '_') {
		return true;
	}
	// Special cases for C/C++ runtime functions.
	// Begins with "_GLOBAL_"
	if (function.size() >= 8 && function[0] == '_' && function[1] == 'G' && function[2] == 'L' && function[3] == 'O' && function[4] == 'B' && function[5] == 'A' && function[6] == 'L' && function[7] == '_') {
		return true;
	}
	// Begins with "_IO_"
	if (function.size() >= 4 && function[0] == '_' && function[1] == 'I' && function[2] == 'O' && function[3] == '_') {
		return true;
	}
	// Begins with "_Unwind_"
	if (function.size() >= 8 && function[0] == '_' && function[1] == 'U' && function[2] == 'n' && function[3] == 'w' && function[4] == 'i' && function[5] == 'n' && function[6] == 'd' && function[7] == '_') {
		return true;
	}
	// Begins with "_dl_"
	if (function.size() >= 4 && function[0] == '_' && function[1] == 'd' && function[2] == 'l' && function[3] == '_') {
		return true;
	}
	// Begins with "_nl_"
	if (function.size() >= 4 && function[0] == '_' && function[1] == 'n' && function[2] == 'l' && function[3] == '_') {
		return true;
	}
	// Begins with "_nss_"
	if (function.size() >= 5 && function[0] == '_' && function[1] == 'n' && function[2] == 's' && function[3] == 's' && function[4] == '_') {
		return true;
	}

	return false;
}

PackedStringArray Sandbox::get_functions() const {
	PackedStringArray result;
	try {
		// Get all unmangled public functions from the guest program.
		// Exclude functions that belong to the C/C++ runtime, as well as compiler-generated functions.
		for (std::string_view function : machine().memory.all_unmangled_function_symbols()) {
			// Double underscore functions are compiler-generated functions.
			if (function.size() >= 2 && function[0] == '_' && function[1] == '_') {
				continue;
			}
			if (is_excluded_function(function)) {
				continue;
			}
			if (exclude_functions.count(function) == 0) {
				result.append(String(std::string(function).c_str()));
			}
		}
	} catch (const std::exception &e) {
		ERR_PRINT("Sandbox: Failed to get functions: " + String(e.what()));
	}
	return result;
}

Sandbox::BinaryInfo Sandbox::get_program_info_from_binary(const PackedByteArray &binary) {
	BinaryInfo result;
	if (binary.is_empty()) {
		return result;
	}

	const std::string_view binary_view = std::string_view{ (const char *)binary.ptr(), static_cast<size_t>(binary.size()) };
	try {
		// Instantiate Machine without loading the ELF
		machine_t machine{ binary_view, riscv::MachineOptions<RISCV_ARCH>{
												.load_program = false, // Do not load the ELF program.
										} };
		std::vector<std::string_view> comments = machine.memory.elf_comments();
		// Detect language: C++, Rust, etc.
		result.language = "Unknown";
		result.version = 0;
		for (std::string_view comment : comments) {
			if (comment.find("Godot Rust") != std::string::npos) {
				// Rust: "Godot Rust API v1"
				result.language = "Rust";
				auto version = comment.find("API v");
				if (version != std::string::npos) {
					result.version = std::stoi(std::string(comment.substr(version + 5)));
				}
				break;
			} else if (comment.find("Godot C++") != std::string::npos) {
				// C++: "Godot C++ API v1"
				result.language = "C++";
				auto version = comment.find("API v");
				if (version != std::string::npos) {
					result.version = std::stoi(std::string(comment.substr(version + 5)));
				}
				break;
			} else if (comment.find("Godot Zig") != std::string::npos) {
				// Zig: "Godot Zig API v1"
				result.language = "Zig";
				auto version = comment.find("API v");
				if (version != std::string::npos) {
					result.version = std::stoi(std::string(comment.substr(version + 5)));
				}
				break;
			}
		}
		//printf("Detected language: %s, version: %d\n", result.language.utf8().ptr(), result.version);

		// Get all unmangled public functions from the guest program.
		// Exclude functions that belong to the C/C++ runtime, as well as compiler-generated functions.
		for (std::string_view function : machine.memory.all_unmangled_function_symbols()) {
			// Double underscore functions are compiler-generated functions.
			if (function.size() >= 2 && function[0] == '_' && function[1] == '_') {
				continue;
			}
			if (is_excluded_function(function)) {
				continue;
			}
			if (exclude_functions.count(function) == 0) {
				result.functions.append(String(std::string(function).c_str()));
			}
		}
	} catch (const std::exception &e) {
		ERR_PRINT("Failed to get functions from binary. " + String(e.what()));
	}
	return result;
}
