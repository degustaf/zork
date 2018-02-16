#define EXTERN
#define INIT

// #include "funcs.h"
/* funcs.h -- functions for dungeon */

#ifndef FUNCS_H
#define FUNCS_H

/* If __STDC__ is not defined, don't use function prototypes, void, or
 * const.
 */

#ifdef __STDC__
#define P(x) x
#else
#define P(x) ()
#define void int
#define const
#endif

/* Try to guess whether we need "rb" to open files in binary mode.
 * If this is unix, it doesn't matter.  Otherwise, assume that if
 * __STDC__ is defined we can use "rb".  Otherwise, assume that we
 * had better use "r" or fopen will fail.
 */

#ifdef unix
#define BINREAD "r"
#define BINWRITE "w"
#else /* ! unix */
#ifdef __STDC__
#define BINREAD "rb"
#define BINWRITE "wb"
#else /* ! __STDC__ */
#define BINREAD "r"
#define BINWRITE "w"
#endif /* ! __STDC__ */
#endif /* ! unix */

#include <stdbool.h>
#include <stdlib.h>

typedef int integer;
typedef bool logical;

// #define abs(x) ((x) >= 0 ? (x) : -(x))
#define min(a,b) ((a) <= (b) ? (a) : (b))
#define max(a,b) ((a) >= (b) ? (a) : (b))

extern logical
	protected P((void)),
	wizard P((void));

extern void
	more_init P((void)),
	more_output P((const char *)),
	more_input P((void));

extern void
	bug_ P((integer, integer)),
	cevapp_ P((integer)),
	cpgoto_ P((integer)),
	cpinfo_ P((integer, integer)),
	encryp_ P((const char *, char *)),
	exit_ P((void)),
	fightd_ P((void)),
	game_ P((void)),
	gdt_ P((void)),
	invent_ P((integer)),
	itime_ P((integer *, integer *, integer *)), 
	jigsup_ P((integer)),
	newsta_ P((integer, integer, integer, integer, integer)),
	orphan_ P((integer, integer, integer, integer, integer)),
	princo_ P((integer, integer)),
	princr_ P((logical, integer)),
	rdline_ P((char *, integer)),
	rspeak_ P((integer)),
	rspsb2_ P((integer, integer, integer)),
	rspsub_ P((integer, integer)),
	rstrgm_ P((void)),
	savegm_ P((void)),
	score_ P((logical)),
	scrupd_ P((integer)),
	swordd_ P((void)),
	thiefd_ P((void)),
	valuac_ P((integer));
extern integer
	blow_ P((integer, integer, integer, logical, integer)),
	fights_ P((integer, logical)),
	fwim_ P((integer, integer, integer, integer, integer, logical)),
	getobj_ P((integer, integer, integer)),
	schlst_ P((integer, integer, integer, integer,  integer, integer)),
	mrhere_ P((integer)),
	oactor_ P((integer)),
	rnd_ P((integer)),
	robadv_ P((integer, integer, integer, integer)), 
	robrm_ P((integer, integer, integer, integer, integer)),
	sparse_ P((const integer *, integer, logical)),
	vilstr_ P((integer)),
	weight_ P((integer, integer, integer));

extern int gttime_();


extern logical
	aappli_ P((integer)),
	ballop_ P((integer)),
	clockd_ P((void)),
	cyclop_ P((integer)),
	drop_ P((logical)),
	findxt_ P((integer, integer)),
	ghere_ P((integer, integer)),
	init_ P((void)),
	lightp_ P((integer)),
	lit_ P((integer)),
	moveto_ P((integer, integer)),
	nobjs_ P((integer, integer)),
	oappli_ P((integer, integer)),
	objact_ P((void)),
	opncls_ P((integer, integer, integer)),
	parse_ P((char *, logical)),
	prob_ P((integer, integer)),
	put_ P((logical)),
	rappli_ P((integer)),
	rappl1_ P((integer)),
	rappl2_ P((integer)),
	rmdesc_ P((integer)),
	sobjs_ P((integer, integer)),
	sverbs_ P((integer)),
	synmch_ P((void)),
	take_ P((logical)),
	thiefp_ P((integer)),
	trollp_ P((integer)),
	qempty_ P((integer)),
	qhere_ P((integer, integer)),
	vappli_ P((integer)),
	walk_ P((void)),
	winnin_ P((integer, integer)),
	yesno_ P((integer, integer, integer));

#endif

// #include "vars.h"
/* vars.h -- variables for dungeon */

/* These variable definitions are really ugly because they are actually
 * translations of FORTRAN common blocks.  In the original FORTRAN source
 * the common blocks were included many times by each function that
 * needed them; I have changed this to define them all in this one file,
 * and include this in every source file.  It's less modular, and it
 * makes everything slower to compile, but it's easier on me.
 * A few structures used only by the parsing routines are in parse.h.
 */

#ifndef VARS_H
#define VARS_H

#ifndef EXTERN
#define EXTERN extern
#endif

EXTERN struct {
    integer prsa, prsi, prso;
    logical prswon;
    integer prscon;
} prsvec_;

#define prsvec_1 prsvec_

EXTERN struct {
    integer oflag, oact, oslot, oprep, oname;
} orphs_;

#define orphs_1 orphs_
#define orp ((integer *)&orphs_1)

EXTERN struct {
    integer lastit;
} last_;

#define last_1 last_

EXTERN struct {
    integer winner, here;
    logical telflg;
} play_;

#define play_1 play_

EXTERN struct {
    integer rlnt, rdesc1[200], rdesc2[200], rexit[200], ractio[200],
	    rval[200], rflag[200];
} rooms_;

#define rooms_1 rooms_
#define eqr ((integer *)&rooms_1 + 1)
#define rrand ((integer *)&rooms_1 + 601)

/* Room flags */

#define RSEEN (32768)
#define RLIGHT (16384)
#define RLAND (8192)
#define RWATER (4096)
#define RAIR (2048)
#define RSACRD (1024)
#define RFILL (512)
#define RMUNG (256)
#define RBUCK (128)
#define RHOUSE (64)
#define RNWALL (32)
#define REND (16)

EXTERN const struct {
    integer whous, lroom, cella, mtrol, maze1, mgrat, maz15, fore1, fore3, 
	    clear, reser, strea, egypt, echor, tshaf, bshaf, mmach, dome, 
	    mtorc, carou, riddl, lld2, temp1, temp2, maint, blroo, treas, 
	    rivr1, rivr2, rivr3, mcycl, rivr4, rivr5, fchmp, falls, mbarr, 
	    mrain, pog, vlbot, vair1, vair2, vair3, vair4, ledg2, ledg3, 
	    ledg4, msafe, cager, caged, twell, bwell, alice, alism, alitr, 
	    mtree, bkent, bkvw, bktwi, bkvau, bkbox, crypt, tstrs, mrant, 
	    mreye, mra, mrb, mrc, mrg, mrd, fdoor, mrae, mrce, mrcw, mrge, 
	    mrgw, mrdw, inmir, scorr, ncorr, parap, cell, pcell, ncell, cpant,
	    cpout, cpuzz;
} rindex_
#ifdef INIT
	= { 2, 8, 9, 10, 11, 25, 30, 31, 33, 36, 40, 42, 44, 49, 61, 76,
	    77, 79, 80, 83, 91, 94, 96, 97, 100, 102, 103, 107, 108, 109, 
	    101, 112, 113, 114, 120, 119, 121, 122, 126, 127, 128, 129, 130, 
	    131, 132, 133, 135, 140, 141, 142, 143, 144, 145, 146, 147, 148, 
	    151, 153, 154, 155, 157, 158, 159, 160, 161, 162, 163, 164, 165, 
	    166, 167, 171, 172, 173, 174, 176, 177, 179, 182, 183, 184, 185, 
	    186, 188, 189, 190 }
#endif
	;

#define rindex_1 rindex_

EXTERN const struct {
    integer xmin, xmax, xdown, xup, xnorth, xsouth, xenter, xexit, xeast, 
	    xwest;
} xsrch_
#ifdef INIT
	= { 1024, 16384, 10240, 9216, 1024, 5120, 13312, 14336, 3072, 
	    7168 }
#endif
	;

#define xsrch_1 xsrch_

EXTERN struct {
    integer olnt, odesc1[220], odesc2[220], odesco[220], oactio[220], oflag1[
	    220], oflag2[220], ofval[220], otval[220], osize[220], ocapac[220]
	    , oroom[220], oadv[220], ocan[220], oread[220];
} objcts_;

#define objcts_1 objcts_
#define eqo ((integer *)&objcts_1 + 1)

EXTERN struct {
    integer r2lnt, oroom2[20], rroom2[20];
} oroom2_;

#define oroom2_1 oroom2_

/* Object flags (oflags) */

#define VISIBT (32768)
#define READBT (16384)
#define TAKEBT (8192)
#define DOORBT (4096)
#define TRANBT (2048)
#define FOODBT (1024)
#define NDSCBT (512)
#define DRNKBT (256)
#define CONTBT (128)
#define LITEBT (64)
#define VICTBT (32)
#define BURNBT (16)
#define FLAMBT (8)
#define TOOLBT (4)
#define TURNBT (2)
#define ONBT (1)
#define FINDBT (32768)
#define SLEPBT (16384)
#define SCRDBT (8192)
#define TIEBT (4096)
#define CLMBBT (2048)
#define ACTRBT (1024)
#define WEAPBT (512)
#define FITEBT (256)
#define VILLBT (128)
#define STAGBT (64)
#define TRYBT (32)
#define NOCHBT (16)
#define OPENBT (8)
#define TCHBT (4)
#define VEHBT (2)
#define SCHBT (1)

EXTERN const struct {
    int garli, food, gunk, coal, machi, diamo, tcase, bottl, water, rope, 
	    knife, sword, lamp, blamp, rug, leave, troll, axe, rknif, keys, 
	    ice, bar, coffi, torch, tbask, fbask, irbox, ghost, trunk, bell, 
	    book, candl, match, tube, putty, wrenc, screw, cyclo, chali, 
	    thief, still, windo, grate, door, hpole, leak, rbutt, raili, pot, 
	    statu, iboat, dboat, pump, rboat, stick, buoy, shove, ballo, 
	    recep, guano, brope, hook1, hook2, safe, sslot, brick, fuse, 
	    gnome, blabe, dball, tomb, lcase, cage, rcage, spher, sqbut, 
	    flask, pool, saffr, bucke, ecake, orice, rdice, blice, robot, 
	    ftree, bills, portr, scol, zgnom, egg, begg, baubl, canar, bcana, 
	    ylwal, rdwal, pindr, rbeam, odoor, qdoor, cdoor, num1, num8, 
	    warni, cslit, gcard, stldr, hands, wall, lungs, sailo, aviat, 
	    teeth, itobj, every, valua, oplay, wnort, gwate, master;
} oindex_
#ifdef INIT
	= { 2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	    20, 21, 23, 30, 26, 33, 34, 35, 36, 39, 42, 45, 46, 47, 48, 51, 
	    54, 55, 56, 57, 58, 59, 61, 62, 63, 65, 66, 71, 78, 79, 75, 85, 
	    86, 87, 88, 89, 90, 92, 94, 96, 98, 99, 97, 101, 102, 103, 105, 
	    107, 109, 110, 111, 112, 113, 119, 123, 124, 125, 126, 127, 132, 
	    133, 134, 137, 138, 139, 140, 141, 142, 145, 148, 149, 151, 152, 
	    154, 155, 156, 157, 158, 159, 161, 164, 171, 172, 173, 175, 178, 
	    185, 186, 187, 188, 189, 200, 198, 201, 196, 202, 197, 192, 194, 
	    195, 193, 205, 209, 215 }
#endif
	;

#define oindex_1 oindex_

EXTERN struct {
    integer clnt, ctick[25], cactio[25];
    logical cflag[25];
} cevent_;

#define cevent_1 cevent_
#define eqc ((integer *)&cevent_1 + 1)

EXTERN const struct {
    integer cevcur, cevmnt, cevlnt, cevmat, cevcnd, cevbal, cevbrn, cevfus, 
	    cevled, cevsaf, cevvlg, cevgno, cevbuc, cevsph, cevegh, cevfor, 
	    cevscl, cevzgi, cevzgo, cevste, cevmrs, cevpin, cevinq, cevfol;
} cindex_
#ifdef INIT
	= { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 
	    18, 19, 20, 21, 22, 23, 24 }
#endif
	;

#define cindex_1 cindex_

EXTERN struct {
    integer alnt, aroom[4], ascore[4], avehic[4], aobj[4], aactio[4], astren[
	    4], aflag[4];
} advs_;

#define advs_1 advs_
#define eqa ((integer *)&advs_1 + 1)

EXTERN const struct {
    integer astag;
} aflags_
#ifdef INIT
	= { 32768 }
#endif
	;

#define aflags_1 aflags_

EXTERN const struct {
    integer player, arobot, amastr;
} aindex_
#ifdef INIT
	= { 1, 2, 3 }
#endif
	;

#define aindex_1 aindex_

EXTERN const struct {
    integer cintw, deadxw, frstqw, inxw, outxw, walkiw, fightw, foow, meltw, 
	    readw, inflaw, deflaw, alarmw, exorcw, plugw, kickw, wavew, 
	    raisew, lowerw, rubw, pushw, untiew, tiew, tieupw, turnw, breatw, 
	    knockw, lookw, examiw, shakew, movew, trnonw, trnofw, openw, 
	    closew, findw, waitw, spinw, boardw, unboaw, takew, invenw, fillw,
	     eatw, drinkw, burnw, mungw, killw, attacw, swingw, walkw, tellw, 
	    putw, dropw, givew, pourw, throww, digw, leapw, stayw, follow, 
	    hellow, lookiw, lookuw, pumpw, windw, clmbw, clmbuw, clmbdw, 
	    trntow;
} vindex_
#ifdef INIT
	= { 1, 2, 3, 4, 5, 6, 7, 8, 101, 100, 102, 103, 104, 105, 106, 
	    107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 
	    120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 
	    133, 134, 135, 136, 137, 138, 139, 141, 140, 142, 143, 144, 145, 
	    146, 147, 148, 89, 91, 73, 85, 151, 152, 153, 154, 155, 156, 157, 
	    158, 159 }
#endif
	;

#define vindex_1 vindex_

EXTERN struct {
    logical trollf, cagesf, bucktf, caroff, carozf, lwtidf, domef, glacrf, 
	    echof, riddlf, lldf, cyclof, magicf, litldf, safef, gnomef, 
	    gnodrf, mirrmf, egyptf, onpolf, blabf, brieff, superf, buoyf, 
	    grunlf, gatef, rainbf, cagetf, empthf, deflaf, glacmf, frobzf, 
	    endgmf, badlkf, thfenf, singsf, mrpshf, mropnf, wdopnf, mr1f, 
	    mr2f, inqstf, follwf, spellf, cpoutf, cpushf;
    integer btief, binff, rvmnt, rvclr, rvcyc, rvsnd, rvgua, orrug, orcand, 
	    ormtch, orlamp, mdir, mloc, poleuf, quesno, nqatt, corrct, lcell, 
	    pnumb, acell, dcell, cphere;
} findex_;

#define findex_1 findex_
#define flags ((logical *)&findex_1)
#define switch_ ((integer *)&findex_1 + 46)

EXTERN struct {
    integer dbgflg, prsflg, gdtflg;
} debug_;

#define debug_1 debug_

EXTERN struct {
    integer thfpos;
    logical thfflg, thfact, swdact;
    integer swdsta;
} hack_;

#define hack_1 hack_

EXTERN struct {
    integer vlnt, villns[4], vprob[4], vopps[4], vbest[4], vmelee[4];
} vill_;

#define vill_1 vill_
#define eqv ((integer *)&vill_1 + 1)

EXTERN struct {
    integer moves, deaths, rwscor, mxscor, mxload, ltshft, bloc, mungrm, hs, 
	    egscor, egmxsc;
} state_;

#define state_1 state_

EXTERN struct {
    integer xtype, xroom1, xstrng, xactio, xobj;
} curxt_;

#define curxt_1 curxt_
#define xflag ((integer *)&curxt_1 + 4)

EXTERN const struct {
    integer xrmask, xdmask, xfmask, xfshft, xashft, xelnt[4], xnorm, xno, 
	    xcond, xdoor, xlflag;
} xpars_
#ifdef INIT
	= { 255, 31744, 3, 256, 256, { 1, 2, 3, 3 }, 1, 2, 3, 4, 32768 }
#endif
	;

#define xpars_1 xpars_

EXTERN struct {
    integer mbase, strbit;
} star_;

#define star_1 star_

EXTERN struct {
    integer inlnt;
    char inbuf[78];
} input_;

#define input_1 input_

EXTERN struct {
    integer fromdr, scolrm, scolac;
    const integer scoldr[8], scolwl[12];
} screen_
#ifdef INIT
	= { 0, 0, 0, { 1024, 153, 5120, 154, 3072, 152, 7168, 151 },
	    { 151, 207, 3072, 152, 208, 7168, 153, 206, 5120, 154, 205,
	      1024 } }
#endif
	;

#define screen_1 screen_

EXTERN struct {
    integer mlnt, mrloc, rtext[1050];
} rmsg_;

#define rmsg_1 rmsg_

EXTERN const struct {
    integer vmaj, vmin, vedit;
} vers_
#ifdef INIT
	= { 2, 7, 'A' }
#endif
	;

#define vers_1 vers_

EXTERN struct {
    integer pltime, shour, smin, ssec;
} time_;

#define time_1 time_

EXTERN const struct {
    integer hfactr;
} hyper_
#ifdef INIT
	= { 500 }
#endif
	;

#define hyper_1 hyper_

EXTERN struct {
    integer xlnt, travel[900];
} exits_;

#define exits_1 exits_

EXTERN struct {
    const integer cpdr[16], cpwl[8];
    integer cpvec[64];
} puzzle_
#ifdef INIT
	= { { 1024, -8, 2048, -7, 3072, 1, 4096, 9, 5120, 8, 6144, 7, 
	      7168, -1, 8192, -9 },
	    { 205, -8, 206, 8, 207, 1, 208, -1 },
            { 1,  1,  1,  1,  1,  1, 1, 1,
              1,  0, -1,  0,  0, -1, 0, 1,
              1, -1,  0,  1,  0, -2, 0, 1,
	      1,  0,  0,  0,  0,  1, 0, 1,
	      1, -3,  0,  0, -1, -1, 0, 1,
	      1,  0,  0, -1,  0,  0, 0, 1,
	      1,  1,  1,  0,  0,  0, 1, 1,
	      1,  1,  1,  1,  1,  1, 1, 1 } }
#endif
	;

#define puzzle_1 puzzle_

EXTERN const struct {
    const integer batdrp[9];
} bats_
#ifdef INIT
	= { 66, 67, 68, 69, 70, 71, 72, 65, 73 }
#endif
	;

#define bats_1 bats_

#endif


// actors.c

// #include "funcs.h"
// #include "vars.h"

