﻿// Copyright (c) Pandas Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#ifndef _RATHENA_CN_CONFIG_HPP_
#define _RATHENA_CN_CONFIG_HPP_

#include "renewal.hpp"
#include "packets.hpp"

#define Pandas

#ifdef Pandas
	#define Pandas_Basic
	#define Pandas_DatabaseIncrease
	#define Pandas_StructIncrease
	#define Pandas_BattleConfigure
	#define Pandas_FuncIncrease
	#define Pandas_CreativeWork
	#define Pandas_Speedup
	#define Pandas_Bugfix
	#define Pandas_Crashfix
	#define Pandas_ScriptEngine
	#define Pandas_Redeclaration
	#define Pandas_Cleanup
	#define Pandas_NpcEvent
	#define Pandas_Mapflags
	#define Pandas_AtCommands
	#define Pandas_ScriptCommands
	#define Pandas_ScriptResults
	#define Pandas_ScriptParams
#endif // Pandas

#ifndef GIT_BRANCH
	#define GIT_BRANCH ""
#endif // GIT_BRANCH

#ifndef GIT_HASH
	#define GIT_HASH ""
#endif // GIT_HASH

// ============================================================================
// 基础组 - Pandas_Basic
// ============================================================================

#ifdef Pandas_Basic
	// --------------------------------------
	// 定义 Pandas 的默认版本号
	// --------------------------------------
	// 在 Windows 环境下版本号优先以资源文件中的文件版本号为准 (获取失败才会使用此处的版本号)
	// 在 Linux 环境下版本号将直接使用此处定义的版本号
	// 
	// 约定:
	// - 版本号的末尾若带有 -dev 后缀则表示这是一个还未 Release 的开发中版本
	// - 在 Windows 环境下资源文件中定义的版本号最后一段如果为 1, 也表示这是一个开发中的版本
	// 
	// 例如:
	//   1.0.1.0
	//         ^ 此处第四段为 0 表示这是一个 1.0.1 的正式版本 (Release)
	//   1.0.2.1
	//         ^ 此处第四段为 1 表示这是一个 1.0.2 的开发版本 (develop)
	// 
	// 在 Windows 环境下, 程序启动时会根据第四段的值自动携带对应的版本后缀, 以便进行版本区分
	#define Pandas_Version "1.0.4.0"

	// 在启动时显示 Pandas 的 LOGO
	#define Pandas_Show_Logo

	// 在启动时显示 Pandas 的版本号
	#define Pandas_Show_Version

	// 是否启用 Google Breakpad 用于处理程序崩溃
	#define Pandas_Google_Breakpad

	// 是否启用 npc.cpp 中的自定义辅助函数
	#define Pandas_NpcHelper_CommonFunc

	// 是否启用 LGTM 建议的一些处理措施, 避免潜在风险
	#define Pandas_LGTM_Optimization
#endif // Pandas_Basic

// ============================================================================
// 数据库增强组 - Pandas_DatabaseIncrease
// ============================================================================

#ifdef Pandas_DatabaseIncrease
	// 是否启用 Pandas 的道具属性数据库 [Sola丶小克]
	// 类似 item_flag 数据库, 不过 rAthena 自己会不断扩充 flag 的定义
	// 为了避免未来可能存在的冲突, 直接创建一个新的数据库来存放对物品属性的自定义扩充
	#define Pandas_Database_ItemProperties

	// 是否启用魔物道具固定掉率数据库及其功能 [Sola丶小克]
	// 通过这个数据库可以指定某个道具的全局固定掉落概率, 且能绕过等级惩罚和VIP掉率加成等机制
	#define Pandas_Database_MobItem_FixedRatio

	// 是否拓展 Yaml 的 Database 操作类使之能抑制错误信息 [Sola丶小克]
	#define Pandas_Database_Yaml_BeQuiet

	// 是否拓展 Yaml 的 Database 操作类使之能读取 UTF8-BOM 编码的文件 [Sola丶小克]
	#define Pandas_Database_Yaml_Support_UTF8BOM
#endif // Pandas_DatabaseIncrease

// ============================================================================
// 数据结构增强组 - Pandas_StructIncrease
// ============================================================================

#ifdef Pandas_StructIncrease
	// 使 item_data 可记录此物品是否为宠物捕捉道具 [Sola丶小克]
	// 结构体修改定位 itemdb.hpp -> item_data.taming_mobid
	#define Pandas_Struct_Item_Data_Taming_Mobid

	// 使 item_data 可记录此物品是否执行了 callfunc 指令 [Sola丶小克]
	// 结构体修改定位 itemdb.hpp -> item_data.has_callfunc
	#define Pandas_Struct_Item_Data_Has_CallFunc

	// 使 item_data 可记录此物品的特殊属性 [Sola丶小克]
	// 效果与 item_data.flag 类似, 只是数据源为 item_properties.yml 
	// 结构体修改定位 itemdb.hpp -> item_data.properties
	// 此选项开关需要依赖 Pandas_Database_ItemProperties 的拓展
	#ifdef Pandas_Database_ItemProperties
		#define Pandas_Struct_Item_Data_Properties
	#endif // Pandas_Database_ItemProperties

	// 使 map_session_data 有一个独立的结构体用来存放 Pandas 的拓展 [Sola丶小克]
	// 结构体修改定位 pc.hpp -> map_session_data.pandas
	#define Pandas_Struct_Map_Session_Data_Pandas

	// 以下选项开关需要依赖 Pandas_Struct_Map_Session_Data_Pandas 的拓展
	#ifdef Pandas_Struct_Map_Session_Data_Pandas
		// 使 map_session_data 可记录当前玩家正在处理哪一个脚本事件 [Sola丶小克]
		// 结构体修改定位 pc.hpp -> map_session_data.pandas.workinevent
		#define Pandas_Struct_Map_Session_Data_WorkInEvent

		// 使 map_session_data 可记录事件中断请求 [Sola丶小克]
		// 结构体修改定位 pc.hpp -> map_session_data.pandas.eventhalt
		#define Pandas_Struct_Map_Session_Data_EventHalt

		// 使 map_session_data 可记录事件触发请求 [Sola丶小克]
		// 结构体修改定位 pc.hpp -> map_session_data.pandas.eventtrigger
		#define Pandas_Struct_Map_Session_Data_EventTrigger

		// 使 map_session_data 可记录当前是否正在进行护身符能力计算 [Sola丶小克]
		// 结构体修改定位 pc.hpp -> map_session_data.pandas.amulet_calculating
		#define Pandas_Struct_Map_Session_Data_AmuletCalculating

		// 使 map_session_data 可记录即将支持捕捉的多个魔物编号 [Sola丶小克]
		#define Pandas_Struct_Map_Session_Data_MultiCatchTargetClass
	#endif // Pandas_Struct_Map_Session_Data_Pandas

	// 使 npc_data 有一个独立的结构体用来存放 Pandas 的拓展 [Sola丶小克]
	// 结构体修改定位 npc.hpp -> npc_data.pandas
	#define Pandas_Struct_Npc_Data_Pandas

	// 以下选项开关需要依赖 Pandas_Struct_Npc_Data_Pandas 的拓展
	#ifdef Pandas_Struct_Npc_Data_Pandas
		// 使 npc_data 结构体可记录此 npc 的自毁策略 [Sola丶小克]
		// 结构体修改定位 npc.hpp -> npc_data.pandas.destruction_strategy
		#define Pandas_Struct_Npc_Data_DestructionStrategy
	#endif // Pandas_Struct_Npc_Data_Pandas
