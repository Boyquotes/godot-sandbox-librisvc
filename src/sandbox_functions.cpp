#include "sandbox.h"

#include <unordered_set>

using namespace godot;
static const std::unordered_set<std::string_view> exclude_functions{
	"_Balloc",
	"_Bfree",
	"_calloc_r",
	"_cleanup_r",
	"_cleanup",
	"_close_r",
	"_close",
	"_conv_stat",
	"_dlerror_run",
	"_dlfo_process_initial",
	"_dlfo_sort_mappings.part.0",
	"_dlfo_sort_mappings",
	"_exit",
	"_Exit",
	"_fclose_r",
	"_fflush_r",
	"_findenv_r",
	"_findenv",
	"_fiprintf_r",
	"_fitoa_word",
	"_flushlbf",
	"_Fork",
	"_fprintf_r",
	"_fputc_r",
	"_fputs_r",
	"_fputwc_r",
	"_free_r",
	"_fstat_r",
	"_fstat",
	"_fwalk_reent",
	"_fwalk_sglue",
	"_fwalk",
	"_fwrite_r",
	"_getenv_r",
	"_getpid_r",
	"_getpid",
	"_i18n_number_rewrite",
	"_init_signal_r",
	"_init_signal",
	"_int_free_create_chunk",
	"_int_free_maybe_consolidate.part.0",
	"_int_free_merge_chunk",
	"_int_free",
	"_int_malloc",
	"_int_memalign",
	"_int_realloc",
	"_isatty_r",
	"_isatty",
	"_itoa_word",
	"_kill_r",
	"_kill",
	"_ldcheck",
	"_ldtoa_r",
	"_localeconv_r",
	"_longjmp_unwind",
	"_longjmp",
	"_lseek_r",
	"_lseek",
	"_malloc_r",
	"_malloc_trim_r",
	"_mbrtowc_r",
	"_mbtowc_r",
	"_mid_memalign.constprop.0",
	"_mid_memalign.isra.0",
	"_mprec_log10",
	"_pthread_cleanup_pop",
	"_pthread_cleanup_push",
	"_putc_r",
	"_putc_unlocked_r",
	"_quicksort",
	"_raise_r",
	"_read_r",
	"_read",
	"_realloc_r",
	"_reclaim_reent",
	"_res_hconf_init",
	"_res_hconf_reorder_addrs",
	"_res_hconf_trim_domain",
	"_res_hconf_trim_domains",
	"_sbrk_r",
	"_sbrk",
	"_setjmp",
	"_setlocale_r",
	"_sfread_r",
	"_signal_r",
	"_siscanf_r",
	"_sniprintf_r",
	"_sprintf_r",
	"_sscanf_r",
	"_start",
	"_strerror_r",
	"_strtod_l",
	"_strtod_r",
	"_strtodg_l",
	"_strtol_l.isra.0",
	"_strtol_r",
	"_strtold_r",
	"_strtoll_l.isra.0",
	"_strtoll_r",
	"_strtorx_l",
	"_strtoul_l.constprop.0",
	"_strtoul_l.isra.0",
	"_strtoul_r",
	"_strtoull_l.isra.0",
	"_strtoull_r",
	"_sungetc_r",
	"_svfiprintf_r",
	"_svfprintf_r",
	"_svfwprintf_r",
	"_swprintf_r",
	"_tzset_r",
	"_tzset_unlocked_r",
	"_tzset_unlocked",
	"_ungetc_r",
	"_user_strerror",
	"_vfiprintf_r",
	"_vfprintf_r",
	"_vsnprintf_r",
	"_wcrtomb_r",
	"_wcstoul_l",
	"_wcstoul_r",
	"_wctomb_r",
	"_wctype_r",
	"_write_r",
	"_write",
	"abort",
	"abs",
	"accept4",
	"action_list_add__",
	"add_alias2.part.0",
	"add_fdes.isra.0",
	"add_fdes",
	"add_module",
	"add_name_to_object.isra.0",
	"add_path.constprop.0.isra.0",
	"add_prefixlist",
	"add_to_global_resize_failure.isra.0",
	"add_to_global_resize",
	"add_to_global_update",
	"adjust_wide_data",
	"alias_compare",
	"aligned_alloc",
	"alloc_new_heap",
	"alloc_perturb",
	"arc4random_buf",
	"arc4random",
	"arena_get_retry",
	"arena_get2",
	"arg_bool",
	"arg_trimdomain_list",
	"argz_add_sep",
	"argz_create_sep",
	"array_add__",
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
	"asprintf",
	"atexit",
	"base_from_object",
	"base_of_encoded_value",
	"bcmp",
	"binary_hnok",
	"bind",
	"brk",
	"bsd_signal",
	"btowc",
	"btree_allocate_node",
	"btree_destroy",
	"btree_handle_root_split.part.0",
	"btree_insert.isra.0",
	"btree_node_update_separator_after_split",
	"btree_release_tree_recursively",
	"btree_remove",
	"buffer_free",
	"buffered_vfprintf",
	"builtin.default_panic",
	"call_destructors",
	"call_dl_init",
	"call_dl_lookup",
	"call_fini",
	"call_init",
	"calloc",
	"canonicalize_file_name",
	"char_buffer_add_slow",
	"chdir",
	"check_match",
	"check_one_fd",
	"chmod",
	"chown",
	"chroot",
	"classify_object_over_fdes.constprop.0",
	"classify_object_over_fdes",
	"cleanup_glue",
	"cleanup_stdio",
	"cleanup",
	"clear_once_control",
	"clearenv",
	"clock_gettime",
	"clock_nanosleep",
	"clone",
	"clone3",
	"close",
	"closedir",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).alignToByte",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).read__anon_8245",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).read__anon_8255",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).read__anon_8257",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).read__anon_8273",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).read__anon_8285",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).readF__anon_8289",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).readN__anon_8326",
	"compress.flate.bit_reader.BitReader(u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).shift",
	"compress.flate.CircularBuffer.writeMatch",
	"compress.flate.inflate.Inflate(.zlib,u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))).decodeDistance",
	"compress.zlib.decompressor__anon_5691",
	"conf_decrement.part.0",
	"connect",
	"context_reuse",
	"context_send_common",
	"convert_hostent_to_gaih_addrtuple",
	"cosf",
	"cosf32",
	"create_thread",
	"d_abi_tags",
	"d_add_substitution",
	"d_append_buffer",
	"d_append_char",
	"d_append_num",
	"d_append_string",
	"d_args_length",
	"d_array_type",
	"d_backtrack",
	"d_bare_function_type",
	"d_call_offset",
	"d_checkpoint",
	"d_class_enum_type",
	"d_clone_suffix",
	"d_compact_number",
	"d_count_templates_scopes",
	"d_ctor_dtor_name",
	"d_cv_qualifiers",
	"d_demangle_callback.constprop.0",
	"d_demangle_callback",
	"d_demangle",
	"d_discriminator",
	"d_encoding.part.0",
	"d_encoding",
	"d_expr_primary",
	"d_expression_1",
	"d_expression",
	"d_exprlist",
	"d_fill_ctor",
	"d_fill_dtor",
	"d_fill_extended_operator",
	"d_fill_name",
	"d_find_pack",
	"d_function_type",
	"d_get_saved_scope",
	"d_growable_string_append_buffer",
	"d_growable_string_callback_adapter",
	"d_growable_string_init",
	"d_growable_string_resize",
	"d_identifier",
	"d_index_template_argument.part.0",
	"d_index_template_argument",
	"d_init_info",
	"d_java_resource",
	"d_lambda",
	"d_last_char",
	"d_local_name",
	"d_lookup_template_argument",
	"d_make_builtin_type",
	"d_make_character",
	"d_make_comp",
	"d_make_ctor",
	"d_make_default_arg",
	"d_make_demangle_mangled_name",
	"d_make_dtor",
	"d_make_empty",
	"d_make_extended_builtin_type",
	"d_make_extended_operator",
	"d_make_function_param",
	"d_make_name",
	"d_make_operator",
	"d_make_sub",
	"d_make_template_param",
	"d_mangled_name",
	"d_maybe_constraints",
	"d_maybe_module_name",
	"d_maybe_print_designated_init",
	"d_maybe_print_fold_expression",
	"d_name",
	"d_nested_name",
	"d_number_component",
	"d_number",
	"d_operator_name",
	"d_pack_length",
	"d_parmlist",
	"d_pointer_to_member_type",
	"d_prefix",
	"d_print_array_type",
	"d_print_callback",
	"d_print_cast",
	"d_print_comp_inner",
	"d_print_comp",
	"d_print_conversion",
	"d_print_error",
	"d_print_expr_op",
	"d_print_flush",
	"d_print_function_type",
	"d_print_init",
	"d_print_java_identifier",
	"d_print_lambda_parm_name",
	"d_print_mod_list",
	"d_print_mod",
	"d_print_saw_error",
	"d_print_subexpr",
	"d_print",
	"d_ref_qualifier",
	"d_save_scope",
	"d_source_name",
	"d_special_name",
	"d_substitution",
	"d_template_arg",
	"d_template_args_1",
	"d_template_args",
	"d_template_head",
	"d_template_param",
	"d_template_parm",
	"d_type",
	"d_unnamed_type",
	"d_unqualified_name",
	"d_unresolved_name",
	"d_vector_type",
	"dcgettext",
	"debug.DebugInfo.lookupModuleDl__struct_5094.callback",
	"debug.DebugInfo.lookupModuleNameDl__struct_8137.callback",
	"debug.panic__anon_3459",
	"debug.panicExtra__anon_3473",
	"debug.panicImpl",
	"debug.printLineInfo__anon_6571",
	"debug.printSourceAtAddress__anon_4391",
	"debug.printUnknownSource__anon_6467",
	"debug.readElfDebugInfo",
	"debug.StackIterator.next_internal",
	"decide_maybe_mmap",
	"decompose_rpath",
	"decrement_at_index.part.0",
	"decrement",
	"deregister_tm_clones",
	"derivation_compare",
	"detach_arena.part.0",
	"dfs_traversal.part.0",
	"dirfd",
	"dl_iterate_phdr",
	"dl_open_worker_begin",
	"dl_open_worker",
	"dladdr",
	"dladdr1",
	"dlclose",
	"dlerror_run",
	"dlerror",
	"dlinfo_doit",
	"dlinfo",
	"dlmopen_doit",
	"dlmopen",
	"dlopen_doit",
	"dlopen",
	"dlsym_doit",
	"dlsym",
	"dlvsym_doit",
	"dlvsym",
	"dn_expand",
	"dn_skipname",
	"do_dlclose",
	"do_dlopen",
	"do_dlsym_private",
	"do_dlsym",
	"do_dlvsym",
	"do_init",
	"do_lookup_x",
	"do_release_all",
	"do_release_shlib",
	"do_swap",
	"do_sym",
	"do_tunable_update_val",
	"dup2",
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
	"dwarf.getStringGeneric",
	"dwarf.LineNumberProgram.checkLineMatch",
	"dwarf.openDwarfDebugInfo",
	"dwarf.parseFormValue",
	"dwarf.pcRelBase",
	"dwarf.readEhPointer",
	"dwarf.readUnitHeader",
	"dynamic_library.linkmap_iterator",
	"e113toe.isra.0",
	"ecmp",
	"ediv",
	"eiremain",
	"elf_machine_matches_host",
	"emdnorm",
	"emovi",
	"emovo.constprop.0",
	"emul",
	"enlarge_userbuf",
	"enormlz",
	"epoll_create1",
	"epoll_ctl",
	"epoll_pwait",
	"epoll_wait",
	"eshdn1",
	"eshift.part.0",
	"eshup1",
	"eventfd",
	"execute_cfa_program_generic",
	"execute_cfa_program_specialized",
	"execute_cfa_program",
	"execute_stack_op",
	"execve",
	"execvp",
	"execvpe",
	"exit",
	"expand_dynamic_string_token",
	"faccessat",
	"fast_exit",
	"fatal_error",
	"fchdir",
	"fchmod",
	"fchown",
	"fclose",
	"fcntl",
	"fcntl64",
	"fdatasync",
	"fde_mixed_encoding_compare",
	"fde_mixed_encoding_extract",
	"fde_radixsort",
	"fde_single_encoding_compare",
	"fde_single_encoding_extract",
	"fde_unencoded_compare",
	"fde_unencoded_extract",
	"fdopendir",
	"fflush",
	"fgetgrent_r",
	"fgetpos",
	"fgetpos64",
	"fgetpwent_r",
	"fgets_unlocked",
	"fileno_unlocked",
	"fileno",
	"fillin_rpath.isra.0",
	"find_derivation",
	"find_module_idx",
	"find_module.constprop.0",
	"fiprintf",
	"flockfile",
	"floor",
	"floorf32x",
	"floorf64",
	"flush_cleanup",
	"fmin",
	"fminf32x",
	"fminf64",
	"fmt.formatBuf__anon_3840",
	"fmt.formatType__anon_7951",
	"fmt.formatType__anon_8140",
	"fopen",
	"fopen64",
	"fork",
	"fprintf",
	"fputc",
	"fputs",
	"fputwc",
	"frame_downheap",
	"frame_dummy",
	"frame_heapsort",
	"free_category",
	"free_derivation",
	"free_mem",
	"free_modules_db",
	"free_slotinfo",
	"free",
	"freeaddrinfo",
	"freeifaddrs",
	"frexp",
	"frexpl",
	"fs.Dir.openFile",
	"fs.Dir.openFileZ",
	"fs.File.read",
	"fs.File.write",
	"fs.path.join",
	"fseek",
	"fseeko",
	"fseeko64",
	"fsetpos",
	"fsetpos64",
	"fstat",
	"fstat64",
	"fstatat",
	"fstatat64",
	"fsync",
	"ftello",
	"ftello64",
	"ftruncate",
	"ftruncate64",
	"functions_allocate",
	"functions_deallocate",
	"funlockfile",
	"futimens",
	"fwrite",
	"gai_strerror",
	"gaiconf_init",
	"gaih_getanswer_slice.isra.0",
	"gaih_inet_serv",
	"gconv_parse_code",
	"gen_negf",
	"get_avphys_pages",
	"get_cie_encoding",
	"get_fde_encoding",
	"get_locked_global",
	"get_next_alias",
	"get_nproc_stat",
	"get_nprocs_conf",
	"get_nprocs_cpu_online",
	"get_nprocs",
	"get_pc_range",
	"get_phys_pages",
	"get_scope",
	"getaddrinfo",
	"getanswer_r_store_alias",
	"getanswer_r.constprop.0",
	"getanswer_r",
	"getauxval",
	"getcwd",
	"getdelim",
	"getdents64",
	"getdtablesize",
	"getegid",
	"getentropy",
	"getenv",
	"geteuid",
	"getgid",
	"getgroups",
	"gethostbyname2_r",
	"gethostbyname3_context",
	"gethostbyname3_multi",
	"gethostname",
	"gethosts",
	"getifaddrs_internal",
	"getifaddrs",
	"getline",
	"getpagesize",
	"getpeername",
	"getpgid",
	"getpid",
	"getppid",
	"getpwuid_r",
	"getrlimit",
	"getrlimit64",
	"getservbyname_r",
	"getsockname",
	"getsockopt",
	"gettext",
	"getuid",
	"global_state_allocate",
	"global_stdio_init.part.0",
	"gnu_get_libc_release",
	"gnu_get_libc_version",
	"group_member",
	"group_number",
	"gsignal",
	"hack_digit",
	"has_return_type",
	"hash_map.getAutoHashFn__struct_7613.hash",
	"hash_map.HashMapUnmanaged(usize,*debug.ModuleDebugInfo__struct_4192,hash_map.AutoContext(usize),80).putAssumeCapacityNoClobberContext",
	"hash.wyhash.Wyhash.hash",
	"heap.arena_allocator.ArenaAllocator.alloc",
	"heap.arena_allocator.ArenaAllocator.createNode",
	"heap.arena_allocator.ArenaAllocator.free",
	"heap.arena_allocator.ArenaAllocator.resize",
	"heap.PageAllocator.alloc",
	"heap.PageAllocator.free",
	"heap.PageAllocator.resize",
	"if_freenameindex",
	"if_indextoname",
	"if_nameindex",
	"if_nametoindex",
	"in6aicmp",
	"increment",
	"index",
	"indirect_msort_with_tmp",
	"inet_addr",
	"inet_aton_end",
	"inet_aton",
	"inet_makeaddr",
	"inet_network",
	"inet_pton",
	"inet_pton4",
	"inet_pton6",
	"init_dwarf_reg_size_table",
	"insert_module",
	"int_mallinfo",
	"internal_getent",
	"io.buffered_writer.BufferedWriter(4096,io.GenericWriter(fs.File,error{DiskQuota,FileTooBig,InputOutput,NoSpaceLeft,DeviceBusy,InvalidArgument,AccessDenied,BrokenPipe,SystemResources,OperationAborted,NotOpenForWriting,LockViolation,WouldBlock,ConnectionResetByPeer,Unexpected},(function 'write'))).flush",
	"io.GenericReader(*compress.flate.inflate.Inflate(.zlib,u32,io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read'))),error{EndOfStream,BadGzipHeader,BadZlibHeader,WrongGzipChecksum,WrongGzipSize,WrongZlibChecksum,InvalidCode,OversubscribedHuffmanTree,IncompleteHuffmanTree,MissingEndOfBlockCode,InvalidMatch,InvalidBlockType,WrongStoredBlockNlen,InvalidDynamicBlockHeader},(function 'read')).typeErasedReadFn",
	"io.GenericReader(*io.fixed_buffer_stream.FixedBufferStream([]const u8),error{},(function 'read')).typeErasedReadFn",
	"io.GenericWriter(*io.buffered_writer.BufferedWriter(4096,io.GenericWriter(fs.File,error{DiskQuota,FileTooBig,InputOutput,NoSpaceLeft,DeviceBusy,InvalidArgument,AccessDenied,BrokenPipe,SystemResources,OperationAborted,NotOpenForWriting,LockViolation,WouldBlock,ConnectionResetByPeer,Unexpected},(function 'write'))),error{DiskQuota,FileTooBig,InputOutput,NoSpaceLeft,DeviceBusy,InvalidArgument,AccessDenied,BrokenPipe,SystemResources,OperationAborted,NotOpenForWriting,LockViolation,WouldBlock,ConnectionResetByPeer,Unexpected},(function 'write')).typeErasedWriteFn",
	"io.GenericWriter(*io.fixed_buffer_stream.FixedBufferStream([]u8),error{NoSpaceLeft},(function 'write')).typeErasedWriteFn",
	"io.GenericWriter(fs.File,error{DiskQuota,FileTooBig,InputOutput,NoSpaceLeft,DeviceBusy,InvalidArgument,AccessDenied,BrokenPipe,SystemResources,OperationAborted,NotOpenForWriting,LockViolation,WouldBlock,ConnectionResetByPeer,Unexpected},(function 'write')).typeErasedWriteFn",
	"io.Reader.readAll",
	"io.Reader.readNoEof",
	"io.tty.Config.setColor__anon_7444",
	"io.Writer.writeAll",
	"io.Writer.writeBytesNTimes",
	"ioctl",
	"is_ctor_dtor_or_conversion",
	"is_designated_init",
	"is_dst",
	"is_fnqual_component_type",
	"is_trusted_path_normalize",
	"isatty",
	"iso_year_adjust.isra.0",
	"iswalnum_l",
	"iswalnum",
	"iswalpha_l",
	"iswalpha",
	"iswblank_l",
	"iswblank",
	"iswcntrl_l",
	"iswcntrl",
	"iswctype",
	"iswdigit",
	"iswgraph_l",
	"iswgraph",
	"iswlower_l",
	"iswlower",
	"iswprint_l",
	"iswprint",
	"iswpunct_l",
	"iswpunct",
	"iswspace_l",
	"iswspace",
	"iswupper_l",
	"iswupper",
	"iswxdigit",
	"kill",
	"known_compare",
	"labs",
	"lchown",
	"length_mismatch",
	"linear_search_fdes",
	"linkat",
	"listen",
	"localeconv",
	"localtime",
	"locked_vfxprintf",
	"longjmp",
	"lseek",
	"lseek64",
	"lstat",
	"lstat64",
	"m16m",
	"madvise",
	"main",
	"mallinfo",
	"mallinfo2",
	"malloc_consolidate",
	"malloc_info",
	"malloc_printerr",
	"malloc_stats",
	"malloc_trim",
	"malloc_usable_size",
	"malloc",
	"mallopt",
	"match_prefix",
	"maybe_init",
	"maybe_script_execute",
	"maybe_split_for_insert.isra.0",
	"mbrlen",
	"mbrtowc",
	"mbsrtowcs",
	"mbstowcs",
	"mem.Allocator.alignedAlloc__anon_6448",
	"mem.Allocator.alignedAlloc__anon_7981",
	"mem.Allocator.alignedAlloc__anon_7983",
	"mem.Allocator.alloc__anon_5692",
	"mem.Allocator.alloc__anon_6121",
	"mem.Allocator.allocBytesWithAlignment__anon_7926",
	"mem.Allocator.allocWithSizeAndAlignment__anon_7984",
	"mem.Allocator.allocWithSizeAndAlignment__anon_8110",
	"mem.Allocator.allocWithSizeAndAlignment__anon_8112",
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
	"mem.indexOfScalar__anon_7449",
	"mem.indexOfScalarPos__anon_6542",
	"mem.indexOfSentinel__anon_8101",
	"mem.replaceScalar__anon_7450",
	"mem.sliceTo__anon_5096",
	"mem.sliceTo__anon_5399",
	"memalign",
	"memchr",
	"memcmp",
	"memcpy",
	"memmem",
	"memmove",
	"memrchr",
	"memset",
	"mkdir",
	"mktime",
	"mmap_remap_check",
	"mmap",
	"mmap64",
	"module_load_builtin",
	"module_load",
	"mprotect",
	"mremap",
	"msort_with_tmp.part.0",
	"multi_array_list.MultiArrayList(array_hash_map.ArrayHashMapUnmanaged(u64,dwarf.CommonInformationEntry,array_hash_map.AutoContext(u64),false).Data).ensureTotalCapacity",
	"multi_array_list.MultiArrayList(array_hash_map.ArrayHashMapUnmanaged(u64,dwarf.CommonInformationEntry,array_hash_map.AutoContext(u64),false).Data).slice",
	"munmap_chunk",
	"munmap",
	"name_to_database_index",
	"nameserver_list_emplace",
	"nan",
	"nanf",
	"nanosleep",
	"new_composite_name",
	"new_do_write",
	"new_heap",
	"next_is_type_qual.isra.0",
	"next_is_type_qual",
	"next_line",
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
	"op_is_new_cast.isra.0",
	"op_is_new_cast",
	"open_path.isra.0",
	"open_socket",
	"open_verify.constprop.0",
	"open",
	"open64",
	"openat",
	"openat64",
	"openaux",
	"opendir_tail",
	"opendir",
	"os.linux.riscv64.restore_rt",
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
	"outstring_converted_wide_string",
	"outstring_func.part.0",
	"parse_tunables",
	"pause",
	"pipe2",
	"plural_eval",
	"poll",
	"posix_memalign",
	"posix_spawn_file_actions_adddup2",
	"posix_spawn_file_actions_destroy",
	"posix_spawn_file_actions_init",
	"posix_spawnattr_destroy",
	"posix_spawnattr_init",
	"posix_spawnattr_setflags",
	"posix_spawnattr_setpgroup",
	"posix_spawnattr_setsigdefault",
	"posix_spawnp",
	"posix.abort",
	"posix.getenv",
	"posix.mmap",
	"posix.raise",
	"posix.realpath",
	"posix.sigaction",
	"powf",
	"powf32",
	"ppoll",
	"prctl",
	"pread",
	"pread64",
	"preadv",
	"preadv64",
	"prefixcmp",
	"printf_positional",
	"process.getBaseAddress",
	"profil",
	"pthread_testcancel",
	"ptmalloc_init.part.0",
	"ptrlist_add__",
	"putc_unlocked",
	"putc",
	"putchar",
	"pvalloc",
	"pwrite",
	"pwrite64",
	"pwritev",
	"pwritev64",
	"qsort_r",
	"qsort",
	"raise",
	"rawmemchr",
	"read_alias_file",
	"read_conf_file.isra.0",
	"read_encoded_value_with_base",
	"read_encoded_value",
	"read_int",
	"read_sleb128",
	"read_sysfs_file",
	"read_uleb128",
	"read",
	"readdir",
	"readdir64",
	"readlink",
	"readlinkat",
	"readv",
	"realloc",
	"realpath",
	"recv",
	"recvfrom",
	"recvmsg",
	"register_fini",
	"register_printf_function",
	"register_printf_modifier",
	"register_printf_specifier",
	"register_printf_type",
	"register_tm_clones",
	"release_registered_frames",
	"remove_slotinfo",
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
	"rewinddir",
	"rfc3484_sort",
	"rindex",
	"rmdir",
	"round_and_return",
	"round_away",
	"rshift",
	"rust_begin_unwind",
	"rust_eh_personality",
	"rust_panic",
	"rvOK.constprop.0",
	"same_address",
	"save_for_backup",
	"save_for_wbackup",
	"sbrk",
	"sched_get_priority_max",
	"sched_get_priority_min",
	"sched_getaffinity",
	"sched_getparam",
	"sched_getscheduler",
	"sched_setparam",
	"sched_setscheduler",
	"sched_yield",
	"scopecmp",
	"search_cache",
	"search_list_add__",
	"search_object",
	"secure_getenv",
	"send_dg",
	"send_vc",
	"send",
	"sendfile",
	"sendfile64",
	"sendmmsg",
	"sendmsg",
	"sendto",
	"set_ones",
	"setenv",
	"setgid",
	"setgroups",
	"setitimer",
	"setjmp",
	"setlocale",
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
	"sigaction",
	"sigaddset",
	"sigaltstack",
	"sigcancel_handler",
	"sigemptyset",
	"siglongjmp",
	"signal",
	"sigprocmask",
	"sincosf",
	"sincosf32",
	"sinf",
	"sinf32",
	"siscanf",
	"size_of_encoded_value",
	"sniprintf",
	"snprintf",
	"sock_eq",
	"socket",
	"socketpair",
	"sort.heap__anon_8281.Context.lessThan",
	"sort.heap__anon_8281",
	"sort.pdq.sort3__anon_8431",
	"sort.siftDown__anon_8429",
	"sort.siftDown__anon_8502",
	"splice",
	"sprintf",
	"sqrtf",
	"sscanf",
	"ssignal",
	"start_thread",
	"start.noopSigHandler",
	"start.posixCallMainAndExit",
	"stat",
	"stat64",
	"stdio_exit_handler",
	"stpcpy",
	"str_to_mpn.part.0.constprop.0",
	"strcasecmp_l",
	"strcasecmp",
	"strchr",
	"strchrnul",
	"strcmp",
	"strcoll",
	"strcpy",
	"strcspn",
	"strdup",
	"strerror_l",
	"strerror_r",
	"strerror",
	"strftime_l",
	"strftime",
	"strip_whitespace",
	"strlen",
	"strncasecmp_l",
	"strncasecmp",
	"strncmp",
	"strncpy",
	"strndup",
	"strnlen",
	"strpbrk",
	"strrchr",
	"strsep",
	"strspn",
	"strstr",
	"strtod_l",
	"strtod",
	"strtof_l",
	"strtof",
	"strtof128_l",
	"strtof128",
	"strtof32_l",
	"strtof32",
	"strtof32x_l",
	"strtof32x",
	"strtof64_l",
	"strtof64",
	"strtof64x_l",
	"strtof64x",
	"strtoimax",
	"strtok_r",
	"strtol_l",
	"strtol",
	"strtold_l",
	"strtold",
	"strtoll_l",
	"strtoll",
	"strtoq",
	"strtoul_l",
	"strtoul",
	"strtoull_l",
	"strtoull",
	"strtoumax",
	"strtouq",
	"strxfrm",
	"sulp",
	"swprintf",
	"symlink",
	"syscall",
	"sysconf",
	"sysinfo",
	"sysmalloc_mmap_fallback.constprop.0",
	"sysmalloc_mmap.constprop.0",
	"sysmalloc_mmap.isra.0",
	"sysmalloc",
	"systrim.constprop.0",
	"tcache_init.part.0",
	"tcgetattr",
	"tcsetpgrp",
	"tdelete",
	"tdestroy_recurse",
	"tdestroy",
	"tfind",
	"Thread.Mutex.lock",
	"Thread.Mutex.unlock",
	"towctrans",
	"towlower",
	"towupper",
	"transcmp",
	"trecurse_r",
	"trecurse",
	"tsearch",
	"tunable_initialize",
	"twalk_r",
	"twalk",
	"two_way_long_needle",
	"tzset",
	"ULtox",
	"uname",
	"ungetc",
	"unlink_chunk.constprop.0",
	"unlink_chunk.isra.0",
	"unlink",
	"unlinkat",
	"unsetenv",
	"unwind_cleanup",
	"unwind_stop",
	"utimensat",
	"uw_frame_state_for",
	"uw_init_context_1",
	"uw_install_context_1",
	"uw_update_context_1",
	"uw_update_context",
	"valloc",
	"vasprintf",
	"version_lock_lock_exclusive",
	"version_lock_unlock_exclusive",
	"vfiprintf",
	"vfprintf",
	"vsnprintf",
	"vsprintf",
	"wait_on_socket",
	"wait4",
	"waitid",
	"waitpid",
	"wcrtomb",
	"wcschrnul",
	"wcscmp",
	"wcscoll",
	"wcscpy",
	"wcsftime_l",
	"wcsftime",
	"wcslcpy",
	"wcslen",
	"wcsnlen",
	"wcsrtombs",
	"wcstoul_l",
	"wcstoul",
	"wcsxfrm",
	"wctob",
	"wctrans",
	"wctype",
	"wcvt",
	"with_errnof",
	"wmemchr",
	"wmemcmp",
	"wmemcpy",
	"wmemmove",
	"wmempcpy",
	"wmemset",
	"write",
	"writev",
	"xflowf",
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
	// Begins with "pthread_"
	if (function.size() >= 8 && std::memcmp(function.data(), "pthread_", 8) == 0) {
		return true;
	}


	return false;
}