bool aappli_(int ri) {
  bool f;
  int i;

  if (ri == 0) {
    return false;
  }
  if(ri == 1) {
    if (prsvec_1.prsa != vindex_1.raisew || prsvec_1.prso != oindex_1.rcage) {
      if (prsvec_1.prsa != vindex_1.drinkw && prsvec_1.prsa != vindex_1.eatw) {
        if (prsvec_1.prsa != vindex_1.readw) {
          if (prsvec_1.prsa == vindex_1.walkw || prsvec_1.prsa == vindex_1.takew || 
      	    prsvec_1.prsa == vindex_1.dropw || prsvec_1.prsa == vindex_1.putw 
      	    || prsvec_1.prsa == vindex_1.pushw || prsvec_1.prsa == 
      	    vindex_1.throww || prsvec_1.prsa == vindex_1.turnw || 
      	    prsvec_1.prsa == vindex_1.leapw) {
      	      return false;
          }
          rspeak_(570);   // JOKE.
          return true;
        }               // READ,
        rspeak_(569);   // JOKE.
        return true;
      }
      rspeak_(568);   // EAT OR DRINK, JOKE.
      return true;
    }
    cevent_1.cflag[cindex_1.cevsph - 1] = false;       // ROBOT RAISED CAGE.
    play_1.winner = aindex_1.player;                    // RESET FOR PLAYER.
    f = moveto_(rindex_1.cager, play_1.winner);         // MOVE TO NEW ROOM.
    newsta_(oindex_1.cage, 567, rindex_1.cager, 0, 0);  // INSTALL CAGE IN ROOM.
    newsta_(oindex_1.robot, 0, rindex_1.cager, 0, 0);   // INSTALL ROBOT IN ROOM.
    advs_1.aroom[aindex_1.arobot - 1] = rindex_1.cager; // ALSO MOVE ROBOT/ADV.
    findex_1.cagesf = true;                            // CAGE SOLVED.
    objcts_1.oflag1[oindex_1.robot - 1] &= ~ NDSCBT;
    objcts_1.oflag1[oindex_1.spher - 1] |= TAKEBT;
    return true;
  } else if(ri == 2) {
    if ((objcts_1.oflag2[oindex_1.qdoor - 1] & OPENBT) != 0) {
      if (prsvec_1.prsa != vindex_1.walkw) {
        if (prsvec_1.prsa == vindex_1.takew || prsvec_1.prsa == vindex_1.dropw || 
    	    prsvec_1.prsa == vindex_1.putw || prsvec_1.prsa == 
    	    vindex_1.throww || prsvec_1.prsa == vindex_1.pushw || 
    	    prsvec_1.prsa == vindex_1.turnw || prsvec_1.prsa == 
    	    vindex_1.spinw || prsvec_1.prsa == vindex_1.trntow || 
    	    prsvec_1.prsa == vindex_1.follow || prsvec_1.prsa == 
    	    vindex_1.stayw || prsvec_1.prsa == vindex_1.openw || 
    	    prsvec_1.prsa == vindex_1.closew || prsvec_1.prsa == 
    	    vindex_1.killw) {
    	      return false;
        }
        rspeak_(786);   // MASTER CANT DO IT.
        return true;
      }     // WALK?
      i = 784;  // ASSUME WONT.
      if (play_1.here == rindex_1.scorr && (prsvec_1.prso == xsrch_1.xnorth || 
  	    prsvec_1.prso == xsrch_1.xenter) || play_1.here == rindex_1.ncorr 
  	    && (prsvec_1.prso == xsrch_1.xsouth || prsvec_1.prso == 
  	    xsrch_1.xenter)) {
  	      i = 785;
      }
      rspeak_(i);
      return true;
    }
    rspeak_(783);   // NO MASTER YET.
    return true;
  }                 // BRANCH ON ADV.
  bug_(11, ri);
  return false;
}

static int func1(int *rhere) {   // This needs a better name
  hack_1.thfflg = true;
  int nr = robrm_(hack_1.thfpos, 100, 0, 0, -oindex_1.thief) + robadv_(play_1.winner, 0, 0, -oindex_1.thief);
  int i = 586;
  if (*rhere != 0)
    i = 588;
  if (nr != 0)
    ++i;
  newsta_(oindex_1.thief, i, 0, 0, 0);
  if (qhere_(oindex_1.still, hack_1.thfpos) || objcts_1.oadv[oindex_1.still - 1] == -oindex_1.thief)
    newsta_(oindex_1.still, 0, 0, oindex_1.thief, 0);
  if (nr != 0 && ! lit_(hack_1.thfpos))
    rspeak_(406);
  *rhere = 0;
  return nr;
}

void thiefd_() {
    /* Local variables */
    integer i, j, nr;
    logical once;
    integer rhere;

    once = false;
  while(true) {
    rhere = objcts_1.oroom[oindex_1.thief - 1];
    if (rhere != 0)
	    hack_1.thfpos = rhere;

    if(((hack_1.thfpos == play_1.here) && (hack_1.thfpos != rindex_1.treas) &&
            ((rooms_1.rflag[hack_1.thfpos - 1] & RLIGHT) != 0)) || (hack_1.thfpos != rindex_1.treas)) {
      newsta_(oindex_1.thief, 0, 0, 0, 0);
      rhere = 0;
      if (qhere_(oindex_1.still, hack_1.thfpos) || objcts_1.oadv[oindex_1.still - 1] == -oindex_1.thief)
  	    newsta_(oindex_1.still, 0, 0, oindex_1.thief, 0);
      if((rooms_1.rflag[hack_1.thfpos - 1] & RSEEN) != 0) {
        i = robrm_(hack_1.thfpos, 75, 0, 0, -oindex_1.thief);
        if(hack_1.thfpos < rindex_1.maze1 || hack_1.thfpos > rindex_1.maz15 || play_1.here < rindex_1.maze1
            || play_1.here > rindex_1.maz15) {
          for(i = 0; i < objcts_1.olnt; i++) {
          	if(qhere_(i+1, hack_1.thfpos) && objcts_1.otval[i] == 0 && !prob_(80, 60) &&
          	      (objcts_1.oflag1[i] & VISIBT + TAKEBT) == VISIBT + TAKEBT) {
            	newsta_(i+1, 0, 0, 0, -oindex_1.thief);
            	objcts_1.oflag2[i] |= TCHBT;
            	break;
          	}
          }
        } else {
          for(i = 0; i < objcts_1.olnt; i++) {
          	if(qhere_(i+1, hack_1.thfpos) && !prob_(60, 60) &&
          	        (objcts_1.oflag1[i] & VISIBT + TAKEBT) == VISIBT + TAKEBT) {
            	rspsub_(590, objcts_1.odesc2[i]);
            	if(!prob_(40, 20)) {
              	newsta_(i+1, 0, 0, 0, -oindex_1.thief);
              	objcts_1.oflag2[i] |= TCHBT;
            	}
            	break;
          	}
          }
        }
      }
    } else if (hack_1.thfpos == play_1.here) {
      if(hack_1.thfpos != rindex_1.treas) {
        if(hack_1.thfflg) {
          if(rhere != 0) {
            if (prob_(70, 70))
        	    return;
        	  nr = func1(&rhere);
          }
        } else if (rhere != 0 || prob_(70, 70)) /* THIEF ANNOUNCED? */ {
          if(rhere == 0 || (objcts_1.oflag2[oindex_1.thief - 1] & FITEBT) == 0) {
            if(!winnin_(oindex_1.thief, play_1.winner)) {
              newsta_(oindex_1.thief, 584, 0, 0, 0);    // WINNING?
              objcts_1.oflag2[oindex_1.thief - 1] &= ~ FITEBT;  // NO, VANISH THIEF.
              if(qhere_(oindex_1.still, hack_1.thfpos) || objcts_1.oadv[oindex_1.still - 1] == -oindex_1.thief)
          	      newsta_(oindex_1.still, 0, 0, oindex_1.thief, 0);
              return;
            }
            if(prob_(90, 90)) {
        	    goto L1700;
            }
          }
          if(rhere != 0 && !prob_(70, 70)) {
            newsta_(oindex_1.thief, 585, 0, 0, 0);
            if (qhere_(oindex_1.still, hack_1.thfpos) || objcts_1.oadv[oindex_1.still - 1] == -oindex_1.thief)
        	      newsta_(oindex_1.still, 0, 0, oindex_1.thief, 0);
            return;
          }
          if (prob_(70, 70))
      	    return;
      	  nr = func1(&rhere);
        } else if(objcts_1.ocan[oindex_1.still - 1] == oindex_1.thief) {
          newsta_(oindex_1.thief, 583, hack_1.thfpos, 0, 0);    // INSERT THIEF INTO ROOM.
          hack_1.thfflg = true;                                // THIEF IS ANNOUNCED.
          return;
        }
      }
    } else {
      if (rhere != 0) {
        newsta_(oindex_1.thief, 0, 0, 0, 0);
        rhere = 0;
        if (qhere_(oindex_1.still, rindex_1.treas) || objcts_1.oadv[
    	    oindex_1.still - 1] == -oindex_1.thief) {
    	      newsta_(oindex_1.still, 0, 0, oindex_1.thief, 0);
        }
      }
      i = robadv_(-oindex_1.thief, hack_1.thfpos, 0, 0);   // DROP VALUABLES.
      if (qhere_(oindex_1.egg, hack_1.thfpos)) {
  	    objcts_1.oflag2[oindex_1.egg - 1] |= OPENBT;
      }
    }

L1700:
    if (objcts_1.oadv[oindex_1.rope - 1] == -oindex_1.thief) {
	    findex_1.domef = false;
    }
    if(once) {
      if (hack_1.thfpos == rindex_1.treas)
  	    return;
      j = (hack_1.thfpos == play_1.here) ? 591 : 0;
      for(i = 0; i < objcts_1.olnt; i++) {
      	if(objcts_1.oadv[i] == -oindex_1.thief && !prob_(70, 70) && objcts_1.otval[i] <= 0) {
      	  newsta_(i+1, j, hack_1.thfpos, 0, 0);
      	  j = 0;
      	}
      }
      return;
    }
    once = !once;
    do {
      --hack_1.thfpos;
      if (hack_1.thfpos <= 0)
  	    hack_1.thfpos = rooms_1.rlnt;
    } while((rooms_1.rflag[hack_1.thfpos - 1] & RLAND + RSACRD + REND) != RLAND);
    hack_1.thfflg = false;
  }

} /* thiefd_ */


// ballop.c
/* BALLOP-	BALLOON FUNCTION */

// #include "funcs.h"
// #include "vars.h"

bool ballop_(int arg) {
  if(arg == 2) {
    if (prsvec_1.prsa != vindex_1.lookw)
      return false;
    if(findex_1.binff)
      rspsub_(544, objcts_1.odesc2[findex_1.binff - 1]);
    else
      rspeak_(543);
    if(findex_1.btief)
      rspeak_(545);
    return true;
  }
  if(arg == 1) {
    if (prsvec_1.prsa != vindex_1.walkw) {
      if (prsvec_1.prsa != vindex_1.takew || prsvec_1.prso != findex_1.binff) {
        if (prsvec_1.prsa != vindex_1.putw || prsvec_1.prsi != oindex_1.recep || qempty_(oindex_1.recep))
    	    return false;;
        rspeak_(549);
        return true;
      }
      rspsub_(548, objcts_1.odesc2[findex_1.binff - 1]);
      return true;
    }
    if (findxt_(prsvec_1.prso, play_1.here)) {
      if (findex_1.btief == 0) {
        if((curxt_1.xtype == xpars_1.xnorm) && ((rooms_1.rflag[curxt_1.xroom1 - 1] & RMUNG) == 0))
      	  state_1.bloc = curxt_1.xroom1;
    	  return false;
      }
      rspeak_(547);
      return true;
    }
    rspeak_(546);
    return true;
  }
  if (prsvec_1.prsa != vindex_1.unboaw || (rooms_1.rflag[play_1.here - 1] & RLAND) == 0) {
    if (prsvec_1.prsa != vindex_1.burnw || objcts_1.ocan[prsvec_1.prso - 1] != oindex_1.recep) {
      if (prsvec_1.prsa == vindex_1.unboaw && findex_1.binff != 0 && (rooms_1.rflag[play_1.here - 1] & RLAND) != 0)
  	    cevent_1.ctick[cindex_1.cevbal - 1] = 3;
      return false;
    }
    rspsub_(550, objcts_1.odesc2[prsvec_1.prso - 1]);
    cevent_1.ctick[cindex_1.cevbrn - 1] = objcts_1.osize[prsvec_1.prso - 1] * 20;
    objcts_1.oflag1[prsvec_1.prso - 1] |= ONBT + FLAMBT + LITEBT & ~ (TAKEBT + READBT);
    if (findex_1.binff != 0)
	    return true;
    if (! findex_1.blabf)
	    newsta_(oindex_1.blabe, 0, 0, oindex_1.ballo, 0);
    findex_1.blabf = true;
    findex_1.binff = prsvec_1.prso;
    cevent_1.ctick[cindex_1.cevbal - 1] = 3;
    rspeak_(551);
    return true;
  }
  if (findex_1.binff != 0)
    cevent_1.ctick[cindex_1.cevbal - 1] = 3;
  return false;
}


// clockr.c
/* CEVAPP- CLOCK EVENT APPLICABLES */

// #include "funcs.h"
// #include "vars.h"

static void litint_(int, int*, int, const int*, int);

void cevapp_(int ri) {
    /* Initialized data */
    static const integer cndtck[10] = { 50,20,10,5,0,156,156,156,157,0 };
    static const integer lmptck[12] = { 50,30,20,10,4,0,154,154,154,154,155,0 };
    /* Local variables */
    logical f;
    integer i, j, bc, br;

    switch (ri) {
      case 0:
        return;
    	case 1:
        advs_1.astren[aindex_1.player - 1] = min(0, advs_1.astren[aindex_1.player-1] + 1);
        if(advs_1.astren[aindex_1.player - 1] < 0)
    	    cevent_1.ctick[cindex_1.cevcur - 1] = 30;
        return;
    	case 2:
        if (play_1.here == rindex_1.maint)
        	rspeak_(findex_1.rvmnt / 2 + 71);
        ++findex_1.rvmnt;
        if (findex_1.rvmnt > 16) {
          cevent_1.ctick[cindex_1.cevmnt - 1] = 0;
          rooms_1.rflag[rindex_1.maint - 1] |= RMUNG;
          rrand[rindex_1.maint - 1] = 80;
          if (play_1.here == rindex_1.maint)
      	    jigsup_(81);
        }
        return;
    	case 3:
        litint_(oindex_1.lamp, &findex_1.orlamp, cindex_1.cevlnt, lmptck, 12);
        return;
    	case 4:
        rspeak_(153);
        objcts_1.oflag1[oindex_1.match - 1] &= ~ ONBT;
        return;
    	case 5:
        litint_(oindex_1.candl, &findex_1.orcand, cindex_1.cevcnd, cndtck, 10);
        return;
    	case 6:
        cevent_1.ctick[cindex_1.cevbal - 1] = 3;
        f = advs_1.avehic[play_1.winner - 1] == oindex_1.ballo;
        if (state_1.bloc == rindex_1.vlbot) {
    	    if (findex_1.binff != 0 && ((objcts_1.oflag2[oindex_1.recep - 1] & OPENBT) != 0)) {
            state_1.bloc = rindex_1.vair1;
            newsta_(oindex_1.ballo, 0, state_1.bloc, 0, 0);
            if (f) {
        	    f = moveto_(state_1.bloc, play_1.winner);
              rspeak_(542);
              f = rmdesc_(0);
            } else if(play_1.here == rindex_1.ledg2 || play_1.here == rindex_1.ledg3 || play_1.here == rindex_1.ledg4 ||
                      play_1.here == rindex_1.vlbot)
        	    rspeak_(541);
    	    }
        } else if (state_1.bloc == rindex_1.ledg2 || state_1.bloc == rindex_1.ledg3 || state_1.bloc == rindex_1.ledg4 ||
                    state_1.bloc == rindex_1.vlbot) {
          state_1.bloc += rindex_1.vair2 - rindex_1.ledg2;
          newsta_(oindex_1.ballo, 0, state_1.bloc, 0, 0);
          if (f) {
      	    f = moveto_(state_1.bloc, play_1.winner);
            rspeak_(540);
            f = rmdesc_(0);
          } else {
            if (play_1.here == rindex_1.ledg2 || play_1.here == rindex_1.ledg3 || play_1.here == rindex_1.ledg4 || play_1.here == rindex_1.vlbot) {
        	    rspeak_(539);
            }
            cevent_1.ctick[cindex_1.cevvlg - 1] = 10;
          }
        } else if ((objcts_1.oflag2[oindex_1.recep - 1] & OPENBT) != 0 && findex_1.binff != 0) {
          if(state_1.bloc == rindex_1.vair4) {
            cevent_1.ctick[cindex_1.cevbrn - 1] = 0;
            cevent_1.ctick[cindex_1.cevbal - 1] = 0;
            findex_1.binff = 0;
            findex_1.btief = 0;
            state_1.bloc = rindex_1.vlbot;
            newsta_(oindex_1.ballo, 0, 0, 0, 0);
            newsta_(oindex_1.dball, 0, state_1.bloc, 0, 0);
            if(f) {
        	    jigsup_(536);
            } else if (play_1.here == rindex_1.ledg2 || play_1.here == rindex_1.ledg3 || play_1.here == rindex_1.ledg4 || play_1.here == rindex_1.vlbot) {
        	    rspeak_(535);
            }
          } else {
            ++state_1.bloc;
            newsta_(oindex_1.ballo, 0, state_1.bloc, 0, 0);
            if (f) {
              f = moveto_(state_1.bloc, play_1.winner);
              rspeak_(538);
              f = rmdesc_(0);
            } else if(play_1.here == rindex_1.ledg2 || play_1.here == rindex_1.ledg3 || play_1.here == rindex_1.ledg4 || play_1.here == rindex_1.vlbot) {
        	    rspeak_(537);
            }
          }
        } else if(state_1.bloc == rindex_1.vair1) {
          state_1.bloc = rindex_1.vlbot;
          newsta_(oindex_1.ballo, 0, state_1.bloc, 0, 0);
          if(f) {
            f = moveto_(state_1.bloc, play_1.winner);
            if (findex_1.binff == 0) {
        	    newsta_(oindex_1.ballo, 532, 0, 0, 0);
              newsta_(oindex_1.dball, 0, state_1.bloc, 0, 0);
              advs_1.avehic[play_1.winner - 1] = 0;
              cevent_1.cflag[cindex_1.cevbal - 1] = false;
              cevent_1.cflag[cindex_1.cevbrn - 1] = false;
              findex_1.binff = 0;
              findex_1.btief = 0;
            } else {
              rspeak_(531);
              f = rmdesc_(0);
            }
          } else if (play_1.here == rindex_1.ledg2 || play_1.here == rindex_1.ledg3 || 
                                  play_1.here == rindex_1.ledg4 || play_1.here == rindex_1.vlbot)
      	    rspeak_(530);
        } else {
    	    --state_1.bloc;
          newsta_(oindex_1.ballo, 0, state_1.bloc, 0, 0);
          if (f) {
      	    f = moveto_(state_1.bloc, play_1.winner);
            rspeak_(534);
            f = rmdesc_(0);
          } else if (play_1.here == rindex_1.ledg2 || play_1.here == rindex_1.ledg3 || play_1.here == rindex_1.ledg4 ||
                      play_1.here == rindex_1.vlbot)
      	    rspeak_(533);
        }
        return;
    	case 7:
    	  for(i = 0; i < objcts_1.olnt; i++) {
        	if(oindex_1.recep == objcts_1.ocan[i] && (objcts_1.oflag1[i] & FLAMBT) != 0) {
            newsta_(i+1, 0, 0, 0, 0);
            findex_1.binff = 0;
            if (play_1.here == state_1.bloc)
        	    rspsub_(292, objcts_1.odesc2[i]);
            return;
        	}
        }
        bug_(4, 0);
    	case 8:
        if (objcts_1.ocan[oindex_1.fuse - 1] != oindex_1.brick) {
    	    if (qhere_(oindex_1.fuse, play_1.here) || objcts_1.oadv[oindex_1.fuse - 1] == play_1.winner)
      	    rspeak_(152);
          newsta_(oindex_1.fuse, 0, 0, 0, 0);
        } else {
          br = objcts_1.oroom[oindex_1.brick - 1];
          bc = objcts_1.ocan[oindex_1.brick - 1];
          if (br == 0 && bc != 0)
      	    br = objcts_1.oroom[bc - 1];
          newsta_(oindex_1.fuse, 0, 0, 0, 0);
          newsta_(oindex_1.brick, 0, 0, 0, 0);
          if (br != 0 && br != play_1.here) {
      	    rspeak_(151);
            state_1.mungrm = br;
            cevent_1.ctick[cindex_1.cevsaf - 1] = 5;
            if(br != rindex_1.msafe) {
              for(i = 0; i < objcts_1.olnt; i++) {
              	if (qhere_(i+1, br) && (objcts_1.oflag1[i] & TAKEBT) != 0)
              	  newsta_(i+1, 0, 0, 0, 0);
              }
              if(br == rindex_1.lroom) {
                for(i = 0; i < objcts_1.olnt; i++) {
                	if (objcts_1.ocan[i] == oindex_1.tcase)
                	    newsta_(i+1, 0, 0, 0, 0);
                }
              }
            } else if(bc == oindex_1.sslot) {
              newsta_(oindex_1.sslot, 0, 0, 0, 0);
              objcts_1.oflag2[oindex_1.safe - 1] |= OPENBT;
              findex_1.safef = true;
            }
          } else {
            rooms_1.rflag[play_1.here - 1] |= RMUNG;
            rrand[play_1.here - 1] = 114;
            jigsup_(150);
          }
        }
        return;
    	case 9:
        rooms_1.rflag[rindex_1.ledg4 - 1] |= RMUNG;
        rrand[rindex_1.ledg4 - 1] = 109;
        if (play_1.here != rindex_1.ledg4) {
          rspeak_(110);
        } else if (advs_1.avehic[play_1.winner - 1] == 0) {
          jigsup_(111);
        } else if (findex_1.btief == 0) {
          rspeak_(112);
        } else {
          state_1.bloc = rindex_1.vlbot;
          newsta_(oindex_1.ballo, 0, 0, 0, 0);
          newsta_(oindex_1.dball, 0, state_1.bloc, 0, 0);
          findex_1.btief = 0;
          findex_1.binff = 0;
          cevent_1.cflag[cindex_1.cevbal - 1] = false;
          cevent_1.cflag[cindex_1.cevbrn - 1] = false;
          jigsup_(113);
        }
        return;
    	case 10:
        rooms_1.rflag[state_1.mungrm - 1] |= RMUNG;
        rrand[state_1.mungrm - 1] = 114;
        if (play_1.here == state_1.mungrm) {
    	    if ((rooms_1.rflag[play_1.here - 1] & RHOUSE) != 0) {
            jigsup_(117);
          } else {
            jigsup_(116);
          }
        } else {
          rspeak_(115);
          if (state_1.mungrm == rindex_1.msafe) {
      	    cevent_1.ctick[cindex_1.cevled - 1] = 8;
          }
        }
        return;
    	case 11:
        if (play_1.here == rindex_1.ledg2 || play_1.here == rindex_1.ledg3 || play_1.here == rindex_1.ledg4 ||
            play_1.here == rindex_1.vlbot) {
          newsta_(oindex_1.gnome, 118, play_1.here, 0, 0);
        } else 
          cevent_1.ctick[cindex_1.cevvlg - 1] = 1;
        return;
    	case 12:
        newsta_(oindex_1.gnome, 149, 0, 0, 0);
        return;
    	case 13:
        if (objcts_1.ocan[oindex_1.water - 1] == oindex_1.bucke)
    	    newsta_(oindex_1.water, 0, 0, 0, 0);
        return;
    	case 14:
        rooms_1.rflag[rindex_1.cager - 1] |= RMUNG;
        rrand[rindex_1.cager - 1] = 147;
        jigsup_(148);
        return;
    	case 15:
        findex_1.endgmf = true;
        rspeak_(119);
        return;
    	case 16:
        cevent_1.cflag[cindex_1.cevfor - 1] = play_1.here == rindex_1.mtree || play_1.here >= rindex_1.fore1
                                            && play_1.here < rindex_1.clear;
        if (cevent_1.cflag[cindex_1.cevfor - 1] && prob_(10, 10))
    	    rspeak_(635);
        return;
    	case 17:
        if (play_1.here == rindex_1.bktwi)
    	    cevent_1.cflag[cindex_1.cevzgi - 1] = true;
        if (play_1.here == rindex_1.bkvau)
    	    jigsup_(636);
        return;
    	case 18:
        cevent_1.cflag[cindex_1.cevzgo - 1] = true;
        newsta_(oindex_1.zgnom, 0, rindex_1.bktwi, 0, 0);
        if (play_1.here == rindex_1.bktwi)
    	    rspeak_(637);
        return;
    	case 19:
        newsta_(oindex_1.zgnom, 0, 0, 0, 0);
        if (play_1.here == rindex_1.bktwi)
    	    rspeak_(638);
        return;
    	case 20:  goto L20000;
    	case 21:
        findex_1.mrpshf = false;
        findex_1.mropnf = false;
        if (play_1.here == rindex_1.mrant)
    	    rspeak_(728);
        if (play_1.here == rindex_1.inmir || mrhere_(play_1.here) == 1)
    	    rspeak_(729);
        return;
    	case 22:
        if (findex_1.wdopnf)
    	    rspeak_(730);
        findex_1.wdopnf = false;
        return;
    	case 23:
        if (advs_1.aroom[aindex_1.player - 1] == rindex_1.fdoor) {
          rspeak_(769);
          rspeak_(findex_1.quesno + 770);
          cevent_1.ctick[cindex_1.cevinq - 1] = 2;
        }
        return;
    	case 24:
        if (advs_1.aroom[aindex_1.amastr - 1] != play_1.here) {
          if (play_1.here != rindex_1.cell && play_1.here != rindex_1.pcell) {
            findex_1.follwf = true;
            i = 812;
            for (j = xsrch_1.xmin; xsrch_1.xmin < 0 ? j >= xsrch_1.xmax : j <= xsrch_1.xmax; j += xsrch_1.xmin) {
            	if (findxt_(j, advs_1.aroom[aindex_1.amastr - 1]) && curxt_1.xroom1 == play_1.here)
            	    i = 813;
            }
            rspeak_(i);
            newsta_(oindex_1.master, 0, play_1.here, 0, 0);
            advs_1.aroom[aindex_1.amastr - 1] = play_1.here;
            return;
          } else {
            if (findex_1.follwf)
        	    rspeak_(811);
            findex_1.follwf = false;
          }
        }
        return;
      default:
        bug_(3, ri);
    }

/* CEV20--	START OF ENDGAME */

L20000:
    if (findex_1.spellf) {
	    goto L20200;
    } else if (play_1.here == rindex_1.crypt) {
      if(! lit_(play_1.here)) {
  	    rspeak_(727);
        goto L20200;
      } else {
        cevent_1.ctick[cindex_1.cevste - 1] = 3;
      }
    }
    return;

    
L20200:
    for(i = 0; i < objcts_1.olnt; i++)
	    newsta_(i+1, 0, objcts_1.oroom[i], objcts_1.ocan[i], 0);
    newsta_(oindex_1.lamp, 0, 0, 0, aindex_1.player);
    newsta_(oindex_1.sword, 0, 0, 0, aindex_1.player);

    objcts_1.oflag1[oindex_1.lamp - 1] = (objcts_1.oflag1[oindex_1.lamp - 1] | LITEBT) & ~ ONBT;
    objcts_1.oflag2[oindex_1.lamp - 1] |= TCHBT;
    cevent_1.cflag[cindex_1.cevlnt - 1] = false;
    cevent_1.ctick[cindex_1.cevlnt - 1] = 350;
    findex_1.orlamp = 0;
    objcts_1.oflag2[oindex_1.sword - 1] |= TCHBT;
    hack_1.swdact = true;
    hack_1.swdsta = 0;

    hack_1.thfact = false;
    findex_1.endgmf = true;
    cevent_1.cflag[cindex_1.cevmat - 1] = false;
    cevent_1.cflag[cindex_1.cevcnd - 1] = false;

    scrupd_(rooms_1.rval[rindex_1.crypt - 1]);
    rooms_1.rval[rindex_1.crypt - 1] = 0;
    f = moveto_(rindex_1.tstrs, play_1.winner);
    f = rmdesc_(3);
    return;

} /* cevapp_ */