#endif // Pandas_StructIncrease

// ============================================================================
// 战斗配置组 - Pandas_BattleConfigure
// ============================================================================

#ifdef Pandas_BattleConfigure
	// 是否支持对战斗配置选项进行完整性检查 [╰づ记忆•斑驳〤 实现] [Sola丶小克 改进]
	#define Pandas_BattleConfig_Verification

	// 是否启用 force_loadevent 配置选项及其功能 [Sola丶小克]
	// 此选项可以强制没有 loadevent 标记的地图也能触发 OnPCLoadMapEvent 事件
	#define Pandas_BattleConfig_Force_LoadEvent

	// 是否启用 force_identified 配置选项及其功能 [Sola丶小克]
	// 此选项可以强制特定渠道获得的装备自动变成已鉴定
	#define Pandas_BattleConfig_Force_Identified

	// 是否启用 cashmount_useitem_limit 配置选项及其功能 [Sola丶小克]
	// 此选项可以使乘坐“商城坐骑”时禁止使用特定类型的物品
	#define Pandas_BattleConfig_CashMounting_UseitemLimit

	// 是否启用 max_aspd_for_pvp 配置选项及其功能 [Sola丶小克]
	// 此选项用于限制玩家在 PVP 地图上的最大攻击速度 (以 MF_PVP 地图标记为准)
	#define Pandas_BattleConfig_MaxAspdForPVP

	// 是否启用 max_aspd_for_gvg 配置选项及其功能 [Sola丶小克]
	// 此选项用于限制玩家在 GVG 地图上的最大攻击速度 (以 MF_GVG/MF_GVG_TE 地图标记为准)
	#define Pandas_BattleConfig_MaxAspdForGVG

	// 是否启用 atcmd_no_permission 配置选项及其功能 [Sola丶小克]
	// 此选项用于指定没有指令权限的玩家, 在执行了管理员指令时的处理策略
	#define Pandas_BattleConfig_AtCmd_No_Permission
	// PYHELP - BATTLECONFIG - INSERT POINT - <Section 1>
#endif // Pandas_BattleConfigure

// ============================================================================
// 函数修改组 - Pandas_FuncIncrease
// ============================================================================

#ifdef Pandas_FuncIncrease
	// 在 pc.cpp 中的 pc_equipitem 增加 swapping 参数 [Sola丶小克]
	// 新增的 swapping 用于判断当前的装备穿戴调用是否由装备切换机制引发, 默认为 false
	#define Pandas_FuncParams_PC_EQUIPITEM

	// 调整 pc.cpp 中 pc_equipitem 执行道具绑定的时机 [Sola丶小克]
	#define Pandas_FuncLogic_PC_EQUIPITEM_BOUND_OPPORTUNITY

	// 调整 storage.cpp 中 storage_additem 的函数定义, 移除 static 关键字 [Sola丶小克]
	#define Pandas_FuncDefine_STORAGE_ADDITEM

	// 调整用于计算 MAX_INVENTORY 相关的变量
	// 以便能够支持将背包的最大上限设置成超过 128 的值 [Sola丶小克]
	// 
	// 提示: 根据目前的 struct item 和 struct s_storage 的体积情况,
	// 应该可支持将 MAX_INVENTORY 调整到 800 左右, 但设置越大对性能影响会越大
	#define Pandas_FuncExtend_Increase_Inventory

	// 调整 atcommand.cpp 中 atcommand_reload 配置重载指令的逻辑 [Sola丶小克]
	// 我们希望在执行某些 reload 指令 (@reloadbattleconf) 时能重新计算全服玩家的属性和能力值
	#define Pandas_FuncLogic_ATCOMMAND_RELOAD
#endif // Pandas_FuncIncrease

// ============================================================================
// 原创功能组 - Pandas_CreativeWork
// ============================================================================