static Variant::Type convert_guest_type_to_variant(const String &type) {
	if (type == "bool") {
		return Variant::BOOL;
	} else if (type == "int" || type == "int32_t" || type == "int64_t" || type == "uint32_t" || type == "uint64_t" || type == "long" || type == "unsigned") {
		return Variant::INT;
	} else if (type == "float" || type == "double") {
		return Variant::FLOAT;
	} else if (type == "String" || type == "StringName") {
		return Variant::STRING;
	} else if (type == "Vector2") {
		return Variant::VECTOR2;
	} else if (type == "Vector3") {
		return Variant::VECTOR3;
	} else if (type == "Vector4") {
		return Variant::VECTOR4;
	} else if (type == "Vector2i") {
		return Variant::VECTOR2I;
	} else if (type == "Vector3i") {
		return Variant::VECTOR3I;
	} else if (type == "Vector4i") {
		return Variant::VECTOR4I;
	} else if (type == "Rect2") {
		return Variant::RECT2;
	} else if (type == "Rect2i") {
		return Variant::RECT2I;
	} else if (type == "Transform2D") {
		return Variant::TRANSFORM2D;
	} else if (type == "Plane") {
		return Variant::PLANE;
	} else if (type == "Quaternion") {
		return Variant::QUATERNION;
	} else if (type == "AABB") {
		return Variant::AABB;
	} else if (type == "Basis") {
		return Variant::BASIS;
	} else if (type == "Transform3D") {
		return Variant::TRANSFORM3D;
	} else if (type == "Color") {
		return Variant::COLOR;
	} else if (type == "NodePath") {
		return Variant::NODE_PATH;
	} else if (type == "RID") {
		return Variant::RID;
	} else if (type == "Object" || type == "Node" || type == "Node2D" || type == "Node3D") {
		return Variant::OBJECT;
	} else if (type == "Dictionary") {
		return Variant::DICTIONARY;
	} else if (type == "Array") {
		return Variant::ARRAY;
	} else if (type == "Callable") {
		return Variant::CALLABLE;
	} else if (type == "Signal") {
		return Variant::SIGNAL;
	} else if (type == "PackedByteArray") {
		return Variant::PACKED_BYTE_ARRAY;
	} else if (type == "PackedInt32Array") {
		return Variant::PACKED_INT32_ARRAY;
	} else if (type == "PackedInt64Array") {
		return Variant::PACKED_INT64_ARRAY;
	} else if (type == "PackedFloat32Array") {
		return Variant::PACKED_FLOAT32_ARRAY;
	} else if (type == "PackedFloat64Array") {
		return Variant::PACKED_FLOAT64_ARRAY;
	} else if (type == "PackedStringArray") {
		return Variant::PACKED_STRING_ARRAY;
	} else if (type == "PackedVector2Array") {
		return Variant::PACKED_VECTOR2_ARRAY;
	} else if (type == "PackedVector3Array") {
		return Variant::PACKED_VECTOR3_ARRAY;
	} else if (type == "PackedVector4Array") {
		return Variant::PACKED_VECTOR4_ARRAY;
	} else if (type == "PackedColorArray") {
		return Variant::PACKED_COLOR_ARRAY;
	}
	return Variant::NIL;
}