static void litint_(int obj, int *ctr, int cev, const int *ticks, int tickln) {
    --ticks;

    ++(*ctr);
    cevent_1.ctick[cev - 1] = ticks[*ctr];
    if (cevent_1.ctick[cev - 1] != 0) {
      objcts_1.oflag1[obj - 1] &= ~ (LITEBT + FLAMBT + ONBT);
      if (objcts_1.oroom[obj - 1] == play_1.here || objcts_1.oadv[obj - 1] == play_1.winner)
  	    rspsub_(293, objcts_1.odesc2[obj - 1]);
    } else if (objcts_1.oroom[obj - 1] == play_1.here || objcts_1.oadv[obj - 1] == play_1.winner)
  	    rspeak_(ticks[*ctr + tickln / 2]);
    return;
}


// demons.c
/* FIGHTD- INTERMOVE FIGHT DEMON */

// #include "funcs.h"
// #include "vars.h"

static bool infest_(int);

void fightd_() {
  /* Initialized data */
  const integer rout = 1;
  /* Local variables */
  bool f;

  for (int i = 0; i < vill_1.vlnt; i++) {
    vill_1.vopps[i] = 0;
    int obj = vill_1.villns[i];
    int ra = objcts_1.oactio[obj - 1];
    if (play_1.here != objcts_1.oroom[obj - 1]) {
    	if((objcts_1.oflag2[obj - 1] & FITEBT) != 0 && ra != 0) {
        prsvec_1.prsa = vindex_1.fightw;
        f = oappli_(ra, 0);
      }
      if (obj == oindex_1.thief)
        findex_1.thfenf = false;
      advs_1.aflag[aindex_1.player - 1] &= ~ aflags_1.astag;
      objcts_1.oflag2[obj - 1] &= ~ (STAGBT + FITEBT);
      if(objcts_1.ocapac[obj - 1] < 0 && ra != 0) {
        prsvec_1.prsa = vindex_1.inxw;
        f = oappli_(ra, 0);
        objcts_1.ocapac[obj - 1] = abs(objcts_1.ocapac[obj - 1]);
      }
    } else if (obj == oindex_1.thief && findex_1.thfenf) {
      if (objcts_1.ocapac[obj - 1] >= 0) {
        if ((objcts_1.oflag2[obj - 1] & FITEBT) == 0) {
        	if(ra != 0) {
          	prsvec_1.prsa = vindex_1.frstqw;
          	if(oappli_(ra, 0)) {
            	objcts_1.oflag2[obj - 1] |= FITEBT;
            	vill_1.vopps[i] = obj;
          	}
        	}
      	} else
          vill_1.vopps[i] = obj;
      } else if (vill_1.vprob[i] == 0 || ! prob_(vill_1.vprob[i], vill_1.vprob[i]))
          vill_1.vprob[i] += 10;
      else {
        objcts_1.ocapac[obj - 1] = abs(objcts_1.ocapac[obj - 1]);
        vill_1.vprob[i] = 0;
        if(ra != 0) {
          prsvec_1.prsa = vindex_1.inxw;
          f = oappli_(ra, 0);
        }
      }
  	}
  }

  int out = 0;
  do {
    for(int i = 0; i < vill_1.vlnt; i++) {
      int j = vill_1.vopps[i];
      if(j != 0) {
        prsvec_1.prscon = 1;
        int ra = objcts_1.oactio[j - 1];
        if(ra != 0) {
          prsvec_1.prsa = vindex_1.fightw;
          if(oappli_(ra, 0))
            continue;
        }

        int res = blow_(aindex_1.player, j, vill_1.vmelee[i], 0, out);
        if(res < 0)
          return;
        if (res == rout)
          out = rnd_(3) + 2;
    	}
    }
    --out;
  } while(out > 0);
}

int blow_(int h, int v, int rmk, bool hflg, int out) {
    /* Initialized data */
    const int rmiss = 0;
    const int rout = 1;
    const int rkill = 2;
    const int rstag = 5;
    const int rlose = 6;
    const int rhes = 7;
    const int rsit = 8;
    static const int def1r[3] = { 1,2,3 };
    static const int def2r[4] = { 13,23,24,25 };
    static const int def3r[5] = { 35,36,46,47,57 };
    static const int rvectr[66] = { 0,0,0,0,5,5,1,1,2,2,2,2,0,0,0,0,0,5,
	    5,3,3,1,0,0,0,5,5,3,3,3,1,2,2,2,0,0,0,0,0,5,5,3,3,4,4,0,0,0,5,5,
	    3,3,3,4,4,4,0,5,5,3,3,3,3,4,4,4 };
    static const int rstate[45] = { 5000,3005,3008,4011,3015,3018,1021,
	    0,0,5022,3027,3030,4033,3037,3040,1043,0,0,4044,2048,4050,4054,
	    5058,4063,4067,3071,1074,4075,1079,4080,4084,4088,4092,4096,4100,
	    1104,4105,2109,4111,4115,4119,4123,4127,3131,3134 };

    /* Local variables */
    int od, def;
    int att, res;
    int dweap;
    int pblose;

    int ra = objcts_1.oactio[v - 1];
    int dv = objcts_1.odesc2[v - 1];
    if(hflg) {
      pblose = 10;
      objcts_1.oflag2[v - 1] |= FITEBT;
      if((advs_1.aflag[h - 1] & aflags_1.astag) != 0) {
        rspeak_(591);
        advs_1.aflag[h - 1] &= ~ aflags_1.astag;
        return rmiss;
      }
      att = fights_(h, 1);
      def = vilstr_(v);
      od = def;
      dweap = 0;
      for(int i = 0; i < objcts_1.olnt; i++) {
      	if(objcts_1.ocan[i] == v && (objcts_1.oflag2[i] & WEAPBT) != 0)
      	    dweap = i+1;
      }
      if (v == advs_1.aobj[aindex_1.player - 1]) {
        jigsup_(593);
        return rmiss;
      }
      if(def == 0){
        rspsub_(592, dv);
        return rmiss;
      }
    } else {
      pblose = 50;
      advs_1.aflag[h - 1] &= ~ aflags_1.astag;
      if((objcts_1.oflag2[v - 1] & STAGBT) != 0) {
        objcts_1.oflag2[v - 1] &= ~ STAGBT;
        rspsub_(594, dv);
        return rmiss;
      }
      att = vilstr_(v);
      def = fights_(h, 1);
      if (def <= 0)
        return rmiss;
      od = fights_(h, 0);
      dweap = abs(fwim_(0, WEAPBT, 0, 0, h, 1));
    }

    if(def <= 0) {
      res = rkill;
      if (hflg)
  	    rspsub_(595, dv);
    } else {
      int tbl;
      if (def < 2) {
        att = min(att,3);
        tbl = def1r[att - 1];
      } else if (def == 2) {
        att = min(att,4);
        tbl = def2r[att - 1];
      } else {
        att -= def;
        att = min(2, max(-2,att)) + 3;
        tbl = def3r[att - 1];
      }
      res = rvectr[tbl + rnd_(10) - 1];
      if(out != 0)
        res = (res == rstag) ? rhes : rsit;
      if(res == rstag && dweap != 0 && prob_(25, pblose))
        res = rlose;
      int mi = rstate[(rmk - 1) * 9 + res];
      if(mi != 0)
        rspsub_(mi % 1000 + rnd_(mi / 1000) + star_1.mbase + 1,
                (hflg || dweap == 0) ? dv : objcts_1.odesc2[dweap - 1]);
    }

    switch(res + 1) {
    	case 1:
    	case 8:
    	  break;
    	case 2:
        if (hflg)
          def = -def;
        break;
    	case 3:
    	case 9:
        def = 0;
        break;
    	case 4:
        def = max(0, def - 1);
        break;
    	case 5:
        def = max(0, def - 2);
        break;
    	case 6:
        if(hflg)
    	    objcts_1.oflag2[v - 1] |= STAGBT;
        else
          advs_1.aflag[h - 1] |= aflags_1.astag;
        break;
    	case 7:
        newsta_(dweap, 0, play_1.here, 0, 0);
        dweap = 0;
        if(!hflg) {
          dweap = fwim_(0, WEAPBT, 0, 0, h, 1);
          if(dweap != 0)
      	    rspsub_(605, objcts_1.odesc2[dweap - 1]);
        }
        break;
    }

    if(!hflg) {
	    advs_1.astren[h - 1] = -10000;
      if (def != 0)
        advs_1.astren[h - 1] = def - od;
      if(def < od) {
        cevent_1.ctick[cindex_1.cevcur - 1] = 30;
        cevent_1.cflag[cindex_1.cevcur - 1] = true;
      }
      if (fights_(h, 1) > 0)
        return res;
      advs_1.astren[h - 1] = 1 - fights_(h, 0);
      jigsup_(596);
      return -1;
    }
    objcts_1.ocapac[v - 1] = def;
    if (def != 0) {
      if (res != rout || ra == 0)
        return res;
      prsvec_1.prsa = vindex_1.outxw;
      oappli_(ra, 0);
      return res;
    }
    objcts_1.oflag2[v - 1] &= ~ FITEBT;
    rspsub_(572, dv);
    newsta_(v, 0, 0, 0, 0);
    if (ra == 0)
      return res;
    prsvec_1.prsa = vindex_1.deadxw;
    oappli_(ra, 0);
    return res;
}

void swordd_() {
  if (objcts_1.oadv[oindex_1.sword - 1] != aindex_1.player) {
    hack_1.swdact = false;
    return;
  }

  int ng = 2;
  if(!infest_(play_1.here)) {
    ng = 1;
    for(int i = xsrch_1.xmin; xsrch_1.xmin < 0 ? i >= xsrch_1.xmax : i <= xsrch_1.xmax; i += xsrch_1.xmin) {
      if(findxt_(i, play_1.here) && (curxt_1.xtype != 2) && infest_(curxt_1.xroom1)) {
        if(ng != hack_1.swdsta) {
          rspeak_(ng + 495);
          hack_1.swdsta = ng;
        }
        return;
      }
    }
    ng = 0;
  }

  if(ng != hack_1.swdsta) {
    rspeak_(ng + 495);
    hack_1.swdsta = ng;
  }
}

static bool infest_(int r) {
    if(!findex_1.endgmf)
      return objcts_1.oroom[oindex_1.cyclo - 1] == r || objcts_1.oroom[oindex_1.troll - 1] == r
          || objcts_1.oroom[oindex_1.thief - 1] == r && hack_1.thfact;
    return r == rindex_1.mrg || r == rindex_1.mrge || r == rindex_1.mrgw || r == rindex_1.inmir
          && findex_1.mloc == rindex_1.mrg;
}


// dgame.c
/* GAME- MAIN COMMAND LOOP FOR DUNGEON */

#include <stdio.h>
#include <string.h>
// #include "funcs.h"
// #include "vars.h"

static bool xvehic_(int);
static void xendmv_ (bool);

void game_() {
    /* Local variables */
    logical f;
    integer i;

    rspeak_(1);
    f = rmdesc_(3);

L100:
    play_1.winner = aindex_1.player;
    play_1.telflg = false;
    if (prsvec_1.prscon <= 1)
      rdline_(input_1.inbuf, 1);

#ifdef ALLOW_GDT
    if (strcmp(input_1.inbuf + prsvec_1.prscon - 1, "GDT") == 0) {
      gdt_();
      goto L100;
    }
#endif /* ALLOW_GDT */

    ++state_1.moves;
    prsvec_1.prswon = parse_(input_1.inbuf, 1);
    if(!prsvec_1.prswon || xvehic_(1)) {
      goto L400;
    }

    if(prsvec_1.prsa == vindex_1.tellw) {
      if((objcts_1.oflag2[prsvec_1.prso - 1] & ACTRBT) != 0) {
        play_1.winner = oactor_(prsvec_1.prso);
        play_1.here = advs_1.aroom[play_1.winner - 1];
        if(prsvec_1.prscon <= 1) {
          rspeak_(play_1.telflg ? 604 : 341);
        } else if (parse_(input_1.inbuf, 1)) {
          if(!aappli_(advs_1.aactio[play_1.winner - 1])) {
            if(!xvehic_(1)) {
              if(prsvec_1.prso == oindex_1.valua || prsvec_1.prso == oindex_1.every) {
                valuac_(oindex_1.valua);
                goto L350;
              } else if(vappli_(prsvec_1.prsa))
                f = rappli_(rooms_1.ractio[play_1.here - 1]);
            }
          }
          xendmv_(play_1.telflg);
        }
        play_1.winner = aindex_1.player;
        play_1.here = advs_1.aroom[play_1.winner - 1];
      } else {
        rspeak_(602);
      }
      goto L350;
    }

L350:
    if(!findex_1.echof && play_1.here == rindex_1.echor) {
	    goto L1000;
    }
    f = rappli_(rooms_1.ractio[play_1.here - 1]);
    goto L400;

L400:
    xendmv_(play_1.telflg);
    if(!lit_(play_1.here))
	    prsvec_1.prscon = 1;
    goto L100;


L1000:
    rdline_(input_1.inbuf, 0);
    ++state_1.moves;
    if(strcmp(input_1.inbuf, "ECHO") == 0) {
      rspeak_(571);
      findex_1.echof = true;
      objcts_1.oflag2[oindex_1.bar - 1] &= ~ SCRDBT;
      prsvec_1.prswon = true;
      prsvec_1.prscon = 1;
      goto L400;
    } else {
      prsvec_1.prswon = parse_(input_1.inbuf, 0);
      if(prsvec_1.prswon && prsvec_1.prsa == vindex_1.walkw) {
        if(findxt_(prsvec_1.prso, play_1.here)) {
          if(prsvec_1.prso == oindex_1.valua || prsvec_1.prso == oindex_1.every) {
            valuac_(oindex_1.valua);
            goto L350;
          } else if(!vappli_(prsvec_1.prsa)) {
            goto L400;
          }
        }
      }
      more_output(input_1.inbuf);
      play_1.telflg = true;
      goto L1000;
    }

} /* game_ */