#ifdef Pandas_CreativeWork
	// 以下选项开关需要依赖 Pandas_Database_Yaml_BeQuiet 的拓展
	#ifdef Pandas_Database_Yaml_BeQuiet
		// 是否启用终端控制台的信息翻译机制 [Sola丶小克]
		#define Pandas_Console_Translate
	#endif // Pandas_Database_Yaml_BeQuiet

	// 扩展信息配置文件 (Msg_conf) 的 ID 最大上限,
	// 同时提供 msg_txt_cn 宏定义函数, 方便在工程中使用自定义信息 [Sola丶小克]
	#define Pandas_Message_Conf

	// 对消息文件进行清理, 移除几乎用不到的其他国家语言
	// 主要留下: 英文, 简体中文, 繁体中文 这三种. [Sola丶小克]
	#define Pandas_Message_Reorganize

	// 将部分硬编码的字符串提取到消息文件中 [Sola丶小克]
	// 这么做的主要目的是在有需要的时候, 可以将内容进行汉化或者其他处理
	#define Pandas_Message_Hardcode_Extract

	// 是否支持在 map_athena.conf 中设定封包混淆密钥 [Sola丶小克]
	#ifdef PACKET_OBFUSCATION
		#define Pandas_Support_Specify_PacketKeys
	#endif // PACKET_OBFUSCATION

	// 是否支持读取 UTF8-BOM 编码的 libconfig 配置文件 [Sola丶小克]
	#define Pandas_Support_Read_UTF8BOM_Configure

	// 在使用 _M/_F 注册的时候, 能够限制使用中文等字符作为游戏账号 [Sola丶小克]
	// 这里的 PCRE_SUPPORT 在"项目属性 -> C/C++ -> 预处理器"中定义
	#ifdef PCRE_SUPPORT
		#define Pandas_Strict_Userid_Verification
	#endif // PCRE_SUPPORT

	// 是否支持隐藏角色服务器的在线人数 [Sola丶小克]
	#define Pandas_Support_Hide_Online_Players_Count

	// 是否扩展魔物名称能展现的信息, 比如体型、种族、属性 [Sola丶小克 改进]
	#define Pandas_MobInfomation_Extend

	// 是否加强 2013-12-23 以及 2013-08-07 客户端的混淆密钥 [Sola丶小克]
	#define Pandas_Packet_Obfuscation_Keys

	// 使影子装备可以支持插卡, 而不会被强制转换成普通道具 [Sola丶小克]
	#define Pandas_Shadowgear_Support_Card

	// 以下选项依赖 Pandas_Struct_Item_Data_Properties 的拓展
	#ifdef Pandas_Struct_Item_Data_Properties
		// 启用道具特殊属性的部分生效代码 [Sola丶小克]
		// 此选项开启后 (item_properties.yml) 数据库中以下选项才能发挥作用:
		// 
		// Property 节点的 &1 = 避免物品被玩家主动使用而消耗
		// Property 节点的 &2 = 避免物品被作为发动技能的必要道具而消耗
		#define Pandas_Item_Properties

		// 是否启用护身符系统 [Sola丶小克]
		// 此选项开启后 (item_properties.yml) 数据库中以下选项才能发挥作用:
		// 
		// Property 节点的 &4 = 该道具为护身符道具
		#define Pandas_Item_Amulet_System

		// 是否启用道具外观控制机制 [Sola丶小克]
		// 此选项开启后 (item_properties.yml) 数据库中以下选项才能发挥作用:
		//
		// ControlViewID 节点中的 InvisibleWhenISee 子节点
		// ControlViewID 节点中的 InvisibleWhenTheySee 子节点
		#define Pandas_Item_ControlViewID

		// 是否启用特殊的道具掉落公告规则 [Sola丶小克]
		// 此选项开启后 (item_properties.yml) 数据库中以下选项才能发挥作用:
		// 
		// AnnouceRules 节点的 &1 - 打死魔物, 魔物将道具掉落到地上时公告
		// AnnouceRules 节点的 &2 - 打死魔物, 掉落 MVP 奖励到玩家的背包时公告
		// AnnouceRules 节点的 &4 - 使用"偷窃"技能, 从魔物身上偷到物品时公告
		#define Pandas_Item_Special_Annouce
	#endif // Pandas_Struct_Item_Data_Properties

	// 使 pointshop 类型的商店能支持指定变量别名, 用于展现给玩家 [Sola丶小克]
	#define Pandas_Support_Pointshop_Variable_DisplayName

	// 检测 import 目录是否存在, 若不存在能够从 import-tmpl 复制一份 [Sola丶小克]
	#define Pandas_Deploy_Import_Directories

	// 是否对数据库配置相关的一系列逻辑进行优化 [Sola丶小克]
	// 
	// 目前主要包括以下几个改动:
	// 
	// --------------------------------------
	// 改动一：重新整理 inter_athena.conf 中对各个 codepage 选项的定义
	// --------------------------------------
	// 
	// 在 rAthena 原始的代码中:
	// 
	//     char_server_db 和 map_server_db 通过 default_codepage 选项控制编码
	//     而其他的 login_server_db, ipban_db_db, log_db_db 则各自有自己的 codepage 设置项
	//     且后面这几个数据库连接时, 并不尊重 default_codepage 选项.
	//     
	//     这样其实对于无法查看代码的用户而言非常容易混淆, 因为 default_codepage 选项并不总是 default
	//     为此我们进行了一些调整, 让它看起来更加合理.
	//
	// 调整之后各个选项的逻辑如下:
	// 
	//     我们为 char_server_db 和 map_server_db 也分配自己的 codepage 设置项.
	//     当各个连接的 codepage 设置项为空的时候, 则默认使用 default_codepage 选项的值作为默认编码.
	// 
	// --------------------------------------
	// 改动二：使用数据库编码自动判定机制
	// --------------------------------------
	//
	// 与数据库建立连接时, 如果配置的 codepage 等于 auto, 那么会根据特定规则自动选择编码
	// 
	// 调整的细节需求点如下所示:
	// 
	// - 能够输出目标数据库当前所使用的编码
	// - 当在 inter_athena.conf 中指定了 codepage 时, 能提示最终使用的编码
	// - 若目标数据库使用 utf8 或者 utf8mb4 编码则会给与提示
	// - 若目标数据库使用 utf8 或者 utf8mb4 编码, 为了兼容性考虑会根据操作
	//   系统语言来选择使用 gbk 或 big5 编码, 若不是简体中文也不是繁体中文则直接
    //   使用当前数据库的 `character_set_database` 编码.
	//
	// --------------------------------------
	// 改动三：用 mysql_set_character_set 来设置 MySQL 的编码字符集
	// --------------------------------------
	#define Pandas_SQL_Configure_Optimization

	// 是否启用一列用于控制角色称号的指令、事件等等 [Sola丶小克]
	#define Pandas_Character_Title_Controller

	#ifndef _WIN32
		// 在 Linux 环境下输出信息时, 能转换成终端自适应编码 [Sola丶小克]
		// 目前能够比较好的自适应 UTF-8, GBK, BIG5 编码
		#define Pandas_Console_Charset_SmartConvert
	#endif // _WIN32

	// 是否简单实现队长用于销毁副本的"面板按钮"功能 [Sola丶小克]
	// 目前仅在 2018-06-20 版本中测试过, 启用此开关将实现 0x02cf 封包的处理
	#define Pandas_Quick_Implement_Dungeon_Command
#endif // Pandas_CreativeWork

// ============================================================================
// 优化加速组 - Pandas_Speedup
// ============================================================================

#ifdef Pandas_Speedup
	// 是否优化 itemdb_searchname1 函数的实现方式 [Sola丶小克]
	// 在默认情况下 rAthena 的 itemdb_searchname1 函数实现的非常低效
	// 在 VS2019 编译环境下, 优化后的检索物品名称的性能提高大约 38 倍 (Release 模式)
	#define Pandas_Speedup_Itemdb_SearchName
#endif // Pandas_Speedup

// ============================================================================
// 官方BUG修正组 - Pandas_Bugfix
// ============================================================================

