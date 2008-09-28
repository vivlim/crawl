/*
 *  File:       debug.h
 *  Summary:    Debug and wizard related functions.
 *  Written by: Linley Henzell and Jesse Jones
 *
 *  Modified for Crawl Reference by $Author$ on $Date$
 */

#ifndef DEBUG_H
#define DEBUG_H

#include <string>
#include "enum.h"

// Synch with ANSI definitions.
#if DEBUG && defined(NDEBUG)
#error DEBUG and NDEBUG are out of sync!
#endif

#if !DEBUG && !defined(NDEBUG)
#error DEBUG and NDEBUG are out of sync!
#endif

// Synch with MSL definitions.
#if __MSL__ && DEBUG != defined(MSIPL_DEBUG_MODE)
#error DEBUG and MSIPL_DEBUG_MODE are out of sync!
#endif

// Synch with MSVC.
#if _MSC_VER >= 1100 && DEBUG != defined(_DEBUG)
#error DEBUG and _DEBUG are out of sync!
#endif


#ifndef _lint
#define COMPILE_CHECK(expr, tag) typedef char compile_check_ ## tag[(expr) ? 1 : -1]
#else
#define COMPILE_CHECK(expr, tag)
#endif

#if DEBUG

void AssertFailed(const char *expr, const char *file, int line);

#define ASSERT(p)       do {if (!(p)) AssertFailed(#p, __FILE__, __LINE__);} while (false)
#define VERIFY(p)       ASSERT(p)

void DEBUGSTR(const char *format,...);
void TRACE(const char *format,...);

#else

#define ASSERT(p)       ((void) 0)
#define VERIFY(p)       do {if (p) ;} while (false)

inline void __DUMMY_TRACE__(...)
{
}

#define DEBUGSTR                                                1 ? ((void) 0) : __DUMMY_TRACE__
#define TRACE                                                   1 ? ((void) 0) : __DUMMY_TRACE__

#endif


// last updated 12 Jun 2008 {jpeg}
/* ***********************************************************************
 * called from: acr
 * *********************************************************************** */
void wizard_cast_spec_spell(void);
void wizard_cast_spec_spell_name(void);
void wizard_create_spec_monster(void);
void wizard_create_spec_monster_name(void);
void wizard_create_spec_object(void);
void wizard_tweak_object(void);
void wizard_exercise_skill(void);
void wizard_set_skill_level(void);
void wizard_set_all_skills(void);
bool wizard_add_mutation(void);
void wizard_change_species( void );
void wizard_set_xl();
void wizard_get_religion( void );
void wizard_set_stats( void );
void wizard_draw_card();
void wizard_dismiss_all_monsters(bool force_all = false);
void wizard_place_stairs( bool down );
void wizard_level_travel( bool down );
void wizard_interlevel_travel();
void debug_make_trap( void );
void debug_make_shop( void );
void debug_place_map();
// Honest debugging functions.
void debug_item_scan( void );
void debug_mons_scan();
void debug_item_statistics( void );
void debug_fight_statistics( bool use_init_defaults, bool defence = false );
void debug_list_monsters();
void debug_test_explore();


// last updated 12 Jun 2008 {jpeg}
/* ***********************************************************************
 * called from: directn
 * *********************************************************************** */
void error_message_to_player(void);
#if DEBUG_DIAGNOSTICS
void debug_stethoscope(int mon);
#endif

class monsters;
class coord_def;
void wizard_apply_monster_blessing(monsters* mon);
void wizard_give_monster_item(monsters* mon);
void wizard_move_player_or_monster(const coord_def& where);
void debug_make_monster_shout(monsters* mon);
void debug_pathfind(int mid);
void debug_miscast( int target );


#ifdef DEBUG_DIAGNOSTICS
/* ***********************************************************************
 * called from: acr
 * *********************************************************************** */
void generate_map_stats();

class map_def;
void mapgen_report_map_try(const map_def &map);
void mapgen_report_map_use(const map_def &map);
void mapgen_report_error(const map_def &map, const std::string &err);
void mapgen_report_map_build_start();
void mapgen_report_map_veto();
#endif

struct item_def;

bool get_item_by_name(item_def *item, char* specs,
                      object_class_type class_wanted,
                      bool create_for_real = false);

#endif