static void xendmv_(bool flag) {
  if(!flag)
    rspeak_(341);
  if(hack_1.thfact)
    thiefd_();
  if(prsvec_1.prswon)
    fightd_();
  if(hack_1.swdact)
    swordd_();
  if(prsvec_1.prswon)
    clockd_();
  if(prsvec_1.prswon)
    xvehic_(2);
}

static bool xvehic_(int n) {
    int av = advs_1.avehic[play_1.winner - 1];
    if (av != 0) {
	    return oappli_(objcts_1.oactio[av - 1], n);
    }
    return false;
}


// dinit.c
/* INIT-- DUNGEON INITIALIZATION SUBROUTINE */

// #include <stdio.h>
// #include "funcs.h"
// #include "vars.h"

FILE *dbfile;

#ifndef TEXTFILE
#ifdef unix
#define TEXTFILE "/usr/games/lib/dunlib/dtextc.dat"
#else /* ! unix */
 I need a definition for TEXTFILE
#endif /* ! unix */
#endif /* ! TEXTFILE */

#ifndef LOCALTEXTFILE
#define LOCALTEXTFILE "dtextc.dat"
#endif

static inline int rdint(FILE *indxfile) {
  int ch = getc(indxfile);
  return ((ch > 127) ? (ch - 256) : (ch)) * 256 + getc(indxfile);
}

static void rdints(int c, int *pi, FILE *indxfile) {
  while (c-- != 0)
    *pi++ = rdint(indxfile);
}

static void rdpartialints(int c, int *pi, FILE *indxfile) {
  int i;
  while (1) {
  	if(c < 255) {
  	  i = getc(indxfile);
  	  if (i == 255)
  		  return;
  	} else {
  	  i = rdint(indxfile);
  	  if (i == -1)
  		  return;
  	}
  	pi[i] = rdint(indxfile);
  }
}

static void rdflags(int c, bool *pf, FILE *indxfile) {
  while (c-- != 0)
    *pf++ = getc(indxfile);
}

static bool init_failure() {
  more_output("Suddenly a sinister, wraithlike figure appears before you,");
  more_output("seeming to float in the air.  In a low, sorrowful voice he says,");
  more_output("\"Alas, the very nature of the world has changed, and the dungeon");
  more_output("cannot be found.  All must now pass away.\"  Raising his oaken staff");
  more_output("in farewell, he fades into the spreading darkness.  In his place");
  more_output("appears a tastefully lettered sign reading:");
  more_output("");
  more_output("                       INITIALIZATION FAILURE");
  more_output("");
  more_output("The darkness becomes all encompassing, and your vision fails.");
  return false;
}

bool init_() {
  /* Local variables */
  int xmax, r2max, dirmax, recno;
  int i, j, k;
  register int ch;
  register FILE *indxfile;
  int mmax, omax, rmax, vmax, amax, cmax, fmax, smax;

  more_init();

  if (protected()) {
    mmax = 1050;
    omax = 220;
    rmax = 200;
    vmax = 4;
    amax = 4;
    cmax = 25;
    fmax = 46;
    smax = 22;
    xmax = 900;
    r2max = 20;
    dirmax = 15;

    rmsg_1.mlnt = 0;
    objcts_1.olnt = 0;
    rooms_1.rlnt = 0;
    vill_1.vlnt = 0;
    advs_1.alnt = 0;
    cevent_1.clnt = 0;
    exits_1.xlnt = 1;
    oroom2_1.r2lnt = 0;

    state_1.ltshft = 10;
    state_1.mxscor = state_1.ltshft;
    state_1.egscor = 0;
    state_1.egmxsc = 0;
    state_1.mxload = 100;
    state_1.rwscor = 0;
    state_1.deaths = 0;
    state_1.moves = 0;
    time_1.pltime = 0;
    state_1.mungrm = 0;
    state_1.hs = 0;
    prsvec_1.prsa = 0;
    prsvec_1.prsi = 0;
    prsvec_1.prso = 0;
    prsvec_1.prscon = 1;
    orphs_1.oflag = 0;
    orphs_1.oact = 0;
    orphs_1.oslot = 0;
    orphs_1.oprep = 0;
    orphs_1.oname = 0;
    hack_1.thfflg = false;
    hack_1.thfact = true;
    hack_1.swdact = false;
    hack_1.swdsta = 0;

    recno = 1;
    star_1.mbase = 0;

    for (i = 0; i < cmax; ++i) {
    	cevent_1.cflag[i] = false;
    	cevent_1.ctick[i] = 0;
    	cevent_1.cactio[i] = 0;
    }

    for (i = 0; i < fmax; ++i)
	    flags[i] = false;
    findex_1.buoyf = true;
    findex_1.egyptf = true;
    findex_1.cagetf = true;
    findex_1.mr1f = true;
    findex_1.mr2f = true;
    findex_1.follwf = true;
    for (i = 0; i < smax; ++i)
	    switch_[i] = 0;
    findex_1.ormtch = 4;
    findex_1.lcell = 1;
    findex_1.pnumb = 1;
    findex_1.mdir = 270;
    findex_1.mloc = rindex_1.mrb;
    findex_1.cphere = 10;

    for (i = 0; i < r2max; ++i) {
    	oroom2_1.rroom2[i] = 0;
    	oroom2_1.oroom2[i] = 0;
    }

    for (i = 0; i < xmax; ++i)
	    exits_1.travel[i] = 0;

    for (i = 0; i < vmax; ++i) {
    	vill_1.vopps[i] = 0;
    	vill_1.vprob[i] = 0;
    	vill_1.villns[i] = 0;
    	vill_1.vbest[i] = 0;
    	vill_1.vmelee[i] = 0;
    }

    for (i = 0; i < omax; ++i) {
    	objcts_1.odesc1[i] = 0;
    	objcts_1.odesc2[i] = 0;
    	objcts_1.odesco[i] = 0;
    	objcts_1.oread[i] = 0;
    	objcts_1.oactio[i] = 0;
    	objcts_1.oflag1[i] = 0;
    	objcts_1.oflag2[i] = 0;
    	objcts_1.ofval[i] = 0;
    	objcts_1.otval[i] = 0;
    	objcts_1.osize[i] = 0;
    	objcts_1.ocapac[i] = 0;
    	objcts_1.ocan[i] = 0;
    	objcts_1.oadv[i] = 0;
    	objcts_1.oroom[i] = 0;
    }

    for (i = 0; i < rmax; ++i) {
    	rooms_1.rdesc1[i] = 0;
    	rooms_1.rdesc2[i] = 0;
    	rooms_1.ractio[i] = 0;
    	rooms_1.rflag[i] = 0;
    	rooms_1.rval[i] = 0;
    	rooms_1.rexit[i] = 0;
    }

    for (i = 0; i < mmax; ++i)
	    rmsg_1.rtext[i] = 0;

    for (i = 0; i < amax; ++i) {
    	advs_1.aroom[i] = 0;
    	advs_1.ascore[i] = 0;
    	advs_1.avehic[i] = 0;
    	advs_1.aobj[i] = 0;
    	advs_1.aactio[i] = 0;
    	advs_1.astren[i] = 0;
    	advs_1.aflag[i] = 0;
    }

    debug_1.dbgflg = 0;
    debug_1.prsflg = 0;
    debug_1.gdtflg = 0;

#ifdef ALLOW_GDT
    /* allow setting gdtflg true if user id matches wizard id */
    /* this way, the wizard doesn't have to recompile to use gdt */
    if (wizard())
	    debug_1.gdtflg = 1;
#endif /* ALLOW_GDT */

    screen_1.fromdr = 0;
    screen_1.scolrm = 0;
    screen_1.scolac = 0;

    if ((dbfile = fopen(LOCALTEXTFILE, BINREAD)) == NULL && (dbfile = fopen(TEXTFILE, BINREAD)) == NULL) {
	    more_output(NULL);
      printf("I can't open %s.\n", TEXTFILE);
      return init_failure();
    }

    indxfile = dbfile;
    i = rdint(indxfile);
    j = rdint(indxfile);
    k = rdint(indxfile);

    if (i != vers_1.vmaj || j != vers_1.vmin) {
	    more_output(NULL);
      printf("%s is version %1d.%1d%c.\n", TEXTFILE, i, j, k);
      more_output(NULL);
      printf("I require version %1d.%1d%c.\n", vers_1.vmaj, vers_1.vmin,
  	   vers_1.vedit);
      return init_failure();
    }

    state_1.mxscor = rdint(indxfile);
    star_1.strbit = rdint(indxfile);
    state_1.egmxsc = rdint(indxfile);

    rooms_1.rlnt = rdint(indxfile);
    rdints(rooms_1.rlnt, &rooms_1.rdesc1[0], indxfile);
    rdints(rooms_1.rlnt, &rooms_1.rdesc2[0], indxfile);
    rdints(rooms_1.rlnt, &rooms_1.rexit[0], indxfile);
    rdpartialints(rooms_1.rlnt, &rooms_1.ractio[0], indxfile);
    rdpartialints(rooms_1.rlnt, &rooms_1.rval[0], indxfile);
    rdints(rooms_1.rlnt, &rooms_1.rflag[0], indxfile);

    exits_1.xlnt = rdint(indxfile);
    rdints(exits_1.xlnt, &exits_1.travel[0], indxfile);

    objcts_1.olnt = rdint(indxfile);
    rdints(objcts_1.olnt, &objcts_1.odesc1[0], indxfile);
    rdints(objcts_1.olnt, &objcts_1.odesc2[0], indxfile);
    rdpartialints(objcts_1.olnt, &objcts_1.odesco[0], indxfile);
    rdpartialints(objcts_1.olnt, &objcts_1.oactio[0], indxfile);
    rdints(objcts_1.olnt, &objcts_1.oflag1[0], indxfile);
    rdpartialints(objcts_1.olnt, &objcts_1.oflag2[0], indxfile);
    rdpartialints(objcts_1.olnt, &objcts_1.ofval[0], indxfile);
    rdpartialints(objcts_1.olnt, &objcts_1.otval[0], indxfile);
    rdints(objcts_1.olnt, &objcts_1.osize[0], indxfile);
    rdpartialints(objcts_1.olnt, &objcts_1.ocapac[0], indxfile);
    rdints(objcts_1.olnt, &objcts_1.oroom[0], indxfile);
    rdpartialints(objcts_1.olnt, &objcts_1.oadv[0], indxfile);
    rdpartialints(objcts_1.olnt, &objcts_1.ocan[0], indxfile);
    rdpartialints(objcts_1.olnt, &objcts_1.oread[0], indxfile);

    oroom2_1.r2lnt = rdint(indxfile);
    rdints(oroom2_1.r2lnt, &oroom2_1.oroom2[0], indxfile);
    rdints(oroom2_1.r2lnt, &oroom2_1.rroom2[0], indxfile);

    cevent_1.clnt = rdint(indxfile);
    rdints(cevent_1.clnt, &cevent_1.ctick[0], indxfile);
    rdints(cevent_1.clnt, &cevent_1.cactio[0], indxfile);
    rdflags(cevent_1.clnt, &cevent_1.cflag[0], indxfile);

    vill_1.vlnt = rdint(indxfile);
    rdints(vill_1.vlnt, &vill_1.villns[0], indxfile);
    rdpartialints(vill_1.vlnt, &vill_1.vprob[0], indxfile);
    rdpartialints(vill_1.vlnt, &vill_1.vopps[0], indxfile);
    rdints(vill_1.vlnt, &vill_1.vbest[0], indxfile);
    rdints(vill_1.vlnt, &vill_1.vmelee[0], indxfile);

    advs_1.alnt = rdint(indxfile);
    rdints(advs_1.alnt, &advs_1.aroom[0], indxfile);
    rdpartialints(advs_1.alnt, &advs_1.ascore[0], indxfile);
    rdpartialints(advs_1.alnt, &advs_1.avehic[0], indxfile);
    rdints(advs_1.alnt, &advs_1.aobj[0], indxfile);
    rdints(advs_1.alnt, &advs_1.aactio[0], indxfile);
    rdints(advs_1.alnt, &advs_1.astren[0], indxfile);
    rdpartialints(advs_1.alnt, &advs_1.aflag[0], indxfile);

    star_1.mbase = rdint(indxfile);
    rmsg_1.mlnt = rdint(indxfile);
    rdints(rmsg_1.mlnt, &rmsg_1.rtext[0], indxfile);

    rmsg_1.mrloc = ftell(indxfile);

    itime_(&time_1.shour, &time_1.smin, &time_1.ssec);

    play_1.winner = aindex_1.player;
    last_1.lastit = advs_1.aobj[aindex_1.player - 1];
    play_1.here = advs_1.aroom[play_1.winner - 1];
    hack_1.thfpos = objcts_1.oroom[oindex_1.thief - 1];
    state_1.bloc = objcts_1.oroom[oindex_1.ballo - 1];
    return true;
  }
  more_output("There appears before you a threatening figure clad all over");
  more_output("in heavy black armor.  His legs seem like the massive trunk");
  more_output("of the oak tree.  His broad shoulders and helmeted head loom");
  more_output("high over your own puny frame, and you realize that his powerful");
  more_output("arms could easily crush the very life from your body.  There");
  more_output("hangs from his belt a veritable arsenal of deadly weapons:");
  more_output("sword, mace, ball and chain, dagger, lance, and trident.");
  more_output("He speaks with a commanding voice:");
  more_output("");
  more_output("                    \"You shall not pass.\"");
  more_output("");
  more_output("As he grabs you by the neck all grows dim about you.");
  exit_();
}


//dso1.c
/* PRINCR- PRINT CONTENTS OF ROOM */

// #include "funcs.h"
// #include "vars.h"

void princr_(bool full, int rm) {
  int j = 329;
  for(int i = 0; i < objcts_1.olnt; i++) {
  	if(qhere_(i+1, rm) && (objcts_1.oflag1[i] & VISIBT + NDSCBT) == VISIBT && i+1 != advs_1.avehic[play_1.winner - 1]) {
    	if(!full && (findex_1.superf || findex_1.brieff && (rooms_1.rflag[play_1.here - 1] & RSEEN) != 0)) {
      	rspsub_(j, objcts_1.odesc2[i]);
      	j = 502;
    	} else {
      	int k = objcts_1.odesco[i];
      	if (k == 0 || (objcts_1.oflag2[i] & TCHBT) != 0)
      	  k = objcts_1.odesc1[i];
      	rspeak_(k);
    	}
    }
  }

  for(int i = 0; i < objcts_1.olnt; i++) {
  	if(qhere_(i+1, rm) && (objcts_1.oflag1[i] & VISIBT + NDSCBT) == VISIBT) {
    	if((objcts_1.oflag2[i] & ACTRBT) != 0)
        invent_(oactor_(i+1));
    	if((objcts_1.oflag1[i] & TRANBT) != 0 || (objcts_1.oflag2[i] & OPENBT) != 0 && !qempty_(i+1)) {
      	if(i+1 == oindex_1.tcase) {
        	if((!findex_1.brieff && !findex_1.superf) || full)
        	  princo_(i+1, 574);
      	} else
      	  princo_(i+1, 573);
    	}
  	}
  }
}

void invent_(int adv) {
  int i = (adv != aindex_1.player) ? 576 : 575;
  for(int j = 0; j < objcts_1.olnt; j++) {
  	if(objcts_1.oadv[j] == adv && (objcts_1.oflag1[j] & VISIBT) != 0) {
    	rspsub_(i, objcts_1.odesc2[advs_1.aobj[adv - 1] - 1]);
    	i = 0;
    	rspsub_(502, objcts_1.odesc2[j]);
  	}
  }

  if (i == 0) {
    for(int j = 0; j < objcts_1.olnt; j++) {
    	if(objcts_1.oadv[j] == adv && (objcts_1.oflag1[j] & VISIBT) != 0 &&
    	    (objcts_1.oflag1[j] & TRANBT) != 0 || (objcts_1.oflag2[j] & OPENBT) != 0) {
      	if(!qempty_(j+1))
      	    princo_(j+1, 573);
    	}
    }
  }
  if (adv == aindex_1.player)
    rspeak_(578);
  return;
}

void princo_(int obj, int desc) {
    rspsub_(desc, objcts_1.odesc2[obj - 1]);
    for(int i = 0; i < objcts_1.olnt; i++) {
    	if (objcts_1.ocan[i] == obj)
    	    rspsub_(502, objcts_1.odesc2[i]);
    }
}


// dso2.c
/* MOVETO- MOVE PLAYER TO NEW ROOM */

// #include <stdio.h>
// #include "funcs.h"
// #include "vars.h"

bool moveto_(int nr, int who) {
  bool lnr = (rooms_1.rflag[nr - 1] & RLAND) != 0;
  int j = advs_1.avehic[who - 1];
  if (j != 0) {
    int bits = 0;
    if (j == oindex_1.rboat)
	    bits = RWATER;
    if (j == oindex_1.ballo)
    	bits = RAIR;
    if (j == oindex_1.bucke)
	    bits = RBUCK;
    bool nlv = (rooms_1.rflag[nr - 1] & bits) == 0;
    if (! lnr && nlv || lnr && ((rooms_1.rflag[play_1.here - 1] & RLAND) != 0) && nlv && bits != RLAND) {
      rspsub_(428, objcts_1.odesc2[j - 1]);
      return false;
    }
  } else if(!lnr) {
    rspeak_(427);
    return false;
  }
  if ((rooms_1.rflag[nr - 1] & RMUNG) == 0) {
    if (who != aindex_1.player)
	    newsta_(advs_1.aobj[who - 1], 0, nr, 0, 0);
    if (j != 0)
	    newsta_(j, 0, nr, 0, 0);
    play_1.here = nr;
    advs_1.aroom[who - 1] = play_1.here;
    scrupd_(rooms_1.rval[nr - 1]);
    rooms_1.rval[nr - 1] = 0;
    return true;
  }
  rspeak_(rrand[nr - 1]);
  return true;
}

void score_(bool flg) {
  /* Initialized data */
  static const integer rank[10] = { 20,19,18,16,12,8,4,2,1,0 };
  static const integer erank[5] = { 20,15,10,5,0 };

  int as = advs_1.ascore[play_1.winner - 1];
  if(!findex_1.endgmf) {
    more_output(NULL);
    printf("Your score ");
    if(flg)
	    printf("would be");
    else
	    printf("is");
    printf(" %d [total of %d points], in %d move", as, state_1.mxscor, state_1.moves);
    if(state_1.moves != 1)
	    printf("s");
    printf(".\n");

    for(int i = 0; i < 10; i++) {
    	if(as * 20 / state_1.mxscor >= rank[i]) {
        rspeak_(i + 485);
        return;
    	}
    }
  }
  more_output(NULL);
  printf("Your score in the endgame ");
  if (flg)
    printf("would be");
  else
    printf("is");
  printf(" %d [total of %d points], in %d moves.\n", state_1.egscor, state_1.egmxsc, state_1.moves);

  int i;
  for(i = 0; i < 5; i++) {
  	if (state_1.egscor * 20 / state_1.egmxsc >= erank[i])
  	  break;
  }
  rspeak_(i + 787);
}