#ifdef Pandas_Bugfix
	// 修复 rAthena 部分空指针检测遗漏或者类似的崩溃错误 [Sola丶小克]
	// 程序内部大量使用 nullpo.cpp 中的系列函数来判定空指针并采取一些措施,
	// 但是这个方法只在 Debug 模式下可以成功拦截空指针并输出报错信息.
	// 在 Release 模式下, 有一些检测不够严格的地方会导致程序直接崩溃, 这是我们不想见到的
	#define Pandas_Fix_NullPtr_Protect

	// 修正在部分情况下角色公会图标刷新不及时的问题 [Sola丶小克]
	#define Pandas_Fix_GuildEmblem_Update

	// 修正部分简体、繁体中文字符作为角色名时, 会被变成问号的问题 [Sola丶小克]
	// 例如: "凯撒"中的"凯"字, "聽風"中的"聽"字等
	#define Pandas_Fix_Chinese_Character_Trimmed

	// 修复 item_trade 中限制物品掉落后, 权限足够的 GM 也无法绕过限制的问题 [Sola丶小克]
	#define Pandas_Fix_Item_Trade_FloorDropable

	// 修正使用 duplicate 或 copynpc 复制商店类型的 NPC 时, 由于没有完整的复制出售的商品列表, 
	// 导致使用 npcshop* 系列指令调整复制后的商店内容时, 原商店的内容也会同步受到影响的问题. 
	// 目前根据各位脚本大神的反馈, 更希望各个商店 NPC 的商品列表内容是各自独立的 [Sola丶小克]
	#define Pandas_Fix_Duplicate_Shop_With_FullyShopItemList

	// 修正复制商店类型的 NPC 时, 打折设置及货币变量等参数没有一起复制的问题 [Sola丶小克]
	#define Pandas_Fix_Duplicate_Shop_Parameters_Missing

	// 修正使用 pointshop 类型的商店操作 #CASHPOINTS 或 #KAFRAPOINTS 变量完成最终的货币结算后
	// 小地图旁边的"道具商城"按钮中的金额不被更新, 最终导致双花的问题 [Sola丶小克]
	#define Pandas_Fix_PointShop_Double_Spend_Attack

	// 修正 npc_unloadfile 和 npc_parsesrcfile 的行为会被空格影响的问题 [Sola丶小克]
	// 如果 @reloadnpc 时给定的路径带空格, 系统将无法正确的 unloadnpc, 导致 npc 重复出现
	#define Pandas_Fix_NPC_Filepath_WhiteSpace_Effects

	// 修正关闭个人仓库和付费仓库时, 进行保存操作后 dirty 标记未被重置的问题 [Sola丶小克]
	// 会导致每次关闭仓库时哪怕没有增删改仓库里面的道具, 也会触发仓库内容全量保存.
	// 不做修正的话, 当出现大量关闭仓库请求且仓库容量比较大时, 对服务器性能会有些影响.
	#define Pandas_Fix_Storage_DirtyFlag_Miss_Reset

	// 修正 skill_db.yml 的 ItemCost 字段指定的 Item 道具不存在时
	// 会导致地图服务器直接崩溃的问题. 看代码应该是 rAthena 的工程师手误了 [Sola丶小克]
	#define Pandas_Fix_SkillDB_ItemCost_NoexistsItem_Crash

	// 修正 pet_db.yml 存在多个携带脚本的相同魔物记录时会触发内存泄露的问题 [Sola丶小克]
	// 例如: 有两条 PORING 记录, 都同时指定了 SupportScript 或 Script 节点,
	// 按照 import 逻辑定义在尾部的数据将覆盖前者, 但当后者覆盖前者的 SupportScript 或
	// Script 时, 会忘记释放之前申请的内存. 导致退出地图服务器时提示内存泄露.
	#define Pandas_Fix_PetDB_Script_Memory_Leaks
#endif // Pandas_Bugfix

// ============================================================================
// 官方崩溃修正组 - Pandas_Crashfix
// ============================================================================

#ifdef Pandas_Crashfix
	// 修复使用 sommon 脚本指令召唤不存在的魔物, 会导致地图服务器崩溃的问题 [Sola丶小克]
	#define Pandas_Crashfix_ScriptCommand_Summon

	// 修复使用 getd 操作的变量名存在空格开头时,
	// 若 getd 的结果直接作为参数传入其他脚本指令, 会导致地图服务器崩溃的问题 [Sola丶小克]
	//
	// 重现方法:
	// 使 NPC 调用 .@result = inarray(getd(" $test"), 100); 即可触发崩溃
	#define Pandas_Crashfix_ScriptCommand_Getd_And_Setd

	// 修正 Visual Studio 2019 的 16.3 在支持 AVX512 指令集的设备上
	// 使用 std::unordered_map::reserve 会提示 Illegal instruction 并导致地图服务器崩溃的问题.
	// 
	// 虽然根据微软的回复已经在 Visual Studio 2019 的 16.4 Preview 4 中解决了问题,
	// 考虑部分用户可能会一直停留在存在问题的编译器上工作, 因此做一个热修复.
	//
	// 此修复只对 _MSC_VER == 1923 的 Visual Studio 编译器有效 (对应 Visual Studio 2019 16.3 版本)
	// https://developercommunity.visualstudio.com/content/problem/787296/vs2019-163-seems-to-incorrectly-detect-avx512-on-w.html
	//
	// 感谢"李小狼"在阿里云服务器上暴露此问题, 并提供调试环境
	#define Pandas_Crashfix_VisualStudio_UnorderedMap_AVX512

	// 修正在 NPC 事件脚本代码中执行 unloadnpc 会导致地图服务器崩溃的问题 [Sola丶小克]
	// unloadnpc 的时候会重新构造 script_event 这个 std::map 的内容
	// 这会导致 npc_script_event 中提前获取的 vector 引用所指向的内容被清空,
	// 以至于在执行下一轮循环的时候, 无法获取已经被清空的原 script_event 内容, 而触发崩溃
	//
	// 感谢"聽風"指出重现此问题的条件和环境
	#define Pandas_Crashfix_Unloadnpc_In_Event
#endif // Pandas_Crashfix

// ============================================================================
// 脚本引擎修改组 - Pandas_ScriptEngine
// ============================================================================