Array Sandbox::get_public_api_functions() const {
	TypedArray<Dictionary> result;
	try {
		gaddr_t public_api_addr = machine().address_of("public_api");
		if (public_api_addr != 0x0) {
			// Get the public API from this address instead of the symbol table.
			// It's an array of structs, ending with a null pointer.
			struct PublicAPI {
				gaddr_t name;
				gaddr_t address;
				gaddr_t description;
				gaddr_t return_type;
				gaddr_t args; // Comma-separated list of argument names and types.
			};

			// View up to 32 public functions, however we will stop at the first null pointer.
			static constexpr size_t MAX_PAPI = 32;
			const PublicAPI *api = machine().memory.memarray<PublicAPI>(public_api_addr, MAX_PAPI);
			for (size_t i = 0; i < MAX_PAPI; i++) {
				const PublicAPI &entry = api[i];
				if (entry.name == 0x0) {
					break;
				}
				std::string_view name = machine().memory.memstring_view(entry.name);
				if (name.empty() || name.size() > 64 || entry.address == 0x0) {
					ERR_PRINT("Sandbox: Invalid public API address.");
					return result;
				}
				Dictionary func;
				String godot_name = String::utf8(name.begin(), name.size());
				func["name"] = godot_name;
				func["address"] = entry.address;
				func["flags"] = METHOD_FLAG_NORMAL;

				Dictionary return_value;
				if (entry.return_type != 0x0) {
					std::string_view return_type = machine().memory.memstring_view(entry.return_type);
					return_value["type"] = convert_guest_type_to_variant(String::utf8(return_type.begin(), return_type.size()));
				} else {
					return_value["type"] = Variant::NIL;
				}
				func["return"] = std::move(return_value);

				if (entry.description != 0x0) {
					std::string_view description = machine().memory.memstring_view(entry.description);
					func["description"] = String::utf8(description.begin(), description.size());
				}

				TypedArray<Dictionary> args;
				if (entry.args != 0x0) {
					std::string_view arg_list = machine().memory.memstring_view(entry.args);
					PackedStringArray arg_names = String::utf8(arg_list.begin(), arg_list.size()).split(", ");
					PackedStringArray arg_name_and_type;
					for (const String &arg : arg_names) {
						arg_name_and_type.clear();
						arg_name_and_type = arg.split(" ");
						// Convert the argument name and type to a dictionary.
						String arg_name = arg_name_and_type[0];
						String arg_type = "Variant";
						if (arg_name_and_type.size() > 1) {
							arg_type = arg_name_and_type[0];
							arg_name = arg_name_and_type[1];
						}

						Dictionary argument;
						argument["name"] = arg_name;
						argument["type"] = convert_guest_type_to_variant(arg_type);
						argument["class_name"] = "Variant";
						argument["usage"] = PROPERTY_USAGE_NIL_IS_VARIANT;

						args.append(std::move(argument));
					}
				} else {
					ERR_PRINT("Sandbox: Invalid function arguments.");
				}

				func["args"] = std::move(args);
				result.append(std::move(func));

				// Since this public function was accepted, cache the address under the function name.
				this->m_lookup.insert_or_assign(godot_name.hash(), entry.address);
			}
		}
	} catch (const std::exception &e) {
		ERR_PRINT("Sandbox: Failed to get functions: " + String(e.what()));
	}
	return result;
}

PackedStringArray Sandbox::get_public_functions(const machine_t& machine) {
	PackedStringArray result;
	try {
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
				result.append(String::utf8(function.begin(), function.size()));
			}
		}
	} catch (const std::exception &e) {
		ERR_PRINT("Sandbox: Failed to get functions: " + String(e.what()));
	}
	return result;
}

Array Sandbox::get_functions() const {
	// Check if the guest program has a public API.
	Array result = this->get_public_api_functions();
	if (!result.is_empty()) {
		return result;
	}
	// Otherwise, get all public functions from the symbol table.
	return this->get_public_functions(machine());
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

		result.functions = Sandbox::get_public_functions(machine);

	} catch (const std::exception &e) {
		ERR_PRINT("Failed to get functions from binary. " + String(e.what()));
	}
	return result;
}