void scrupd_(int n) {
    if(findex_1.endgmf) {
      state_1.egscor += n;
    } else {
      advs_1.ascore[play_1.winner - 1] += n;
      state_1.rwscor += n;
      if (advs_1.ascore[play_1.winner - 1] >= state_1.mxscor - state_1.deaths * 10) {
        cevent_1.cflag[cindex_1.cevegh - 1] = true;
        cevent_1.ctick[cindex_1.cevegh - 1] = 15;
      }
    }
}


// dso3.c
/* FINDXT- FIND EXIT FROM ROOM */

// #include <stdio.h>
// #include "funcs.h"
// #include "vars.h"

bool findxt_(int dir, int rm) {
  int xi = rooms_1.rexit[rm - 1];
  if (xi == 0)
    return false;

  int i;
  do {
    i = exits_1.travel[xi - 1];
    curxt_1.xroom1 = i & xpars_1.xrmask; // mask to 16-bits to get rid of sign extension problems with 32-bit ints
    int xxxflg = ~ xpars_1.xlflag & 65535;
    curxt_1.xtype = ((i & xxxflg) / xpars_1.xfshft & xpars_1.xfmask) + 1;
    switch (curxt_1.xtype) {
    	case 4:
    	case 3:
        curxt_1.xobj = exits_1.travel[xi + 1] & xpars_1.xrmask;
        curxt_1.xactio = exits_1.travel[xi + 1] / xpars_1.xashft;
        // There is intentionally no break here.
    	case 2:
        curxt_1.xstrng = exits_1.travel[xi];
        // There is intentionally no break here.
    	case 1:
        xi += xpars_1.xelnt[curxt_1.xtype - 1];
        if ((i & xpars_1.xdmask) == dir)
    	    return true;
        break;
      default:
        bug_(10, curxt_1.xtype);
    }
  } while((i & xpars_1.xlflag) == 0);
  return false;
}

int fwim_(int f1, int f2, int rm, int con, int adv, bool nocare) {
    int ret_val = 0;
    for(int i = 0; i < objcts_1.olnt; i++) {
    	if ((rm && objcts_1.oroom[i] == rm) ||
    	    (adv && objcts_1.oadv[i] == adv) ||
    	    (con && objcts_1.ocan[i] == con)) {
      	if(objcts_1.oflag1[i] & VISIBT) {
        	if(~nocare & (objcts_1.oflag1[i] & TAKEBT) == 0 || (objcts_1.oflag1[i] & f1) == 0 &&
              (objcts_1.oflag2[i] & f2) == 0 || ret_val == 0) {
          	if (ret_val == 0)
            	ret_val = i+1;
          	if(objcts_1.oflag2[i] & OPENBT) {
            	for(int j = 0; j <= objcts_1.olnt; j++) {
            	  if(objcts_1.ocan[j] == i+1 && (objcts_1.oflag1[j] & VISIBT) &&
            	      (objcts_1.oflag1[j] & f1) || (objcts_1.oflag2[j] & f2)) {
                  if(ret_val)
                    return -ret_val;
              	}
              	ret_val = j+1;
            	}
          	}
        	} else
          	return -ret_val;
      	}
    	}
    }
    return ret_val;
}

bool yesno_(int q, int y, int n) {
    char ans[100];

  while(true) {
    rspeak_(q);
    fflush(stdout);
    fgets(ans, sizeof ans, stdin);
    more_input();
    if (*ans == 'Y' || *ans == 'y') {
      rspeak_(y);
      return true;
    }
    if (*ans == 'N' || *ans == 'n') {
      rspeak_(n);
      return false;
    }
    rspeak_(6);
  }
}


// dso4.c
/* ROBADV-- STEAL WINNER'S VALUABLES */

// #include "funcs.h"
// #include "vars.h"

int robadv_(int adv, int nr, int nc, int na) {
  int ret_val = 0;
  for(int i = 0; i < objcts_1.olnt; i++) {
  	if(objcts_1.oadv[i] == adv && objcts_1.otval[i] > 0 && (objcts_1.oflag2[i] & SCRDBT) == 0) {
    	newsta_(i+1, 0, nr, nc, na);
    	++ret_val;
  	}
  }
  return ret_val;
}

int robrm_(int rm, int pr, int nr, int nc, int na) {
  int ret_val = 0;
  for(int i = 0; i < objcts_1.olnt; i++) {
  	if(qhere_(i+1, rm)) {
    	if(objcts_1.otval[i] <= 0 || (objcts_1.oflag2[i] & SCRDBT) != 0 ||
    	    (objcts_1.oflag1[i] & VISIBT) == 0 || ! prob_(pr, pr)) {
      	if ((objcts_1.oflag2[i] & ACTRBT) != 0)
      	  ret_val += robadv_(oactor_(i+1), nr, nc, na);
    	} else {
      	newsta_(i+1, 0, nr, nc, na);
      	++ret_val;
      	objcts_1.oflag2[i] |= TCHBT;
    	}
  	}
  }
  return ret_val;
}

bool winnin_(int vl, int hr) {
    int vs = objcts_1.ocapac[vl - 1];
    int ps = vs - fights_(hr, 1);
    if (ps > 3)
	    return prob_(90, 100);
    if (ps > 0)
	    return prob_(75, 85);
    if (ps == 0)
	    return prob_(50, 30);
    if (vs > 1)
	    return prob_(25, 25);
    return prob_(10, 0);
}

int fights_(int h, bool flg) {
    /* Initialized data */
    const integer smin = 2;
    const integer smax = 7;

    return smin + ((smax - smin) * advs_1.ascore[h - 1] + state_1.mxscor / 2) / state_1.mxscor
                + (flg ? advs_1.astren[h - 1] : 0);
}

int vilstr_(int v) {
  int ret_val = objcts_1.ocapac[v - 1];
  if(ret_val <= 0)
    return ret_val;
  if (v == oindex_1.thief && findex_1.thfenf) {
    findex_1.thfenf = false;
    ret_val = min(ret_val,2);
  }
  for(int i = 0; i < vill_1.vlnt; i++) {
  	if (vill_1.villns[i] == v && prsvec_1.prsi == vill_1.vbest[i])
	    ret_val = max(1, ret_val - 1);
  }
  return ret_val;
}


// dso5.c
// #include "funcs.h"
// #include "vars.h"

int gttime_() {
  int h, m, s;

  itime_(&h, &m, &s);
  int t = h * 60 + m - (time_1.shour * 60 + time_1.smin);
  if(t < 0)
    t += 1440;
  return t + time_1.pltime;
}

bool opncls_(int obj, int so, int sc) {
  if(prsvec_1.prsa == vindex_1.closew) {
    if((objcts_1.oflag2[obj - 1] & OPENBT) != 0) {
      rspeak_(sc);
      objcts_1.oflag2[obj - 1] &= ~ OPENBT;
      return true;
    }
    rspeak_(rnd_(3) + 125);
    return true;
  }
  if(prsvec_1.prsa == vindex_1.openw) {
    if((objcts_1.oflag2[obj - 1] & OPENBT) == 0) {
      rspeak_(so);
      objcts_1.oflag2[obj - 1] |= OPENBT;
      return true;
    }
    rspeak_(rnd_(3) + 125);
    return true;
  }
  return false;
}

bool lit_(int rm) {
    if ((rooms_1.rflag[rm - 1] & RLIGHT) != 0)
	    return true;

    for(int i = 0; i < objcts_1.olnt; i++) {
    	if(!qhere_(i+1, rm)) {
      	int oa = objcts_1.oadv[i];
      	if (oa <= 0)
      	  continue;
      	if (advs_1.aroom[oa - 1] != rm)
      	  continue;
    	}
    	if ((objcts_1.oflag1[i] & ONBT) != 0)
    	  return true;
    	if((objcts_1.oflag1[i] & VISIBT) && (objcts_1.oflag1[i] & TRANBT) || (objcts_1.oflag2[i] & OPENBT))
      	for (int j = 0; j < objcts_1.olnt; j++)
      	  if (objcts_1.ocan[j] == i+1 && (objcts_1.oflag1[j] & ONBT) != 0)
      		  return true;
    }
    return false;
}

int weight_(int rm, int cn, int ad) {
  int ret_val = 0;
  for(int i = 0; i < objcts_1.olnt; i++) {
  	if(objcts_1.osize[i] < 10000) {
    	if(qhere_(i+1, rm) && rm != 0 || objcts_1.oadv[i] == ad && ad != 0) {
      	ret_val += objcts_1.osize[i];
    	} else {
        for(int j=objcts_1.ocan[i]; j!=cn; j=objcts_1.ocan[j-1]) {
          if(j == 0)
            break;
          if(j == cn) {
            ret_val += objcts_1.osize[i];
            break;
          }
        }
    	}
  	}
  }
  return ret_val;
}


// dso6.c
/* GHERE--	IS GLOBAL ACTUALLY IN THIS ROOM? */

// #include "funcs.h"
// #include "vars.h"

bool ghere_(int obj, int rm) {
  switch (obj - star_1.strbit) {
  	case 1:
  	case 2:
  	case 3:
  	case 4:
  	case 5:
  	case 6:
  	case 7:
  	case 8:
  	case 9:
  	case 10:
  	case 11:
  	  return true;
  	case 12:
  	  return rm >= rindex_1.fore1 && rm < rindex_1.clear || rm == rindex_1.mtree;
  	case 13:
      return rm >= rindex_1.fore1 && rm < rindex_1.clear && rm != rindex_1.fore3;
  	case 14:
      return rm >= rindex_1.bkvw && rm <= rindex_1.bkbox || rm == rindex_1.cpuzz;
  	case 15:
  	case 16:
  	case 17:
      return rm >= rindex_1.bkvw && rm < rindex_1.bkbox || rm == rindex_1.cpuzz;
  	case 18:
      return (rooms_1.rflag[rm - 1] & RWATER + RFILL) != 0;
  	case 19:
      return rm >= rindex_1.mrc && rm <= rindex_1.mrd || rm >= rindex_1.mrce && rm <= rindex_1.mrdw
          || rm == rindex_1.inmir;
  	case 20:
  	case 23:
      return rm >= rindex_1.mra && rm <= rindex_1.mrd || rm == rindex_1.inmir;
  	case 22:
      if (rm == rindex_1.fdoor)
  	    return true;
  	  // There is intentionally no break here.
  	case 21:
      return rm >= rindex_1.mra && rm <= rindex_1.mrc || rm >= rindex_1.mrae && rm <= rindex_1.mrcw;
  	case 24:
      return rm == rindex_1.fdoor || rm == rindex_1.ncorr || rm == rindex_1.parap || rm == rindex_1.cell;
  	case 25:
      return rm == rindex_1.cpuzz;
  	default:
  	  bug_(60, obj);
  }
}

int mrhere_(int rm) {
    if (rm < rindex_1.mrae || rm > rindex_1.mrdw) {
      if (abs(findex_1.mloc - rm) != 1 || findex_1.mdir % 180 == 0)
  	    return 0;
      return (rm < findex_1.mloc && findex_1.mdir < 180 || rm > findex_1.mloc && findex_1.mdir > 180) ? 2 : 1;
    }
    return ((rm - rindex_1.mrae) % 2 == findex_1.mdir / 180) ? 2 : 1;
}


// dso7.c
/* ENCRYP--	ENCRYPT PASSWORD */

// #include <stdio.h>
// #include "funcs.h"
// #include "vars.h"

void encryp_(const char *inw, char *outw) {
    int uinw[6];
    char ukeyw[1*6];

    int uinws = 0;
    int ukeyws = 0;
    int j = 0;
    for(int i = 0; i < 6; ++i) {
    	ukeyw[i] = ("ECORMS"[i] - 64);
    	if(inw[j] <= '@')
    	  j = 0;
    	uinw[i] = inw[j] - 64;
    	ukeyws += ukeyw[i];
    	uinws += uinw[i];
    	j++;
    }

    int usum = uinws % 8 + (ukeyws % 8 << 3);
    for(int i = 0; i < 6; ++i) {
    	j = (uinw[i] ^ ukeyw[i] ^ usum) & 31;
    	usum = (usum + 1) % 32;
    	if(j > 26)
    	  j %= 26;
    	outw[i] = (max(1,j) + 64);
    }
}

void cpgoto_(int st) {
    rooms_1.rflag[rindex_1.cpuzz - 1] &= ~ RSEEN;
    for(int i = 0; i < objcts_1.olnt; i++) {
    	if (objcts_1.oroom[i] == rindex_1.cpuzz && (objcts_1.oflag2[i] & ACTRBT + VILLBT) == 0)
  	    newsta_(i+1, 0, findex_1.cphere * hyper_1.hfactr, 0, 0);
    	if(objcts_1.oroom[i] == st * hyper_1.hfactr)
  	    newsta_(i+1, 0, rindex_1.cpuzz, 0, 0);
    }
    findex_1.cphere = st;
}

void cpinfo_(int rmk, int st) {
  static const int dgmoft[8] = { -9,-8,-7,-1,1,7,8,9 };
  char dgm[1*8];

  rspeak_(rmk);
  for(int i = 0; i < 8; ++i) {
  	int j = dgmoft[i];
  	dgm[i] = "SSS M"[puzzle_1.cpvec[st + j - 1] + 3];
  	if(abs(j) != 1 && abs(j) != 8) {
    	int k = (j < 0) ? 0 : 8;
    	if(puzzle_1.cpvec[st + k - 1] && puzzle_1.cpvec[st + j - k - 1])
    	  dgm[i] = '?';
    }
  }

  more_output(NULL);
  printf("       |%c%c %c%c %c%c|\n", dgm[0], dgm[0], dgm[1], dgm[1], dgm[2], dgm[2]);
  more_output(NULL);
  printf(" West  |%c%c .. %c%c| East\n", dgm[3], dgm[3], dgm[4], dgm[4]);
  more_output(NULL);
  printf("       |%c%c %c%c %c%c|\n", dgm[5], dgm[5], dgm[6], dgm[6], dgm[7], dgm[7]);

  if(st == 10)
  	rspeak_(870);
  if(st == 37)
  	rspeak_(871);
  if(st == 52)
  	rspeak_(findex_1.cpoutf ? 873 : 872);
  if(puzzle_1.cpvec[st] == -2)
    rspeak_(874);
  if (puzzle_1.cpvec[st - 2] == -3)
  	rspeak_(875);
}


// dsub.c
/* RESIDENT SUBROUTINES FOR DUNGEON */

// #include <stdio.h>
// #include "funcs.h"
// #include "vars.h"

#ifndef SEEK_SET
#define SEEK_SET (0)
#endif

extern FILE *dbfile;

static void rspsb2nl_(int, int, int, bool);

void rspeak_(int n) {
    rspsb2nl_(n, 0, 0, true);
}

void rspsub_(int n, int s1) {
    rspsb2nl_(n, s1, 0, true);
}

void rspsb2_(int n, int s1, int s2) {
    rspsb2nl_(n, s1, s2, true);
}

static void rspsb2nl_(int n, int y, int z, bool nl) {
    const char *zkey = "IanLanceTaylorJr";
    long x = (long)n;

    if (x > 0)
	    x = rmsg_1.rtext[x - 1];
    if (x == 0)
	    return;
    play_1.telflg = true;

    x = ((- x) - 1) * 8;
    if (fseek(dbfile, x + (long)rmsg_1.mrloc, SEEK_SET) == EOF) {
	    fprintf(stderr, "Error seeking database loc %d\n", x);
	    exit_();
    }

    if (nl)
	    more_output(NULL);

    while (1) {
    	int i = getc(dbfile);
    	if(i == EOF) {
    	  fprintf(stderr, "Error reading database loc %d\n", x);
    	  exit_();
    	}
    	i ^= zkey[x & 0xf] ^ (x & 0xff);
    	x = x + 1;
    	if(i == '\0')
    	  break;
    	else if (i == '\n') {
    	  putchar('\n');
    	  if (nl)
    		more_output(NULL);
    	}
    	else if (i == '#' && y != 0) {
    	  long iloc = ftell(dbfile);
    	  rspsb2nl_(y, 0, 0, 0);
    	  if (fseek(dbfile, iloc, SEEK_SET) == EOF) {
      		fprintf(stderr, "Error seeking database loc %d\n", iloc);
      		exit_();
      	}
    	  y = z;
    	  z = 0;
    	} else
    	  putchar(i);
    }
    if (nl)
	    putchar('\n');
}

bool objact_() {
    /* System generated locals */
    if (prsvec_1.prsi != 0) {
      if (oappli_(objcts_1.oactio[prsvec_1.prsi - 1], 0)) {
  	    return true;
      }
    }
    if (prsvec_1.prso == 0) {
      return false;
    }
    if (oappli_(objcts_1.oactio[prsvec_1.prso - 1], 0)) {
	    return true;
    }
    return false;
}

void bug_(int a, int b) {
    more_output(NULL);
    printf("PROGRAM ERROR %d, PARAMETER=%d\n", a, b);
    if(debug_1.dbgflg != 0)
	    return;
    exit_();
}

void newsta_(int o, int r, int rm, int cn, int ad) {
    rspeak_(r);
    objcts_1.oroom[o - 1] = rm;
    objcts_1.ocan[o - 1] = cn;
    objcts_1.oadv[o - 1] = ad;
}

bool qhere_(int obj, int rm) {
    if (objcts_1.oroom[obj - 1] == rm)
	    return true;
    for (int i = 0; i < oroom2_1.r2lnt; i++) {
    	if (oroom2_1.oroom2[i] == obj && oroom2_1.rroom2[i] == rm)
    	  return true;
    }
    return false;
}

bool qempty_(int obj) {
    for (int i = 0; i < objcts_1.olnt; i++) {
    	if (objcts_1.ocan[i] == obj)
    	    return false;
    }
    return true;
}

void jigsup_(int desc) {
    rspeak_(desc);
    prsvec_1.prscon = 1;
    if (debug_1.dbgflg != 0)
	    return;
    advs_1.avehic[play_1.winner - 1] = 0;
    if (play_1.winner == aindex_1.player) {
      if (findex_1.endgmf)
        rspeak_(625);
      else
        rspeak_(7);
      score_(0);
      (void) fclose(dbfile);
      exit_();
    }
    rspsub_(432, objcts_1.odesc2[advs_1.aobj[play_1.winner - 1] - 1]);
    newsta_(advs_1.aobj[play_1.winner - 1], 0, 0, 0, 0);
    return;
}

int oactor_(int obj) {
    for(int i = 0; i < advs_1.alnt; i++) {
    	if(advs_1.aobj[i] == obj)
    	    return i+1;
    }
    bug_(40, obj);
    return advs_1.alnt;
}

bool prob_(int g, int b) {
    int i = g;
    if (findex_1.badlkf)
	    i = b;
    return rnd_(100) < i;
}

bool rmdesc_(int full) {
  if (prsvec_1.prso >= xsrch_1.xmin) {
    screen_1.fromdr = prsvec_1.prso;
    prsvec_1.prso = 0;
  }
  if (play_1.here != advs_1.aroom[aindex_1.player - 1]) {
    rspeak_(2);
    prsvec_1.prsa = vindex_1.walkiw;
    return true;
  }

  int ra;
  do {
    if(!lit_(play_1.here)) {
      rspeak_(430);
      return false;
    } else {
      ra = rooms_1.ractio[play_1.here - 1];
      if (full != 1) {
        int i = rooms_1.rdesc2[play_1.here - 1];
        if (full == 0 && (findex_1.superf || (rooms_1.rflag[play_1.here - 1] & RSEEN) != 0 && findex_1.brieff)) {
          rspeak_(i);
        } else {
          i = rooms_1.rdesc1[play_1.here - 1];
          if (i != 0 || ra == 0) {
            rspeak_(i);
          } else {
            prsvec_1.prsa = vindex_1.lookw;
            if(! rappli_(ra)) {
        	    continue;
            }
            prsvec_1.prsa = vindex_1.foow;
          }
        }
        if (advs_1.avehic[play_1.winner - 1] != 0)
    	    rspsub_(431, objcts_1.odesc2[advs_1.avehic[play_1.winner - 1] - 1]);
      }
    }
    if (full != 2)
    	princr_(full != 0, play_1.here);
    rooms_1.rflag[play_1.here - 1] |= RSEEN;
    if (full != 0 || ra == 0)
    	return true;
    prsvec_1.prsa = vindex_1.walkiw;
  } while(!rappli_(ra));
  prsvec_1.prsa = vindex_1.foow;
  return true;
}