#ifdef Pandas_ScriptEngine
	// 使脚本引擎能够支持穿越事件队列机制, 直接执行某些事件 [Sola丶小克]
	#define Pandas_ScriptEngine_Express

	// 使脚本引擎能够支持备份无数个脚本堆栈 [Sola丶小克]
	// 以此避免嵌套调用超过两层的脚本会导致程序崩溃的问题 (如: script4each -> getitem -> 成就系统)
	#define Pandas_ScriptEngine_MutliStackBackup

	// 脚本语法验证时能够考虑双字节字符与转义序列的关系 [Sola丶小克]
	// 
	// rAthena 在大部分情况下可以正常工作, 除了中文紧挨着待转义的双引号这种情况:
	// script4eachmob "{ unittalk $@gid, \"中文紧挨着待转义的双引号无法通过语法检测\"; }", 0;
	//
	// ASCII码表: https://baike.baidu.com/item/ASCII
	// 若一个字符对应的字节编码 <= 0x7e 那么说明它在 ASCII 编码范围
	// 
	// rAthena 在最原始的判断中, 只判断了 p 不作为双字节字符的低位出现, 就认为 p 是独立的反斜杠
	// 注意: 但部分 GBK 的中文的低位, 若紧挨着 \ 就会导致 rAthena 的方法出现误判.
	// 
	// 例如: [文] 这个字符在 GBK 的编码是 0xCDC4
	// 若编写的时候出现这样的情况: "\"中文\"" 我们预期输出的就是 "中文"
	// 但这里我们重点看下 [文\] 这两个字符挨在一起的时候, 它们的十六进制是: 0xCDC45C
	//
	// 此处的 0x5C 就是反斜杠的字符编码 (位于 ASCII 码表),
	// rAthena 的代码走到 p == 0x5C 的时候,
	// 判断一看 p[-1] 即 0xC4 <= 0x7E 不成立, 那么认为 p 是一个独立反斜杠
	// 
	// 但实际上此时的反斜杠和下一个字符的 " 构成的 \" 才是真正的一组转义序列,
	// 如果认为 p 是独立反斜杠, 那么 " 也将被独立, 不再成为转义序列的一部分. 从而提前关闭第一个双引号,
	// 原计划输出的 "中文" 输出将变成: "中文
	// 而最末末尾的 " 将被作为一个新的字符串起点, 导致语法检测双引号无法闭合而报错
	#define Pandas_ScriptEngine_DoubleByte_UnEscape_Detection
#endif // Pandas_ScriptEngine

// ============================================================================
// 重新声明组 - Pandas_Redeclaration
// ============================================================================

#ifdef Pandas_Redeclaration
	// 将 struct event_data 的定义从 npc.cpp 移动到 npc.hpp [Sola丶小克]
	#define Pandas_Redeclaration_Struct_Event_Data
#endif // Pandas_Redeclaration

// ============================================================================
// 无用代码清理组 - Pandas_Cleanup
// ============================================================================

#ifdef Pandas_Cleanup
	// 清理读取 sql.db_hostname 选项的相关代码 [Sola丶小克]
	// 
	// 在 rAthena 官方的代码中原本预留了一个数据库默认连接的配置组, 
	// 这些选项以 sql. 开头, 配置在 conf/inter_athena.conf 中的话就会被程序读取.
	// 但是整个服务端只有 login-server 会尝试去读取这个配置, 所以非常鸡肋.
	// 以至于目前 rAthena 在官方的 conf/inter_athena.conf 中都把相关配置删了.
	//
	// 所以熊猫表示, 我们也干脆删了吧!! Oh yeah!
	#define Pandas_Cleanup_Useless_SQL_Global_Configure
#endif // Pandas_Cleanup

// ============================================================================
// NPC事件组 - Pandas_NpcEvent
// ============================================================================

#ifdef Pandas_NpcEvent
	/************************************************************************/
	/* Filter 类型的过滤事件，这些事件可以被 processhalt 中断                    */
	/************************************************************************/

	#ifdef Pandas_Struct_Map_Session_Data_EventHalt
		// 当玩家在装备鉴定列表中选择好装备, 并点击“确定”按钮时触发过滤器 [Sola丶小克]
		// 事件类型: Filter / 事件名称: OnPCIdentifyFilter
		// 常量名称: NPCF_IDENTIFY / 变量名称: identify_filter_name
		#define Pandas_NpcFilter_IDENTIFY

		// 当玩家进入 NPC 开启的聊天室时触发过滤器 [Sola丶小克]
		// 事件类型: Filter / 事件名称: OnPCInChatroomFilter
		// 常量名称: NPCF_ENTERCHAT / 变量名称: enterchat_filter_name
		#define Pandas_NpcFilter_ENTERCHAT

		// 当玩家准备插入卡片时触发过滤器 [Sola丶小克]
		// 事件类型: Filter / 事件名称: OnPCInsertCardFilter
		// 常量名称: NPCF_INSERT_CARD / 变量名称: insert_card_filter_name
		#define Pandas_NpcFilter_INSERT_CARD

		// 当玩家准备使用非装备类道具时触发过滤器 [Sola丶小克]
		// 事件类型: Filter / 事件名称: OnPCUseItemFilter
		// 常量名称: NPCF_USE_ITEM / 变量名称: use_item_filter_name
		#define Pandas_NpcFilter_USE_ITEM

		// 当玩家准备使用技能时触发过滤器 [Sola丶小克]
		// 事件类型: Filter / 事件名称: OnPCUseSkillFilter
		// 常量名称: NPCF_USE_SKILL / 变量名称: use_skill_filter_name
		#define Pandas_NpcFilter_USE_SKILL

		// 当玩家准备打开乐透大转盘的时候触发过滤器 [Sola丶小克]
		// 事件类型: Filter / 事件名称: OnPCOpenRouletteFilter
		// 常量名称: NPCF_ROULETTE_OPEN / 变量名称: roulette_open_filter_name
		#define Pandas_NpcFilter_ROULETTE_OPEN

		// 当玩家准备查看某个角色的装备时触发过滤器 [Sola丶小克]
		// 事件类型: Filter / 事件名称: OnPCViewEquipFilter
		// 常量名称: NPCF_VIEW_EQUIP / 变量名称: view_equip_filter_name
		#define Pandas_NpcFilter_VIEW_EQUIP

		// 当玩家准备穿戴装备时触发过滤器 [Sola丶小克]
		// 事件类型: Filter / 事件名称: OnPCEquipFilter
		// 常量名称: NPCF_EQUIP / 变量名称: equip_filter_name
		#define Pandas_NpcFilter_EQUIP

		// 当玩家准备脱下装备时触发过滤器 [Sola丶小克]
		// 事件类型: Filter / 事件名称: OnPCUnequipFilter
		// 常量名称: NPCF_UNEQUIP / 变量名称: unequip_filter_name
		#define Pandas_NpcFilter_UNEQUIP

#ifdef Pandas_Character_Title_Controller
		// 当玩家试图变更称号时将触发此过滤器 [Sola丶小克]
		// 事件类型: Filter / 事件名称: OnPCChangeTitleFilter
		// 常量名称: NPCF_CHANGETITLE / 变量名称: changetitle_filter_name
		#define Pandas_NpcFilter_CHANGETITLE