bool rappli_(int ri) {
    const int newrms = 38;

    if (ri == 0)
	    return true;
    if (ri < newrms)
	    return rappl1_(ri);
    if (ri >= newrms)
	    return rappl2_(ri);
    return true;
}


// dverb1.c
/* TAKE-- BASIC TAKE SEQUENCE */

// #include "funcs.h"
// #include "vars.h"

bool take_(bool flg) {
  int oa = objcts_1.oactio[prsvec_1.prso - 1];
  if(prsvec_1.prso > star_1.strbit)
    return objact_();

  int x = objcts_1.ocan[prsvec_1.prso - 1];
  if(prsvec_1.prso == advs_1.avehic[play_1.winner - 1]) {
    rspeak_(672);
    return false;
  }

  if((objcts_1.oflag1[prsvec_1.prso - 1] & TAKEBT) == 0) {
    if(!oappli_(oa, 0))
    	rspeak_(rnd_(5) + 552);
    return false;
  }

  if(x == 0 && !qhere_(prsvec_1.prso, play_1.here)) {
    if(objcts_1.oadv[prsvec_1.prso - 1] == play_1.winner)
      rspeak_(557);
    return false;
  }

  if(x == 0 || objcts_1.oadv[x - 1] != play_1.winner &&
      weight_(0,prsvec_1.prso, play_1.winner) + objcts_1.osize[prsvec_1.prso - 1] > state_1.mxload) {
    rspeak_(558);
    return false;
  }

  if(oappli_(oa, 0))
    return true;
  newsta_(prsvec_1.prso, 0, 0, 0, play_1.winner);
  objcts_1.oflag2[prsvec_1.prso - 1] |= TCHBT;
  scrupd_(objcts_1.ofval[prsvec_1.prso - 1]);
  objcts_1.ofval[prsvec_1.prso - 1] = 0;
  if(flg)
    rspeak_(559);
  return true;
}

bool drop_(bool z) {
  int x = objcts_1.ocan[prsvec_1.prso - 1];
  if(x != 0 || objcts_1.oadv[prsvec_1.prso - 1] == play_1.winner && objcts_1.oadv[x - 1] == play_1.winner) {
    if ((objcts_1.oflag2[x - 1] & OPENBT) != 0) {
      if(advs_1.avehic[play_1.winner - 1] != 0) {
        prsvec_1.prsi = advs_1.avehic[play_1.winner - 1];
        put_(1);
        prsvec_1.prsi = 0;
        return true;
      }
      newsta_(prsvec_1.prso, 0, play_1.here, 0, 0);
      if (play_1.here == rindex_1.mtree)
        newsta_(prsvec_1.prso, 0, rindex_1.fore3, 0, 0);
      scrupd_(objcts_1.ofval[prsvec_1.prso - 1]);
      objcts_1.ofval[prsvec_1.prso - 1] = 0;
      objcts_1.oflag2[prsvec_1.prso - 1] |= TCHBT;
  
      if(objact_())
        return true;
      int i = 0;
      if(prsvec_1.prsa == vindex_1.dropw)
        i = 528;
      if(prsvec_1.prsa == vindex_1.throww)
        i = 529;
      if(i != 0 && play_1.here == rindex_1.mtree)
        i = 659;
      rspsub_(i, objcts_1.odesc2[prsvec_1.prso - 1]);
      return true;
    }
    rspsub_(525, objcts_1.odesc2[x - 1]);
    return true;
  }

  rspeak_(527);
  return true;
}

bool put_(bool flg) {
  if(prsvec_1.prso > star_1.strbit || prsvec_1.prsi > star_1.strbit) {
    if(!objact_())
      rspeak_(560);
    return true;
  }

  if((objcts_1.oflag2[prsvec_1.prsi - 1] & OPENBT) == 0 && (objcts_1.oflag1[prsvec_1.prsi - 1] & DOORBT + CONTBT) == 0
      && (objcts_1.oflag2[prsvec_1.prsi - 1] & VEHBT) == 0) {
    rspeak_(561);
    return false;
  }

  if((objcts_1.oflag2[prsvec_1.prsi - 1] & OPENBT) == 0) {
    rspeak_(562);
    return false;
  }

  if(prsvec_1.prso == prsvec_1.prsi) {
    rspeak_(563);
    return false;
  }

  if(objcts_1.ocan[prsvec_1.prso - 1] == prsvec_1.prsi) {
    rspsb2_(564, objcts_1.odesc2[prsvec_1.prso - 1], objcts_1.odesc2[prsvec_1.prsi - 1]);
    return true;
  }

  if(weight_(0, prsvec_1.prso, 0) + weight_(0, prsvec_1.prsi,0) + objcts_1.osize[prsvec_1.prso - 1]
        > objcts_1.ocapac[prsvec_1.prsi - 1]) {
    rspeak_(565);
    return false;
  }

  for(int j = prsvec_1.prso; j!=0; j = objcts_1.ocan[j - 1]) {
    if (qhere_(j, play_1.here)) {
      int svo = prsvec_1.prso;
      int svi = prsvec_1.prsi;
      prsvec_1.prsa = vindex_1.takew;
      prsvec_1.prsi = 0;
      if(!take_(0))
        return false;
      prsvec_1.prsa = vindex_1.putw;
      prsvec_1.prso = svo;
      prsvec_1.prsi = svi;
      if (objact_())
        return false;
      newsta_(prsvec_1.prso, 2, 0, prsvec_1.prsi, 0);
      return true;
    }
  }

  if(objcts_1.ocan[prsvec_1.prso - 1] != 0) {
    if((objcts_1.oflag2[objcts_1.ocan[prsvec_1.prso - 1] - 1] & OPENBT) == 0) {
      rspsub_(566, objcts_1.odesc2[prsvec_1.prso - 1]);
      return false;
    }
    scrupd_(objcts_1.ofval[prsvec_1.prso - 1]);
    objcts_1.ofval[prsvec_1.prso - 1] = 0;
    objcts_1.oflag2[prsvec_1.prso - 1] |= TCHBT;
    newsta_(prsvec_1.prso, 0, 0, 0, play_1.winner);
  }
  if (objact_())
    return false;
  newsta_(prsvec_1.prso, 2, 0, prsvec_1.prsi, 0);
  return true;
}

void valuac_(int v) {
  bool f = true;
  int i = 579;
  if(lit_(play_1.here)) {
    i = 677;
    int savep = prsvec_1.prso;
    int saveh = play_1.here;

    if (prsvec_1.prsa != vindex_1.takew) {
      if (prsvec_1.prsa != vindex_1.dropw) {
        if(prsvec_1.prsa == vindex_1.putw) {
          for (prsvec_1.prso = 1; prsvec_1.prso <= objcts_1.olnt; ++prsvec_1.prso) {
          	if(objcts_1.oadv[prsvec_1.prso - 1] == play_1.winner && prsvec_1.prso != prsvec_1.prsi && savep != v
                || objcts_1.otval[prsvec_1.prso - 1] > 0 && (objcts_1.oflag1[prsvec_1.prso - 1] & VISIBT) != 0) {
              f = false;
              rspsub_(580, objcts_1.odesc2[prsvec_1.prso - 1]);
              put_(1);
              if (saveh != play_1.here) {
                return;
              }
            }
          }
        }
      } else {
        for(prsvec_1.prso = 1; prsvec_1.prso <= objcts_1.olnt; ++prsvec_1.prso) {
          if(objcts_1.oadv[prsvec_1.prso - 1] == play_1.winner && savep != v || objcts_1.otval[prsvec_1.prso - 1] > 0) {
            f = false;
            rspsub_(580, objcts_1.odesc2[prsvec_1.prso - 1]);
            drop_(1);
            if (saveh != play_1.here)
              return;
          }
        }
      }
    } else {
      for (prsvec_1.prso = 1; prsvec_1.prso <= objcts_1.olnt; ++prsvec_1.prso) {
      	if(qhere_(prsvec_1.prso, play_1.here) && (objcts_1.oflag1[prsvec_1.prso - 1] & VISIBT) != 0 &&
            (objcts_1.oflag2[prsvec_1.prso - 1] & ACTRBT) == 0 && savep != v || objcts_1.otval[prsvec_1.prso - 1] > 0) {
          if((objcts_1.oflag1[prsvec_1.prso - 1] & TAKEBT) != 0 || (objcts_1.oflag2[prsvec_1.prso - 1] & TRYBT) != 0) {
            f = false;
            rspsub_(580, objcts_1.odesc2[prsvec_1.prso - 1]);
            take_(1);
            if (saveh != play_1.here)
              return;
          }
        }
      }
    }

    i = (savep == v) ? 582 : 581;
  }
  if(f)
    rspeak_(i);
}


// dverb2.c
/* SAVE- SAVE GAME STATE */

// #include <stdio.h>
// #include "funcs.h"
// #include "vars.h"

static int cxappl_(int);

void savegm_() {
    /* Local variables */
    int i;
    FILE *e;

    prsvec_1.prswon = false;
    if((e = fopen("dsave.dat", BINWRITE)) == NULL)
      rspeak_(598);

    gttime_(&i); 

#define do_uio(i, zbuf, cbytes) \
	(void) fwrite((const char *)(zbuf), (cbytes), (i), e)

    do_uio(1, &vers_1.vmaj, sizeof(integer));
    do_uio(1, &vers_1.vmin, sizeof(integer));
    do_uio(1, &vers_1.vedit, sizeof(integer));

    do_uio(1, &play_1.winner, sizeof(integer));
    do_uio(1, &play_1.here, sizeof(integer));
    do_uio(1, &hack_1.thfpos, sizeof(integer));
    do_uio(1, &play_1.telflg, sizeof(logical));
    do_uio(1, &hack_1.thfflg, sizeof(logical));
    do_uio(1, &hack_1.thfact, sizeof(logical));
    do_uio(1, &hack_1.swdact, sizeof(logical));
    do_uio(1, &hack_1.swdsta, sizeof(integer));
    do_uio(64, &puzzle_1.cpvec[0], sizeof(integer));

    do_uio(1, &i, sizeof(integer));
    do_uio(1, &state_1.moves, sizeof(integer));
    do_uio(1, &state_1.deaths, sizeof(integer));
    do_uio(1, &state_1.rwscor, sizeof(integer));
    do_uio(1, &state_1.egscor, sizeof(integer));
    do_uio(1, &state_1.mxload, sizeof(integer));
    do_uio(1, &state_1.ltshft, sizeof(integer));
    do_uio(1, &state_1.bloc, sizeof(integer));
    do_uio(1, &state_1.mungrm, sizeof(integer));
    do_uio(1, &state_1.hs, sizeof(integer));
    do_uio(1, &screen_1.fromdr, sizeof(integer));
    do_uio(1, &screen_1.scolrm, sizeof(integer));
    do_uio(1, &screen_1.scolac, sizeof(integer));

    do_uio(220, &objcts_1.odesc1[0], sizeof(integer));
    do_uio(220, &objcts_1.odesc2[0], sizeof(integer));
    do_uio(220, &objcts_1.oflag1[0], sizeof(integer));
    do_uio(220, &objcts_1.oflag2[0], sizeof(integer));
    do_uio(220, &objcts_1.ofval[0], sizeof(integer));
    do_uio(220, &objcts_1.otval[0], sizeof(integer));
    do_uio(220, &objcts_1.osize[0], sizeof(integer));
    do_uio(220, &objcts_1.ocapac[0], sizeof(integer));
    do_uio(220, &objcts_1.oroom[0], sizeof(integer));
    do_uio(220, &objcts_1.oadv[0], sizeof(integer));
    do_uio(220, &objcts_1.ocan[0], sizeof(integer));

    do_uio(200, &rooms_1.rval[0], sizeof(integer));
    do_uio(200, &rooms_1.rflag[0], sizeof(integer));

    do_uio(4, &advs_1.aroom[0], sizeof(integer));
    do_uio(4, &advs_1.ascore[0], sizeof(integer));
    do_uio(4, &advs_1.avehic[0], sizeof(integer));
    do_uio(4, &advs_1.astren[0], sizeof(integer));
    do_uio(4, &advs_1.aflag[0], sizeof(integer));

    do_uio(46, &flags[0], sizeof(logical));
    do_uio(22, &switch_[0], sizeof(integer));
    do_uio(4, &vill_1.vprob[0], sizeof(integer));
    do_uio(25, &cevent_1.cflag[0], sizeof(logical));
    do_uio(25, &cevent_1.ctick[0], sizeof(integer));

#undef do_uio

    if (fclose(e) == EOF)
      rspeak_(598);

    rspeak_(597);
    return;
}

void rstrgm_() {
  /* Local variables */
  integer i, j, k;
  FILE *e;

  prsvec_1.prswon = false;
  if ((e = fopen("dsave.dat", BINREAD)) == NULL) {
    rspeak_(598);
    return;
  }

#define do_uio(i, zbuf, cbytes) \
  (void)fread((char *)(zbuf), (cbytes), (i), e)

  do_uio(1, &i, sizeof(integer));
  do_uio(1, &j, sizeof(integer));
  do_uio(1, &k, sizeof(integer));

  if(i != vers_1.vmaj | j != vers_1.vmin) {
    rspeak_(600);
    (void)fclose(e);
    return;
  }

  do_uio(1, &play_1.winner, sizeof(integer));
  do_uio(1, &play_1.here, sizeof(integer));
  do_uio(1, &hack_1.thfpos, sizeof(integer));
  do_uio(1, &play_1.telflg, sizeof(logical));
  do_uio(1, &hack_1.thfflg, sizeof(logical));
  do_uio(1, &hack_1.thfact, sizeof(logical));
  do_uio(1, &hack_1.swdact, sizeof(logical));
  do_uio(1, &hack_1.swdsta, sizeof(integer));
  do_uio(64, &puzzle_1.cpvec[0], sizeof(integer));

  do_uio(1, &time_1.pltime, sizeof(integer));
  do_uio(1, &state_1.moves, sizeof(integer));
  do_uio(1, &state_1.deaths, sizeof(integer));
  do_uio(1, &state_1.rwscor, sizeof(integer));
  do_uio(1, &state_1.egscor, sizeof(integer));
  do_uio(1, &state_1.mxload, sizeof(integer));
  do_uio(1, &state_1.ltshft, sizeof(integer));
  do_uio(1, &state_1.bloc, sizeof(integer));
  do_uio(1, &state_1.mungrm, sizeof(integer));
  do_uio(1, &state_1.hs, sizeof(integer));
  do_uio(1, &screen_1.fromdr, sizeof(integer));
  do_uio(1, &screen_1.scolrm, sizeof(integer));
  do_uio(1, &screen_1.scolac, sizeof(integer));

  do_uio(220, &objcts_1.odesc1[0], sizeof(integer));
  do_uio(220, &objcts_1.odesc2[0], sizeof(integer));
  do_uio(220, &objcts_1.oflag1[0], sizeof(integer));
  do_uio(220, &objcts_1.oflag2[0], sizeof(integer));
  do_uio(220, &objcts_1.ofval[0], sizeof(integer));
  do_uio(220, &objcts_1.otval[0], sizeof(integer));
  do_uio(220, &objcts_1.osize[0], sizeof(integer));
  do_uio(220, &objcts_1.ocapac[0], sizeof(integer));
  do_uio(220, &objcts_1.oroom[0], sizeof(integer));
  do_uio(220, &objcts_1.oadv[0], sizeof(integer));
  do_uio(220, &objcts_1.ocan[0], sizeof(integer));

  do_uio(200, &rooms_1.rval[0], sizeof(integer));
  do_uio(200, &rooms_1.rflag[0], sizeof(integer));

  do_uio(4, &advs_1.aroom[0], sizeof(integer));
  do_uio(4, &advs_1.ascore[0], sizeof(integer));
  do_uio(4, &advs_1.avehic[0], sizeof(integer));
  do_uio(4, &advs_1.astren[0], sizeof(integer));
  do_uio(4, &advs_1.aflag[0], sizeof(integer));

  do_uio(46, &flags[0], sizeof(logical));
  do_uio(22, &switch_[0], sizeof(integer));
  do_uio(4, &vill_1.vprob[0], sizeof(integer));
  do_uio(25, &cevent_1.cflag[0], sizeof(logical));
  do_uio(25, &cevent_1.ctick[0], sizeof(integer));

  (void)fclose(e);
  rspeak_(599);
}

bool walk_() {
    if(play_1.winner != aindex_1.player || lit_(play_1.here) || prob_(25, 25)) {
      if(!findxt_(prsvec_1.prso, play_1.here)) {
        curxt_1.xstrng = 678;
        if (prsvec_1.prso == xsrch_1.xup)
          curxt_1.xstrng = 679;
        if (prsvec_1.prso == xsrch_1.xdown)
          curxt_1.xstrng = 680;
        if ((rooms_1.rflag[play_1.here - 1] & RNWALL) != 0)
          curxt_1.xstrng = 524;
        rspeak_(curxt_1.xstrng);
        prsvec_1.prscon = 1;
        return true;
      }
  
      switch (curxt_1.xtype) {
        case 3:
          if (cxappl_(curxt_1.xactio) != 0)
            break;
          if (flags[*xflag - 1])
            break;
        case 2:
          if (curxt_1.xstrng == 0) {
            curxt_1.xstrng = 678;
            if (prsvec_1.prso == xsrch_1.xup)
              curxt_1.xstrng = 679;
            if (prsvec_1.prso == xsrch_1.xdown)
              curxt_1.xstrng = 680;
            if ((rooms_1.rflag[play_1.here - 1] & RNWALL) != 0)
              curxt_1.xstrng = 524;
            rspeak_(curxt_1.xstrng);
            prsvec_1.prscon = 1;
            return true;
          }
          rspeak_(curxt_1.xstrng);
          prsvec_1.prscon = 1;
          return true;
        case 4:
          if(cxappl_(curxt_1.xactio) != 0)
            break;
          if((objcts_1.oflag2[curxt_1.xobj - 1] & OPENBT) != 0)
            break;
          if(curxt_1.xstrng == 0)
            curxt_1.xstrng = 525;
          rspsub_(curxt_1.xstrng, objcts_1.odesc2[curxt_1.xobj - 1]);
          prsvec_1.prscon = 1;
          return true;
        case 1:
          break;
        default:
          bug_(9, curxt_1.xtype);
      }
      if(moveto_(curxt_1.xroom1, play_1.winner))
        return rmdesc_(0);
      return false;
    }

    if(!findxt_(prsvec_1.prso, play_1.here)) {
      jigsup_(522);
      return true;
    }

    switch (curxt_1.xtype) {
      case 1:
        break;
      case 3:
        if (cxappl_(curxt_1.xactio) != 0)
          break;
        if (flags[*xflag - 1])
          break;
      case 2:
        jigsup_(523);
        return true;
      case 4:
        if (cxappl_(curxt_1.xactio) != 0)
          break;
        if ((objcts_1.oflag2[curxt_1.xobj - 1] & OPENBT) != 0)
          break;
        jigsup_(523);
        return true;
      default:
        bug_(9, curxt_1.xtype);
    }
    if (lit_(curxt_1.xroom1)) {
      if(moveto_(curxt_1.xroom1, play_1.winner))
        return rmdesc_(0);
      return false;
    }
    jigsup_(522);
    return true;
}