#endif // Pandas_Character_Title_Controller
		// PYHELP - NPCEVENT - INSERT POINT - <Section 1>
	#endif // Pandas_Struct_Map_Session_Data_EventHalt

	/************************************************************************/
	/* Event  类型的标准事件，这些事件不能被 processhalt 打断                    */
	/************************************************************************/

	// 当玩家杀死 MVP 魔物后触发事件 [Sola丶小克]
	// 事件类型: Event / 事件名称: OnPCKillMvpEvent
	// 常量名称: NPCE_KILLMVP / 变量名称: killmvp_event_name
	#define Pandas_NpcEvent_KILLMVP

	// 当玩家成功鉴定了装备时触发事件 [Sola丶小克]
	// 事件类型: Event / 事件名称: OnPCIdentifyEvent
	// 常量名称: NPCE_IDENTIFY / 变量名称: identify_event_name
	#define Pandas_NpcEvent_IDENTIFY

	// 当玩家成功插入卡片后触发事件 [Sola丶小克]
	// 事件类型: Event / 事件名称: OnPCInsertCardEvent
	// 常量名称: NPCE_INSERT_CARD / 变量名称: insert_card_event_name
	#define Pandas_NpcEvent_INSERT_CARD

	// 当玩家成功使用非装备类道具后触发事件 [Sola丶小克]
	// 事件类型: Event / 事件名称: OnPCUseItemEvent
	// 常量名称: NPCE_USE_ITEM / 变量名称: use_item_event_name
	#define Pandas_NpcEvent_USE_ITEM

	// 当玩家成功使用技能后触发事件 [Sola丶小克]
	// 事件类型: Event / 事件名称: OnPCUseSkillEvent
	// 常量名称: NPCE_USE_SKILL / 变量名称: use_skill_event_name
	#define Pandas_NpcEvent_USE_SKILL

	// 当玩家的进度条被打断后触发事件 [Sola丶小克]
	// 事件类型: Event / 事件名称: OnPCProgressAbortEvent
	// 常量名称: NPCE_PROGRESS_ABORT / 变量名称: progressbar_abort_event_name
	#define Pandas_NpcEvent_PROGRESS_ABORT

	// 当玩家成功穿戴一件装备时触发事件 [Sola丶小克]
	// 事件类型: Event / 事件名称: OnPCEquipEvent
	// 常量名称: NPCE_EQUIP / 变量名称: equip_event_name
	#define Pandas_NpcEvent_EQUIP

	// 当玩家成功脱下一件装备时触发事件 [Sola丶小克]
	// 事件类型: Event / 事件名称: OnPCUnequipEvent
	// 常量名称: NPCE_UNEQUIP / 变量名称: unequip_event_name
	#define Pandas_NpcEvent_UNEQUIP
	// PYHELP - NPCEVENT - INSERT POINT - <Section 7>

	/************************************************************************/
	/* Express 类型的快速事件，这些事件将会被立刻执行, 不进事件队列                */
	/************************************************************************/

	#ifdef Pandas_ScriptEngine_Express
		// PYHELP - NPCEVENT - INSERT POINT - <Section 13>
	#endif // Pandas_ScriptEngine_Express
	
#endif // Pandas_NpcEvent

// ============================================================================
// 地图标记组 - Pandas_Mapflags
// ============================================================================

#ifdef Pandas_Mapflags
	// 是否启用 mobinfo 地图标记 [Sola丶小克]
	// 该标记用于指定某地图的 show_mob_info 值, 以此控制该地图魔物名称的展现信息
	#define Pandas_MapFlag_Mobinfo

	// 是否启用 noautoloot 地图标记 [Sola丶小克]
	// 该标记用于在给定此标记的地图上禁止玩家使用自动拾取功能, 或使已激活的自动拾取功能失效
	#define Pandas_MapFlag_NoAutoLoot

	// 是否启用 notoken 地图标记 [Sola丶小克]
	// 该标记用于禁止玩家在指定的地图上使用“原地复活之证”道具
	#define Pandas_MapFlag_NoToken

	// 是否启用 nocapture 地图标记 [Sola丶小克]
	// 该标记用于禁止玩家在地图上使用宠物捕捉道具或贤者的"随机技能"来捕捉宠物
	// 此地图标记依赖 Pandas_Struct_Item_Data_Taming_Mobid 的拓展
	#ifdef Pandas_Struct_Item_Data_Taming_Mobid
		#define Pandas_MapFlag_NoCapture
	#endif // Pandas_Struct_Item_Data_Taming_Mobid

	// 是否启用 hideguildinfo 地图标记 [Sola丶小克]
	// 使当前地图上的玩家无法见到其他人的公会图标、公会名称、职位等信息 (自己依然可见)
	#define Pandas_MapFlag_HideGuildInfo

	// 是否启用 hidepartyinfo 地图标记 [Sola丶小克]
	// 使当前地图上的玩家无法见到其他人的队伍名称 (自己依然可见)
	#define Pandas_MapFlag_HidePartyInfo

	// 是否启用 nomail 地图标记 [Sola丶小克]
	// 该标记用于禁止玩家在地图上打开邮件界面或进行邮件系统的相关操作
	#define Pandas_MapFlag_NoMail

	// 是否启用 nopet 地图标记 [维护者昵称]
	// TODO: 请在此填写此地图标记的说明
	#define Pandas_MapFlag_NoPet

	// 是否启用 nohomun 地图标记 [维护者昵称]
	// TODO: 请在此填写此地图标记的说明
	#define Pandas_MapFlag_NoHomun

	// 是否启用 nomerc 地图标记 [维护者昵称]
	// TODO: 请在此填写此地图标记的说明
	#define Pandas_MapFlag_NoMerc

	// 是否启用 mobdroprate 地图标记 [Sola丶小克]
	// 该标记用于额外调整此地图上普通魔物的物品掉落倍率
	#define Pandas_MapFlag_MobDroprate

	// 是否启用 mvpdroprate 地图标记 [Sola丶小克]
	// 该标记用于额外调整此地图上 MVP 魔物的物品掉落倍率
	#define Pandas_MapFlag_MvpDroprate

	// 是否启用 maxheal 地图标记 [Sola丶小克]
	// 该标记用于限制此地图上单位的治愈系技能最大的 HP 治愈量
	#define Pandas_MapFlag_MaxHeal

	// 是否启用 maxdmg_skill 地图标记 [Sola丶小克]
	// 该标记用于限制此地图上单位的最大技能伤害 (不含治愈系技能)
	#define Pandas_MapFlag_MaxDmg_Skill

	// 是否启用 maxdmg_normal 地图标记 [Sola丶小克]
	// 该标记用于限制此地图上单位的最大平砍伤害 (包括二刀连击和刺客拳刃平砍)
	#define Pandas_MapFlag_MaxDmg_Normal
	// PYHELP - MAPFLAG - INSERT POINT - <Section 1>
#endif // Pandas_Mapflags

// ============================================================================
// 管理员指令组 - Pandas_AtCommands
// ============================================================================

#ifdef Pandas_AtCommands
	// 是否启用 recallmap 管理员指令 [Sola丶小克]
	// 召唤当前(或指定)地图的玩家来到身边 (处于离线挂店模式的角色不会被召唤)
	#define Pandas_AtCommand_RecallMap

	// 是否启用 crashtest 管理员指令 [Sola丶小克]
	// 执行崩溃测试, 在比较严格的环境上故意触发地图服务器崩溃
	#define Pandas_AtCommand_Crashtest

	#ifdef Pandas_Character_Title_Controller
		// 是否启用 title 管理员指令 [Sola丶小克]
		// 给角色设置一个指定的称号ID, 客户端封包版本大于等于 20150513 才可用
		#define Pandas_AtCommand_Title
	#endif // Pandas_Character_Title_Controller
	// PYHELP - ATCMD - INSERT POINT - <Section 1>
#endif // Pandas_AtCommands

// ============================================================================
// 脚本指令组 - Pandas_ScriptCommands
// ============================================================================

#ifdef Pandas_ScriptCommands
	// 是否启用 setheaddir 脚本指令 [Sola丶小克]
	// 用于调整角色纸娃娃脑袋的朝向 (0 - 正前方; 1 - 向右看; 2 - 向左看)
	#define Pandas_ScriptCommand_SetHeadDir

	// 是否启用 setbodydir 脚本指令 [Sola丶小克]
	// 用于调整角色纸娃娃身体的朝向 (与 NPC 一致, 从 0 到 7 共 8 个方位可选择)
	#define Pandas_ScriptCommand_SetBodyDir

	// 是否启用 openbank 脚本指令 [Sola丶小克]
	// 让指定的角色立刻打开银行界面 (只对拥有随身银行的客户端版本有效)
	#define Pandas_ScriptCommand_OpenBank

	// 是否启用 instance_users 脚本指令 [Sola丶小克]
	// 获取指定的副本实例中已经进入副本地图的人数
	#define Pandas_ScriptCommand_InstanceUsers

	// 是否启用 cap 脚本指令 [Sola丶小克]
	// 确保数值不低于给定的最小值, 不超过给定的最大值
	#define Pandas_ScriptCommand_CapValue

	// 是否启用 mobremove 脚本指令 [Sola丶小克]
	// 根据 GID 移除一个魔物单位 (只是移除, 不会让魔物死亡)
	#define Pandas_ScriptCommand_MobRemove

	// 是否启用 mesclear 脚本指令 [Sola丶小克]
	// 由于 rAthena 已经实现 clear 指令, 这里兼容老版本 mesclear 指令
	#define Pandas_ScriptCommand_MesClear

	// 是否启用 battleignore 脚本指令 [Sola丶小克]
	// 将角色设置为魔物免战状态, 避免被魔物攻击 (与 GM 指令的 monsterignore 效果一致)
	#define Pandas_ScriptCommand_BattleIgnore

	// 是否启用 gethotkey 脚本指令 [Sola丶小克]
	// 获取指定快捷键位置当前的信息 (该指令有一个用于兼容的别名: get_hotkey)
	#define Pandas_ScriptCommand_GetHotkey

	// 是否启用 sethotkey 脚本指令 [Sola丶小克]
	// 设置指定快捷键位置的信息 (该指令有一个用于兼容的别名: set_hotkey)
	#define Pandas_ScriptCommand_SetHotkey

	// 是否启用 showvend 脚本指令 [Jian916]
	// 使指定的 NPC 头上可以显示露天商店的招牌, 点击招牌可触发与 NPC 的对话
	#define Pandas_ScriptCommand_ShowVend

	// 是否启用 viewequip 脚本指令 [Sola丶小克]
	// 使用该指令可以查看指定在线角色的装备面板信息 (注意: v2.0.0 以前是通过账号编号)
	#define Pandas_ScriptCommand_ViewEquip

	// 是否启用 countitemidx 脚本指令 [Sola丶小克]
	// 获取指定背包序号的道具在背包中的数量 (该指令有一个用于兼容的别名: countinventory)
	#define Pandas_ScriptCommand_CountItemIdx

	// 是否启用 delitemidx 脚本指令 [Sola丶小克]
	// 移除指定背包序号的道具, 其中数量参数可不填, 若不填则表示删除指定道具的全部
	#define Pandas_ScriptCommand_DelItemIdx

	// 是否启用 identifyidx 脚本指令 [Sola丶小克]
	// 鉴定指定背包序号的道具 (该指令有一个用于兼容的别名: identifybyidx)
	#define Pandas_ScriptCommand_IdentifyIdx

	// 是否启用 unequipidx 脚本指令 [Sola丶小克]
	// 脱下指定背包序号的道具 (该指令有一个用于兼容的别名: unequipinventory)
	#define Pandas_ScriptCommand_UnEquipIdx

	// 是否启用 equipidx 脚本指令 [Sola丶小克]
	// 穿戴指定背包序号的道具 (该指令有一个用于兼容的别名: equipinventory)
	#define Pandas_ScriptCommand_EquipIdx

	// 是否启用 itemexists 脚本指令 [Sola丶小克]
	// 确认物品数据库中是否存在指定物品 (该指令有一个用于兼容的别名: existitem)
	#define Pandas_ScriptCommand_ItemExists

	// 是否启用 renttime 脚本指令 [Sola丶小克]
	// 增加/减少指定位置装备的租赁时间 (该指令有一个用于兼容的别名: resume)
	#define Pandas_ScriptCommand_RentTime

	// 是否启用 getequipidx 脚本指令 [Sola丶小克]
	// 获取指定位置装备的背包序号
	#define Pandas_ScriptCommand_GetEquipIdx

	// 是否启用 statuscalc 脚本指令 [Sola丶小克]
	// 由于 rAthena 已经实现 recalculatestat 指令, 这里兼容老版本 statuscalc 指令
	#define Pandas_ScriptCommand_StatusCalc

	// 是否启用 getequipexpiretick 脚本指令 [Sola丶小克]
	// 获取指定位置装备的租赁到期剩余秒数 (该指令有一个用于兼容的别名: isrental)
	#define Pandas_ScriptCommand_GetEquipExpireTick

	// 是否启用 getinventoryinfo 脚本指令 [Sola丶小克]
	// 查询指定背包序号的道具的详细信息
	#define Pandas_ScriptCommand_GetInventoryInfo

	// 是否启用 statuscheck 脚本指令 [Sola丶小克]
	// 判断状态是否存在, 并取得相关的状态参数 (该指令有一个用于兼容的别名: sc_check)
	#define Pandas_ScriptCommand_StatusCheck

	// 是否启用 renttimeidx 脚本指令 [Sola丶小克]
	// 增加/减少指定背包序号道具的租赁时间
	#define Pandas_ScriptCommand_RentTimeIdx

	// 是否启用 party_leave 脚本指令 [Sola丶小克]
	// 使当前角色或指定角色退出队伍 (主要出于兼容目的而实现该指令)
	#define Pandas_ScriptCommand_PartyLeave

	// 是否启用 script4each / script4eachmob / script4eachnpc 脚本指令 [Sola丶小克]
	// 对指定范围的玩家 / 魔物 / NPC 执行相同的一段脚本
	#define Pandas_ScriptCommand_Script4Each

	// 是否启用 searcharray 脚本指令 [Sola丶小克]
	// 由于 rAthena 已经实现 inarray 指令, 这里兼容老版本 searcharray 指令
	#define Pandas_ScriptCommand_SearchArray

	// 是否启用 getsameipinfo 脚本指令 [Sola丶小克]
	// 获得某个指定 IP 在线的玩家信息
	#define Pandas_ScriptCommand_GetSameIpInfo

	// 是否启用 logout 脚本指令 [Sola丶小克]
	// 使指定的角色立刻登出游戏
	#define Pandas_ScriptCommand_Logout

	// 是否启用 warppartyrevive 脚本指令 [Sola丶小克]
	// 与 warpparty 类似, 但可以复活死亡的队友并传送 (该指令有一个用于兼容的别名: warpparty2)
	#define Pandas_ScriptCommand_WarpPartyRevive

	// 是否启用 getareagid 脚本指令 [Sola丶小克]
	// 获取指定范围内特定类型单位的全部 GID (注意: 该指令不再兼容以前 rAthenaCN 的同名指令)
	#define Pandas_ScriptCommand_GetAreaGid

	// 是否启用 processhalt 脚本指令 [Sola丶小克]
	// 在事件处理代码中使用该指令, 可以中断源代码的后续处理逻辑
	// 此选项开关需要依赖 Pandas_Struct_Map_Session_Data_EventHalt 的拓展
	#ifdef Pandas_Struct_Map_Session_Data_EventHalt
		#define Pandas_ScriptCommand_ProcessHalt
	#endif // Pandas_Struct_Map_Session_Data_EventHalt

	// 是否启用 settrigger 脚本指令 [Sola丶小克]
	// 使用该指令可以设置某个事件或过滤器的触发行为 (是否触发、下次触发、永久触发)
	// 此选项开关需要依赖 Pandas_Struct_Map_Session_Data_EventTrigger 的拓展
	#ifdef Pandas_Struct_Map_Session_Data_EventTrigger
		#define Pandas_ScriptCommand_SetEventTrigger
	#endif // Pandas_Struct_Map_Session_Data_EventTrigger

	// 是否启用 messagecolor 脚本指令 [Sola丶小克]
	// 使用该指令可以发送指定颜色的消息文本到聊天窗口中
	#define Pandas_ScriptCommand_MessageColor

	// 是否启用 copynpc 脚本指令 [Sola丶小克]
	// 使用该指令可以复制指定的 NPC 到一个新的位置 (坐标等相对可以灵活设置)
	#define Pandas_ScriptCommand_Copynpc

	// 是否启用 gettimefmt 脚本指令 [Sola丶小克]
	// 将当前时间格式化输出成字符串, 是 gettimestr 的改进版
	#define Pandas_ScriptCommand_GetTimeFmt

	// 是否启用 multicatchpet 脚本指令 [Sola丶小克]
	// 与 catchpet 指令类似, 但可以指定更多支持捕捉的魔物编号
	// 此选项开关需要依赖 Pandas_Struct_Map_Session_Data_MultiCatchTargetClass 的拓展
	#ifdef Pandas_Struct_Map_Session_Data_MultiCatchTargetClass
		#define Pandas_ScriptCommand_MultiCatchPet
	#endif // Pandas_Struct_Map_Session_Data_MultiCatchTargetClass

	// 是否启用 selfdeletion 脚本指令 [Sola丶小克]
	// 设置 NPC 的自毁策略, 用于配合 copynpc 实现在开宝箱/挖矿时进行自毁等场景
	#define Pandas_ScriptCommand_SelfDeletion

	#ifdef Pandas_Character_Title_Controller
		// 是否启用 setchartitle 脚本指令 [Sola丶小克]
		// 设置指定玩家的称号ID, 客户端封包版本大于等于 20150513 才可用
		#define Pandas_ScriptCommand_SetCharTitle

		// 是否启用 getchartitle 脚本指令 [Sola丶小克]
		// 获得指定玩家的称号ID, 客户端封包版本大于等于 20150513 才可用
		#define Pandas_ScriptCommand_GetCharTitle
	#endif // Pandas_Character_Title_Controller

	// 是否启用 npcexists 脚本指令 [Sola丶小克]
	// 该指令用于判断指定名称的 NPC 是否存在, 就算不存在控制台也不会报错
	#define Pandas_ScriptCommand_NpcExists

	#ifdef Pandas_FuncDefine_STORAGE_ADDITEM
		// 是否启用 storagegetitem 脚本指令 [Sola丶小克]
		// 往仓库直接创造一个指定的道具, 必须在仓库关闭的时候才能调用
		#define Pandas_ScriptCommand_StorageGetItem
	#endif // Pandas_FuncDefine_STORAGE_ADDITEM
	// PYHELP - SCRIPTCMD - INSERT POINT - <Section 1>
#endif // Pandas_ScriptCommands

// ============================================================================
// 脚本返回值拓展组 - Pandas_ScriptResults
// ============================================================================

#ifdef Pandas_ScriptResults
	// 是否拓展 getinventorylist 脚本指令的返回数组 [Sola丶小克]
	#define Pandas_ScriptResults_GetInventoryList

	// 使 OnSellItem 标签可以返回被出售道具的背包序号 [Sola丶小克]
	#define Pandas_ScriptResults_OnSellItem
#endif // Pandas_ScriptResults

// ============================================================================
// 脚本参数拓展组 - Pandas_ScriptParams
// ============================================================================

#ifdef Pandas_ScriptParams
	// 是否拓展 readparam 脚本指令的可用参数 [Sola丶小克]
	#define Pandas_ScriptParams_ReadParam

	// 是否拓展 getiteminfo 脚本指令的可用参数 [Sola丶小克]
	#define Pandas_ScriptParams_GetItemInfo
#endif // Pandas_ScriptParams

#endif // _RATHENA_CN_CONFIG_HPP_