static int cxappl_(int ri) {
    if (ri == 0)
      return 0;

    switch (ri) {
      case 1:
        findex_1.egyptf = objcts_1.oadv[oindex_1.coffi - 1] != play_1.winner;
        return 0;
      case 2:
        if (findex_1.caroff)
          return 0;
        rspeak_(121);
      case 5:
        curxt_1.xroom1 = exits_1.travel[rooms_1.rexit[play_1.here - 1] + xpars_1.xelnt[xpars_1.xcond - 1] * rnd_(8) - 1]
                        & xpars_1.xrmask;
        return curxt_1.xroom1;
      case 3: {
        findex_1.litldf = false;
        int j = 0;
        for(int i = 0; i < objcts_1.olnt; ++i)
          if (objcts_1.oadv[i] == play_1.winner) j++;
        if(j > 2)
          return 0;
        curxt_1.xstrng = 446;
        if(objcts_1.oadv[oindex_1.lamp - 1] != play_1.winner)
          return 0;
        findex_1.litldf = true;
        if((objcts_1.oflag2[oindex_1.door - 1] & OPENBT) == 0)
          objcts_1.oflag2[oindex_1.door - 1] &= ~ TCHBT;
        return 0;
      }
      case 4:
        if (findex_1.caroff)
          rspeak_(121);
        findex_1.frobzf = false;
        return 0;
      case 6:
        if (findex_1.caroff)
          rspeak_(121);
        findex_1.frobzf = true;
        return 0;
      case 7:
        findex_1.frobzf = objcts_1.oroom[oindex_1.bills - 1] != 0 & objcts_1.oroom[oindex_1.portr - 1] != 0;
        return 0;
      case 8: {
        findex_1.frobzf = false;
        if (findex_1.mloc != curxt_1.xroom1)
          return curxt_1.xroom1;
        if (prsvec_1.prso == xsrch_1.xnorth || prsvec_1.prso == xsrch_1.xsouth) {
          curxt_1.xstrng = 814;
          if (findex_1.mdir % 180 == 0)
            return 0;
        } else if(findex_1.mdir % 180 == 0) {
          curxt_1.xroom1 = (curxt_1.xroom1 - rindex_1.mra << 1) + rindex_1.mrae;
          if (prsvec_1.prso > xsrch_1.xsouth)
            ++curxt_1.xroom1;
          return curxt_1.xroom1;
        }
        int ldir = findex_1.mdir;
        if (prsvec_1.prso == xsrch_1.xsouth)
          ldir = 180;
        curxt_1.xstrng = 815;
        if (ldir > 180 && ! findex_1.mr1f || ldir < 180 && ! findex_1.mr2f)
          curxt_1.xstrng = 816;
        return 0;
      }
      case 9:
        if(mrhere_(play_1.here) != 1) {
          findex_1.frobzf = false;
          curxt_1.xstrng = 817;
          return 0;
        }
        if(findex_1.mr1f)
          curxt_1.xstrng = 805;
        findex_1.frobzf = findex_1.mropnf;
        return 0;
      case 10: {
        findex_1.frobzf = false;
        int ldir = (prsvec_1.prso - xsrch_1.xnorth) / xsrch_1.xnorth * 45;
        if(!findex_1.mropnf || (findex_1.mdir + 270) % 360 != ldir && prsvec_1.prso != xsrch_1.xexit) {
          if(!findex_1.wdopnf || (findex_1.mdir + 180) % 360 != ldir && prsvec_1.prso != xsrch_1.xexit)
            return 0;
          curxt_1.xroom1 = findex_1.mloc + 1;
          if (findex_1.mdir == 0)
            curxt_1.xroom1 = findex_1.mloc - 1;
          rspeak_(818);
          findex_1.wdopnf = false;
          return curxt_1.xroom1;
        }
        curxt_1.xroom1 = (findex_1.mloc - rindex_1.mra << 1) + rindex_1.mrae + 1 - findex_1.mdir / 180;
        if(findex_1.mdir % 180 != 0) {
          curxt_1.xroom1 = findex_1.mloc + 1;
          if(findex_1.mdir > 180)
            curxt_1.xroom1 = findex_1.mloc - 1;
        }
        return curxt_1.xroom1;
      }
      case 11:
        if (findex_1.lcell != 4)
          curxt_1.xstrng = 678;
        return 0;
      case 12:
        findex_1.frobzf = true;
        findex_1.cphere = 10;
        return 0;
      case 13:
        findex_1.cphere = 52;
        return 0;
      case 14:
        findex_1.frobzf = false;
        if(prsvec_1.prso == xsrch_1.xup) {
          if (findex_1.cphere != 10)
            return 0;
          curxt_1.xstrng = 881;
          if (puzzle_1.cpvec[findex_1.cphere] != -2)
            return 0;
          rspeak_(882);
          findex_1.frobzf = true;
          return 0;
        }
        if(findex_1.cphere == 52 && prsvec_1.prso == xsrch_1.xwest && findex_1.cpoutf) {
          findex_1.frobzf = true;
          return 0;
        }
        for(int i = 0; i < 16; i += 2) {
          if (prsvec_1.prso == puzzle_1.cpdr[i]) {
            int j = puzzle_1.cpdr[i+1];
            int nxt = findex_1.cphere + j;
            int k = (j < 0) ? -8 : 8;
            if((abs(j) == 1 || abs(j) == 8 || (puzzle_1.cpvec[findex_1.cphere + k - 1] == 0 ||
                puzzle_1.cpvec[nxt - k - 1] == 0)) && puzzle_1.cpvec[nxt - 1] == 0) {
              cpgoto_(nxt);
              curxt_1.xroom1 = rindex_1.cpuzz;
              return curxt_1.xroom1;
            }
            return 0;
          }
        }
        return 0;
      default:
        bug_(5, ri);
    }

/* C14-	FROBZF (PUZZLE ROOM TRANSITIONS) */

}


// lightp.c
/* LIGHTP-	LIGHT PROCESSOR */

// #include "funcs.h"
// #include "vars.h"

bool lightp_(int obj) {
  int flobts = FLAMBT + LITEBT + ONBT;
  if (obj != oindex_1.candl) {
    if(obj != oindex_1.match)
      bug_(6, obj);
    if(prsvec_1.prsa != vindex_1.trnonw || prsvec_1.prso != oindex_1.match) {
      if (prsvec_1.prsa != vindex_1.trnofw || (objcts_1.oflag1[oindex_1.match - 1] & ONBT) == 0)
        return false;
      objcts_1.oflag1[oindex_1.match - 1] &= ~ flobts;
      cevent_1.ctick[cindex_1.cevmat - 1] = 0;
      rspeak_(185);
      return true;
    }
    if (findex_1.ormtch != 0) {
      findex_1.ormtch--;
      objcts_1.oflag1[oindex_1.match - 1] |= flobts;
      cevent_1.ctick[cindex_1.cevmat - 1] = 2;
      rspeak_(184);
      return true;
    }
    rspeak_(183);
    return true;
  }
  if(findex_1.orcand == 0) {
    findex_1.orcand = 1;
    cevent_1.ctick[cindex_1.cevcnd - 1] = 50;
  }
  if (prsvec_1.prsi == oindex_1.candl)
    return false;
  if(prsvec_1.prsa == vindex_1.trnofw) {
    cevent_1.cflag[cindex_1.cevcnd - 1] = false;
    objcts_1.oflag1[oindex_1.candl - 1] &= ~ ONBT;
    rspeak_(((objcts_1.oflag1[oindex_1.candl - 1] & ONBT) != 0) ? 514 : 513);
    return true;
  }
  if (prsvec_1.prsa != vindex_1.burnw && prsvec_1.prsa != vindex_1.trnonw)
    return false;
  if((objcts_1.oflag1[oindex_1.candl - 1] & LITEBT) == 0) {
    rspeak_(515);
    return true;
  }
  if(prsvec_1.prsi == 0) {
    rspeak_(516);
    prsvec_1.prswon = false;
    return true;
  }
  if(prsvec_1.prsi == oindex_1.match && (objcts_1.oflag1[oindex_1.match - 1] & ONBT) != 0) {
    objcts_1.oflag1[oindex_1.candl - 1] |= ONBT;
    cevent_1.cflag[cindex_1.cevcnd - 1] = true;
    rspeak_(((objcts_1.oflag1[oindex_1.candl - 1] & ONBT) != 0) ? 518 : 517);
    return true;
  }
  if(prsvec_1.prsi != oindex_1.torch || (objcts_1.oflag1[oindex_1.torch - 1] & ONBT) == 0) {
    rspeak_(519);
    return true;
  }
  if((objcts_1.oflag1[oindex_1.candl - 1] & ONBT) != 0) {
    rspeak_(520);
    return true;
  }
  newsta_(oindex_1.candl, 521, 0, 0, 0);
  return true;
}


// local.c
/* local.c -- dungeon functions which need local definition */

// #include "funcs.h"


/* This function should return true if it's OK for people to play the
 * game, false otherwise.  If you have a working <time.h> library,
 * you can define NONBUSINESS to disallow play Monday to Friday, 9-5
 * (this is only checked at the start of the game, though).  For more
 * complex control you will have to write your own version of this
 * function.
 */

#ifdef NONBUSINESS
#ifdef BSD4_2
#include <sys/timeb.h>
#else /* ! BSD4_2 */
#include <time.h>
#endif /* ! BSD4_2 */
#endif /* NONBUSINESS */

bool protected() {
  return true;
}

#ifdef ALLOW_GDT

/* This function should return true if the user is allowed to invoke the
 * game debugging tool by typing "gdt".  This isn't very useful without
 * the source code, and it's mainly for people trying to debug the game.
 * You can define WIZARDID to specify a user id on a UNIX system.  On a
 * non AMOS, non unix system this function will have to be changed if
 * you want to use gdt.
 */

#ifndef WIZARDID
#define WIZARDID (0)
#endif

bool wizard() {
#ifdef unix
  if(getuid() == 0 || getuid() == WIZARDID)
    return true;
#endif
    return true;
}

#endif


// nobjs.c
/* NOBJS-	NEW OBJECTS PROCESSOR */
/* 	OBJECTS IN THIS MODULE CANNOT CALL RMINFO, JIGSUP, */
/* 	MAJOR VERBS, OR OTHER NON-RESIDENT SUBROUTINES */

// #include "funcs.h"
// #include "vars.h"

static bool mirpan_(int, bool);

static bool func2(int target, int odi2, int odo2) {
  if(prsvec_1.prso == target) {
    if(prsvec_1.prsa == vindex_1.pushw || prsvec_1.prsa == vindex_1.movew || prsvec_1.prsa == vindex_1.takew
        || prsvec_1.prsa == vindex_1.rubw) {
      rspeak_(673);
      return true;
    }
    if(prsvec_1.prsa == vindex_1.killw || prsvec_1.prsa == vindex_1.attacw || prsvec_1.prsa == vindex_1.mungw) {
      rspsub_(674, odi2);
      return true;
    }
  }
  if(prsvec_1.prsa != vindex_1.throww || prsvec_1.prsi != target) {
    return false;
  }
  if(play_1.here != rindex_1.bkbox) {
    newsta_(prsvec_1.prso, 0, rindex_1.bkbox, 0, 0);
    rspsub_(675, odo2);
    cevent_1.ctick[cindex_1.cevscl - 1] = 0;
    screen_1.scolrm = 0;
    return true;
  }
  if(screen_1.scolrm == 0) {
    newsta_(prsvec_1.prso, 0, screen_1.scolrm, 0, 0);
    rspsub_(676, odo2);
    cevent_1.ctick[cindex_1.cevscl - 1] = 0;
    screen_1.scolrm = 0;
    return true;
  }
  rspeak_(213);
  return true;
}

bool nobjs_(int ri, int arg) {
  int odo2 = (prsvec_1.prso != 0) ? objcts_1.odesc2[prsvec_1.prso - 1] : 0;
  int odi2 = (prsvec_1.prsi != 0) ? objcts_1.odesc2[prsvec_1.prsi - 1] : 0;
  int av = advs_1.avehic[play_1.winner - 1];

  switch(ri) {
    case 32: {
      if(prsvec_1.prsa == vindex_1.eatw) {
        rspeak_(639);
        return true;
      }
      if (prsvec_1.prsa == vindex_1.burnw)
        rspeak_(640);
      return false;
    }
    case 33:
      return func2(oindex_1.scol, odi2, odo2);
    case 34: {
      if(prsvec_1.prsa == vindex_1.givew || prsvec_1.prsa == vindex_1.throww) {
        if(objcts_1.otval[prsvec_1.prso - 1] == 0) {
          newsta_(prsvec_1.prso, 641, 0, 0, 0);
          return true;
        }
        newsta_(prsvec_1.prso, 0, 0, 0, 0);
        rspsub_(642, odo2);
        newsta_(oindex_1.zgnom, 0, 0, 0, 0);
        cevent_1.ctick[cindex_1.cevzgo - 1] = 0;
        moveto_(rindex_1.bkent, play_1.winner);
        return true;
      }
      if(prsvec_1.prsa == vindex_1.attacw || prsvec_1.prsa == vindex_1.killw || prsvec_1.prsa == vindex_1.mungw) {
        newsta_(oindex_1.zgnom, 643, 0, 0, 0);
        cevent_1.ctick[cindex_1.cevzgo - 1] = 0;
        return true;
      }
      rspeak_(644);
      return true;
    }
    case 35: {
      if (prsvec_1.prsa != vindex_1.openw || prsvec_1.prso != oindex_1.egg) {
        if (prsvec_1.prsa != vindex_1.openw && prsvec_1.prsa != vindex_1.mungw) {
          if (prsvec_1.prsa != vindex_1.dropw || play_1.here != rindex_1.mtree)
            return false;
          newsta_(oindex_1.begg, 658, rindex_1.fore3, 0, 0);
          newsta_(oindex_1.egg, 0, 0, 0, 0);
          objcts_1.otval[oindex_1.begg - 1] = 2;
          if (objcts_1.ocan[oindex_1.canar - 1] != oindex_1.egg) {
            newsta_(oindex_1.bcana, 0, 0, 0, 0);
            return true;
          }
          objcts_1.otval[oindex_1.bcana - 1] = 1;
          return true;
        }
        newsta_(oindex_1.begg, 655, objcts_1.oroom[oindex_1.egg - 1], objcts_1.ocan[oindex_1.egg - 1],
                objcts_1.oadv[oindex_1.egg - 1]);
        newsta_(oindex_1.egg, 0, 0, 0, 0);
        objcts_1.otval[oindex_1.begg - 1] = 2;
        if (objcts_1.ocan[oindex_1.canar - 1] != oindex_1.egg) {
          newsta_(oindex_1.bcana, 0, 0, 0, 0);
          return true;
        }
        rspeak_(objcts_1.odesco[oindex_1.bcana - 1]);
        objcts_1.otval[oindex_1.bcana - 1] = 1;
        return true;
      }
      if((objcts_1.oflag2[oindex_1.egg - 1] & OPENBT) != 0) {
        rspeak_(649);
        return true;
      }
      if(prsvec_1.prsi == 0) {
        rspeak_(650);
        return true;
      }
      if(prsvec_1.prsi == oindex_1.hands) {
        rspeak_(651);
        return true;
      }
      if((objcts_1.oflag1[prsvec_1.prsi - 1] & TOOLBT) == 0 && (objcts_1.oflag2[prsvec_1.prsi - 1] & WEAPBT) == 0) {
        objcts_1.oflag2[prsvec_1.prso - 1] |= FITEBT;
        rspsub_(((objcts_1.oflag2[prsvec_1.prso - 1] & FITEBT) != 0) ? 654 : 653, odi2);
        return true;
      }
      newsta_(oindex_1.begg, 652, objcts_1.oroom[oindex_1.egg - 1], objcts_1.ocan[oindex_1.egg - 1],
              objcts_1.oadv[oindex_1.egg - 1]);
      newsta_(oindex_1.egg, 0, 0, 0, 0);
      objcts_1.otval[oindex_1.begg - 1] = 2;
      if (objcts_1.ocan[oindex_1.canar - 1] != oindex_1.egg) {
        newsta_(oindex_1.bcana, 0, 0, 0, 0);
        return true;
      }
      rspeak_(objcts_1.odesco[oindex_1.bcana - 1]);
      objcts_1.otval[oindex_1.bcana - 1] = 1;
      return true;
    }
    case 36: {
      if(prsvec_1.prsa != vindex_1.windw)
        return false;
      if(prsvec_1.prso != oindex_1.canar) {
        rspeak_(645);
        return true;
      }
      if(findex_1.singsf || (play_1.here != rindex_1.mtree && play_1.here < rindex_1.fore1
          || play_1.here >= rindex_1.clear)) {
        rspeak_(646);
        return true;
      }
      findex_1.singsf = true;
      newsta_(oindex_1.baubl, 647, (play_1.here == rindex_1.mtree) ? rindex_1.fore3 : play_1.here, 0, 0);
      return true;
    }
    case 37: {
      if (prsvec_1.prsa != vindex_1.clmbw && prsvec_1.prsa != vindex_1.clmbuw && prsvec_1.prsa != vindex_1.clmbdw)
        return false;
      rspeak_(648);
      return true;
    }
    case 38: {
      if(abs(play_1.here - findex_1.mloc) == 1 && mrhere_(play_1.here) == 0 && prsvec_1.prsa == vindex_1.pushw) {
        rspeak_(860);
        return true;
      }
      if ((rooms_1.rflag[play_1.here - 1] & RNWALL) == 0)
        return false;
      rspeak_(662);
      return true;
    }
    case 39: {
      if(prsvec_1.prsa == vindex_1.findw) {
        rspeak_(666);
        return true;
      }
      if (prsvec_1.prsa != vindex_1.examiw)
        return false;
      rspeak_(667);
      return true;
    }
    case 40: {
      if(play_1.here == rindex_1.cpuzz) {
        if (prsvec_1.prsa != vindex_1.pushw)
          return false;
        for(int i = 1; i <= 8; i += 2) {
          if (prsvec_1.prso == puzzle_1.cpwl[i - 1]) {
            int j = puzzle_1.cpwl[i];
            int nxt = findex_1.cphere + j;
            int wl = puzzle_1.cpvec[nxt - 1];
            switch(wl) {
              case 0:
                rspeak_(876);
                return true;
              case -3:
              case -2:
              case -1:
                if (puzzle_1.cpvec[nxt + j - 1] == 0) {
                  findex_1.cpushf = true;
                  puzzle_1.cpvec[nxt + j - 1] = wl;
                  puzzle_1.cpvec[nxt - 1] = 0;
                  cpgoto_(nxt);
                  cpinfo_(findex_1.cpushf ? 879 : 878, nxt);
                  princr_(1, play_1.here);
                  rooms_1.rflag[play_1.here - 1] |= RSEEN;
                  return true;
                }
              case 1:
                rspeak_(877);
                return true;
            }
          }
        }
        bug_(80, prsvec_1.prso);
      }
  
      if(play_1.here == screen_1.scolac)
        for(int i = 1; i <= 12; i += 3)
        	if(screen_1.scolwl[i - 1] == play_1.here)
              return func2(screen_1.scolwl[i], odi2, odo2);
      if(play_1.here != rindex_1.bkbox)
        return false;
      return func2(oindex_1.wnort, odi2, odo2);
    }
    case 41: {
      if(prsvec_1.prsa == vindex_1.raisew) {
        rspeak_((findex_1.poleuf == 2) ? 750 : 749);
        findex_1.poleuf = 2;
        return true;
      }
      if(prsvec_1.prsa != vindex_1.lowerw && prsvec_1.prsa != vindex_1.pushw)
        return false;
      if(findex_1.poleuf == 0) {
        rspeak_(751);
        return true;
      }
      if(findex_1.mdir % 180 == 0) {
        findex_1.poleuf = 0;
        rspeak_(752);
        return true;
      }
      if(findex_1.mdir == 270 && findex_1.mloc == rindex_1.mrb) {
        findex_1.poleuf = 0;
        rspeak_(753);
        return true;
      }
      rspeak_(findex_1.poleuf + 753);
      findex_1.poleuf = 1;
      return true;
    }
    case 42: {
      if(prsvec_1.prsa != vindex_1.pushw)
        return false;
      if (findex_1.mrpshf) {
        rspeak_(758);
        return true;
      }
      rspeak_(756);
      for(int i = 1; i <= objcts_1.olnt; ++i)
        if (qhere_(i, rindex_1.mreye) && i != oindex_1.rbeam) {
          cevent_1.cflag[cindex_1.cevmrs - 1] = true;
          cevent_1.ctick[cindex_1.cevmrs - 1] = 7;
          findex_1.mrpshf = true;
          findex_1.mropnf = true;
          return true;
        }
      rspeak_(757);
      return true;
    }
    case 43: {
      if(prsvec_1.prsa == vindex_1.takew && prsvec_1.prso == oindex_1.rbeam) {
        rspeak_(759);
        return true;
      }
      int i = prsvec_1.prso;
      if(prsvec_1.prsa != vindex_1.putw || prsvec_1.prsi != oindex_1.rbeam) {
        if (prsvec_1.prsa != vindex_1.mungw || prsvec_1.prso != oindex_1.rbeam || prsvec_1.prsi == 0)
          return false;
        i = prsvec_1.prsi;
      }
      if(objcts_1.oadv[i - 1] == play_1.winner) {
        newsta_(i, 0, play_1.here, 0, 0);
        rspsub_(760, objcts_1.odesc2[i - 1]);
        return true;
      }
      rspsub_(qhere_(761, play_1.here) ? 762 : 761, objcts_1.odesc2[i - 1]);
      return true;
    }
    case 44: {
      if(play_1.here == rindex_1.ncell || findex_1.lcell == 4 && (play_1.here == rindex_1.cell ||
            play_1.here == rindex_1.scorr)) {
        if(!opncls_(oindex_1.odoor, 764, 765))
          return false;
        if (play_1.here == rindex_1.ncell && (objcts_1.oflag2[oindex_1.odoor - 1] & OPENBT) != 0)
          rspeak_(766);
        return true;
      }
      rspeak_(763);
      return true;
    }
    case 45: {
      if(prsvec_1.prsa == vindex_1.openw || prsvec_1.prsa == vindex_1.closew) {
        rspeak_(767);
        return true;
      }
      if(prsvec_1.prsa != vindex_1.knockw)
        return false;
      if(findex_1.inqstf) {
        rspeak_(798);
        return true;
      }
      findex_1.inqstf = true;
      cevent_1.cflag[cindex_1.cevinq - 1] = true;
      cevent_1.ctick[cindex_1.cevinq - 1] = 2;
      findex_1.quesno = rnd_(8);
      findex_1.nqatt = 0;
      findex_1.corrct = 0;
      rspeak_(768);
      rspeak_(769);
      rspeak_(findex_1.quesno + 770);
      return true;
    }
    case 46: {
      if (prsvec_1.prsa != vindex_1.openw)
        return false;
      rspeak_(778);
      return true;
    }
    case 47:
      return opncls_(oindex_1.cdoor, 779, 780);
    case 48: {
      if (prsvec_1.prsa != vindex_1.pushw)
        return false;
      rspeak_(809);
      if((objcts_1.oflag2[oindex_1.cdoor - 1] & OPENBT) != 0)
        rspeak_(810);
  
      for(int i = 0; i < objcts_1.olnt; i++) {
        if(objcts_1.oroom[i] == rindex_1.cell && (objcts_1.oflag1[i] & DOORBT) == 0)
          newsta_(i+1, 0, findex_1.lcell * hyper_1.hfactr, 0, 0);
        if(objcts_1.oroom[i] == findex_1.pnumb * hyper_1.hfactr)
          newsta_(i+1, 0, rindex_1.cell, 0, 0);
      }
  
      objcts_1.oflag2[oindex_1.odoor - 1] &= ~ OPENBT;
      objcts_1.oflag2[oindex_1.cdoor - 1] &= ~ OPENBT;
      objcts_1.oflag1[oindex_1.odoor - 1] &= ~ VISIBT;
      if (findex_1.pnumb == 4)
        objcts_1.oflag1[oindex_1.odoor - 1] |= VISIBT;
  
      if(advs_1.aroom[aindex_1.player - 1] == rindex_1.cell) {
        if(findex_1.lcell == 4) {
          objcts_1.oflag1[oindex_1.odoor - 1] |= VISIBT;
          moveto_(rindex_1.ncell, aindex_1.player);
        } else
          moveto_(rindex_1.pcell, aindex_1.player);
      }
      findex_1.lcell = findex_1.pnumb;
      return true;
    }
    case 49: {
      if(prsvec_1.prsa == vindex_1.spinw) {
        findex_1.pnumb = rnd_(8) + 1;
        rspsub_(797, findex_1.pnumb + 712);
        return true;
      }
      if(prsvec_1.prsa != vindex_1.movew && prsvec_1.prsa != vindex_1.putw && prsvec_1.prsa != vindex_1.trntow)
        return false;
      if(prsvec_1.prsi == 0) {
        rspeak_(806);
        return true;
      }
      if(prsvec_1.prsi < oindex_1.num1 || prsvec_1.prsi > oindex_1.num8) {
        rspeak_(807);
        return true;
      }
      findex_1.pnumb = prsvec_1.prsi - oindex_1.num1 + 1;
      rspsub_(808, findex_1.pnumb + 712);
      return true;
    }
    case 50:
      return mirpan_(832, 0);
    case 51: {
      if(play_1.here == rindex_1.fdoor) {
        if (prsvec_1.prsa != vindex_1.openw && prsvec_1.prsa != vindex_1.closew)
          return false;
        rspeak_(843);
        return true;
      }
      return mirpan_(838, 1);
    }
    case 52: {
      if(prsvec_1.prsa != vindex_1.putw || prsvec_1.prsi != oindex_1.cslit)
        return false;
      if(prsvec_1.prso == oindex_1.gcard) {
        newsta_(prsvec_1.prso, 863, 0, 0, 0);
        findex_1.cpoutf = true;
        objcts_1.oflag1[oindex_1.stldr - 1] &= ~ VISIBT;
        return true;
      }
      if((objcts_1.oflag1[prsvec_1.prso - 1] & VICTBT) == 0 && (objcts_1.oflag2[prsvec_1.prso - 1] & VILLBT) == 0) {
        newsta_(prsvec_1.prso, 0, 0, 0, 0);
        rspsub_(864, odo2);
        return true;
      }
      rspeak_(rnd_(5) + 552);
      return true;
    }
    default:
      bug_(6, ri);
  }
}

static bool mirpan_(int st, bool pnf) {
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    integer num;
    integer mrbf;

    ret_val = true;
    num = mrhere_(play_1.here);
    if(num == 0) {
      rspeak_(st);
      return ret_val;
    }
    mrbf = (num == 1 && ! findex_1.mr1f || num == 2 && ! findex_1.mr2f) ? 1 : 0;
    if(prsvec_1.prsa == vindex_1.movew || prsvec_1.prsa == vindex_1.openw) {
      rspeak_(st + 1);
      return ret_val;
    }
    if(!pnf && prsvec_1.prsa == vindex_1.lookiw || prsvec_1.prsa == vindex_1.examiw || prsvec_1.prsa == vindex_1.lookw) {
      rspeak_(mrbf + 844);
      return ret_val;
    }
    if(prsvec_1.prsa == vindex_1.mungw) {
      rspeak_(st + 2 + mrbf);
      if(num == 1 && !pnf)
        findex_1.mr1f = false;
      if(num == 2 && !pnf)
        findex_1.mr2f = false;
      return ret_val;
    }
    if(pnf && mrbf != 0) {
      rspeak_(846);
      return ret_val;
    }
    if (prsvec_1.prsa != vindex_1.pushw) {
	goto L600;
    }
/* 						!PUSH? */
    rspeak_(st + 3 + num);
    return ret_val;

L600:
    ret_val = false;
/* 						!CANT HANDLE IT. */
    return ret_val;

} /* mirpan_ */


// nrooms.c
/* RAPPL2- SPECIAL PURPOSE ROOM ROUTINES, PART 2 */

// #include "funcs.h"
// #include "vars.h"

static void ewtell_(int, int);
static void lookto_(int, int, int, int, int);

bool rappl2_(int ri) {
    const int newrms = 38;

    switch (ri - newrms + 1) {
    	case 1:
        if (prsvec_1.prsa == vindex_1.lookw)
    	    lookto_(rindex_1.fdoor, rindex_1.mrg, 0, 682, 681);
        break;
    	case 2:
        if (prsvec_1.prsa == vindex_1.walkiw)
        	jigsup_(685);
        break;
    	case 3:
        if (prsvec_1.prsa == vindex_1.lookw)
        	lookto_(rindex_1.mrg, rindex_1.mrb, 683, 0, 681);
        break;
    	case 4:
        if (prsvec_1.prsa == vindex_1.lookw)
        	lookto_(rindex_1.mrc, rindex_1.mra, 0, 0, 681);
        break;
    	case 5:
        if (prsvec_1.prsa == vindex_1.lookw)
    	    lookto_(rindex_1.mrb, 0, 0, 684, 681);
        break;
    	case 6:
        if (prsvec_1.prsa == vindex_1.lookw)
    	    ewtell_(play_1.here, 683);
        break;
    	case 7:
        if (prsvec_1.prsa == vindex_1.lookw)
        	ewtell_(play_1.here, 686);
        break;
    	case 8:
        if (prsvec_1.prsa == vindex_1.lookw)
        	ewtell_(play_1.here, 687);
        break;
    	case 9:
        if (prsvec_1.prsa == vindex_1.lookw) {
          rspeak_(688);
          int i = 689;
          if (findex_1.mdir == 270 && findex_1.mloc == rindex_1.mrb)
      	    i = min(findex_1.poleuf,1) + 690;
          if (findex_1.mdir % 180 == 0)
      	    i = min(findex_1.poleuf,1) + 692;
          rspeak_(i);
          rspsub_(694, findex_1.mdir / 45 + 695);
        }
        break;
    	case 10:
        if (prsvec_1.prsa == vindex_1.lookw) {
          int j;
          int i = 703;
          for(j = 0; j < objcts_1.olnt; j++) {
          	if(qhere_(j+1, play_1.here) && j+1 != oindex_1.rbeam) {
          	  i = 704;
          	  break;
          	}
          }
          rspsub_(i, objcts_1.odesc2[j]);
          lookto_(rindex_1.mra, 0, 0, 0, 0);
        }
        break;
    	case 11:
        if (prsvec_1.prsa == vindex_1.lookw) {
          if ((objcts_1.oflag2[oindex_1.tomb - 1] & OPENBT) != 0)
      	    rspsub_(705, 12);
          else
            rspsub_(705, 46);
        }
        break;
    	case 12:
        if (prsvec_1.prsa != vindex_1.lookw)
    	    return true;
        rspeak_(706);
        if (findex_1.lcell == 4) {
          if ((objcts_1.oflag2[oindex_1.odoor - 1] & OPENBT) != 0)
      	    rspsub_(707, 12);
      	  else
      	    rspsub_(707, 46);
        }
        break;
    	case 13:
        if (prsvec_1.prsa == vindex_1.walkiw) {
          cevent_1.cflag[cindex_1.cevfol - 1] = true;
          cevent_1.ctick[cindex_1.cevfol - 1] = -1;
        } else if (prsvec_1.prsa == vindex_1.lookw) {
          if ((objcts_1.oflag2[oindex_1.qdoor - 1] & OPENBT) != 0) {
      	    rspsub_(708, 12);
          } else
            rspsub_(708, 46);
        }
        break;
    	case 14:
        if (prsvec_1.prsa == vindex_1.walkiw)
    	    cevent_1.ctick[cindex_1.cevfol - 1] = 0;
        if (prsvec_1.prsa == vindex_1.lookw) {
          lookto_(0, rindex_1.mrd, 709, 0, 0);
          int i = findex_1.inqstf ? : 46;
          int j = (objcts_1.oflag2[oindex_1.qdoor - 1] & OPENBT) ? 12 : 46;
          rspsb2_(710, i, j);
        }
        break;
    	case 15:
        if (prsvec_1.prsa == vindex_1.lookw) {
          if ((objcts_1.oflag2[oindex_1.cdoor - 1] & OPENBT) != 0)
      	    rspsub_(711, 12);
          else
            rspsub_(711, 46);
        }
        break;
    	case 16:
        if (prsvec_1.prsa == vindex_1.lookw)
        	rspsub_(712, findex_1.pnumb + 712);
        break;
    	case 17:
        if (prsvec_1.prsa == vindex_1.lookw) {
          if ((objcts_1.oflag2[oindex_1.cdoor - 1] & OPENBT) != 0)
      	    rspeak_(722);
          else
            rspeak_(721);
          if (findex_1.lcell == 4) {
            if ((objcts_1.oflag2[oindex_1.odoor - 1] & OPENBT) != 0)
        	    rspsub_(723, 12);
            else
              rspsub_(723, 46);
          }
        }
        break;
    	case 18:
        if (prsvec_1.prsa == vindex_1.lookw)
    	    rspeak_(724);
        break;
    	case 19:
        if (prsvec_1.prsa == vindex_1.lookw) {
          if ((objcts_1.oflag2[oindex_1.odoor - 1] & OPENBT) != 0) {
      	    rspsub_(725, 12);
          } else
            rspsub_(725, 46);
        }
        break;
    	case 20:
        if (prsvec_1.prsa == vindex_1.walkiw) {
          rspeak_(726);
          score_(0);
          exit_();
        }
        break;
    	case 21:
        if (prsvec_1.prsa == vindex_1.lookw) {
          if ((objcts_1.oflag2[oindex_1.tomb - 1] & OPENBT) != 0) {
      	    rspsub_(792, 12);
          } else
            rspsub_(792, 46);
        }
        break;
    	case 22:
        if (prsvec_1.prsa == vindex_1.lookw) {
          if (findex_1.cpoutf)
      	    rspeak_(862);
          else
            rspeak_(861);
        }
        break;
    	case 23:
        if (prsvec_1.prsa == vindex_1.lookw) {
          if (findex_1.cpushf) {
            cpinfo_(880, findex_1.cphere);
          } else {
            rspeak_(868);
            if ((objcts_1.oflag2[oindex_1.warni - 1] & TCHBT) != 0)
      	      rspeak_(869);
          }
        }
        break;
    	default:
        bug_(70, ri);
    }
    return true;
}

static void lookto_(int nrm, int srm, int nt, int st, int ht) {
    rspeak_(ht);
    rspeak_(nt);
    rspeak_(st);
    int dir = 0;
    if (abs(findex_1.mloc - play_1.here) == 1) {
      if (findex_1.mloc == nrm)
  	    dir = 695;
      if (findex_1.mloc == srm)
  	    dir = 699;
      if (findex_1.mdir % 180 != 0) {
        int m1 = mrhere_(play_1.here);
        int mrbf = (m1 == 1 && ! findex_1.mr1f || m1 == 2 && ! findex_1.mr2f) ? 1 : 0;
        rspsub_(mrbf + 849, dir);
        if (m1 == 1 && findex_1.mropnf)
        	rspeak_(mrbf + 823);
        if (mrbf != 0)
    	    rspeak_(851);
      }
      rspsub_(847, dir);
      rspsb2_(848, dir, dir);
    }
    if (ht != 0) {
      int i = 0;
      if (nt == 0 && (dir == 0 || dir == 699))
  	    i = 852;
      if (st == 0 && (dir == 0 || dir == 695))
  	    i = 853;
      if (nt + st + dir == 0)
  	    i = 854;
	    rspeak_(i);
    }
}

static void ewtell_(int rm, int st) {
    int i;
    bool m1;

    m1 = findex_1.mdir + (rm - rindex_1.mrae) % 2 * 180 == 180;
    i = (rm - rindex_1.mrae) % 2 + 819;
    if (m1 && ! findex_1.mr1f || ! m1 && ! findex_1.mr2f)
	    i += 2;
    rspeak_(i);
    if (m1 && findex_1.mropnf)
    	rspeak_((i - 819) / 2 + 823);
    rspeak_(825);
    rspeak_(st);
}


// supp.c
/* supp.c -- support routines for dungeon */

// #include <stdio.h>
// #include <stdlib.h>

#ifdef unix
#include <sys/types.h>
#endif

#ifdef BSD4_2
#include <sys/time.h>
#else /* ! BSD4_2 */
#include <time.h>
#endif /* ! BSD4_2 */

// #include "funcs.h"


void exit_() {
  fprintf(stderr, "The game is over.\n");
  exit(0);
}

void itime_(int *hrptr, int *minptr, int *secptr) {
	time_t timebuf;
	struct tm *tmptr;

	time(&timebuf);
	tmptr = localtime(&timebuf);
	
	*hrptr  = tmptr->tm_hour;
	*minptr = tmptr->tm_min;
	*secptr = tmptr->tm_sec;
}

int rnd_(int maxval) {
	return rand() % maxval;
}

/* Terminal support routines for dungeon */
/* By Ian Lance Taylor ian@airs.com or uunet!airs!ian */

/* The dungeon game can often output long strings, more than enough
 * to overwhelm a typical 24 row terminal (I assume that back when
 * dungeon was written people generally used paper terminals (I know
 * I did) so this was not a problem).  The functions in this file
 * provide a very simplistic ``more'' facility.  They are necessarily
 * somewhat operating system dependent, although I have tried to
 * minimize it as much as I could.
 */

/* The following macro definitions may be used to control how these
 * functions work:
 *
 *	MORE_NONE	Don't use the more facility at all
 *	MORE_24		Always assume a 24 row terminal
 *	MORE_TERMCAP	Use termcap routines to get rows of terminal
 *	MORE_TERMINFO	Use terminfo routines to get rows of terminal
 *	MORE_AMOS	Use AMOS monitor calls to get rows of terminal
 *
 * If none of these are defined then this will use termcap routines on
 * unix and AMOS routines on AMOS.
 */

#ifndef MORE_NONE
#ifndef MORE_24
#ifndef MORE_TERMCAP
#ifndef MORE_TERMINFO
#ifndef MORE_AMOS
#ifdef __AMOS__
#define MORE_AMOS
#else /* ! __AMOS__ */
#ifdef unix
#define MORE_TERMCAP
#else /* ! unix */
#define MORE_NONE
#endif /* ! unix */
#endif /* ! __AMOS__ */
#endif /* ! MORE_AMOS */
#endif /* ! MORE_TERMINFO */
#endif /* ! MORE_TERMCAP */
#endif /* ! MORE_24 */
#endif /* ! MORE_NONE */

#ifdef MORE_TERMCAP

extern char *getenv P((const char *));
extern void tgetent P((char *, const char *));
extern int tgetnum P((const char *));

#else /* ! MORE_TERMCAP */

#ifdef MORE_TERMINFO

#include <cursesX.h>
#include <term.h>
extern void setupterm P((const char *, int, int));

#else /* ! MORE_TERMINFO */

#ifdef MORE_AMOS

#include <moncal.h>
#include <unistd.h>

#endif /* MORE_AMOS */
#endif /* ! MORE_TERMINFO */
#endif /* ! MORE_TERMCAP */

static integer crows;
static integer coutput;

void more_init() {
#ifdef MORE_NONE
  crows = 0;
#else /* ! MORE_NONE */
#ifdef MORE_24
  crows = 24;
#else /* ! MORE_24 */
#ifdef MORE_TERMCAP
  char buf[2048];
  char *term;
  term = getenv("TERM");
  if (term == NULL)
    crows = 0;
  else {
    tgetent(buf, term);
    crows = tgetnum("li");
  }
#else /* ! MORE_TERMCAP */
#ifdef MORE_TERMINFO
  int i;
  setupterm(NULL, 1, &i);
  if (i != 1)
      crows = 0;
  else
    crows = lines;
#else /* ! MORE_TERMINFO */
#ifdef MORE_AMOS
  trm_char st;
  if (isatty(fileno(stdin)) == 0)
    crows = 0;
  else {
    trmchr(&st, 0);
    crows = st.row;
  }
#else /* ! MORE_AMOS */
  This should be impossible
#endif /* ! MORE_AMOS */
#endif /* ! MORE_TERMINFO */
#endif /* ! MORE_TERMCAP */
#endif /* ! MORE_24 */
#endif /* ! MORE_NONE */
}

void more_output(const char *z) {
  if (z != NULL)
    printf("%s\n", z);
  coutput++;
}

void more_input() {
  coutput = 0;
}


// dmain.c
/* DUNGEON-- MAIN PROGRAM */

#define EXTERN
#define INIT

// #include "funcs.h"
// #include "vars.h"

void main(int argc, char **argv) {
    if (init_()) {
	    game_();
    }
    exit_();
}













