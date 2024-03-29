#ifndef _NISPROG_H
#define _NISPROG_H

#include <stdint.h>

#include "libcli.h"

/* state of connection to ECU */
enum npstate_t {
	NP_DISC,	/** disconnected */
	NP_NORMALCONN, /** normal connection to stock firmware */
	NP_NPKCONN /** kernel connection to npkern */
};

extern enum npstate_t npstate;

enum ecutype_t {
	NISECU_UNK,
	NISECU_7055_35,	/** old 350nm part */
	NISECU_7055_18,	/** 180nm */
	NISECU_7058
	};

struct nisecu_t {
	//enum ecutype_t ecutype;	/** decides which flashblock descriptor to use etc */
	uint8_t ecuid[6];		/** ASCIIz */

	const void *keyset;	/** keyset to use */
	const void *flashdev;	/** device descriptor */

};

extern struct nisecu_t nisecu;


/* public funcs */
void nisecu_cleardata(struct nisecu_t *pne);


/***** CLI command handlers */
enum cli_retval cmd_npconn(int argc, char **argv);
enum cli_retval cmd_npdisc(int argc, char **argv);
enum cli_retval cmd_npconf(int argc, char **argv);
enum cli_retval cmd_setdev(int argc, char **argv);
enum cli_retval cmd_guesskey(int argc, char **argv);
enum cli_retval cmd_setkeys(int argc, char **argv);
enum cli_retval cmd_kspeed(int argc, char **argv);
enum cli_retval cmd_runkernel(int argc, char **argv);
enum cli_retval cmd_stopkernel(int argc, char **argv);
enum cli_retval cmd_writevin(int argc, char** argv);
enum cli_retval cmd_initk(int argc, char **argv);
enum cli_retval cmd_dumpmem(int argc, char **argv);
enum cli_retval cmd_watch(int argc, char **argv);
enum cli_retval cmd_flverif(int argc, char **argv);
enum cli_retval cmd_flblock(int argc, char **argv);
enum cli_retval cmd_flrom(int argc, char **argv);
enum cli_retval cmd_npt(int argc, char **argv);

// Subaru specific commands
enum cli_retval cmd_spconn(int argc, char **argv);
enum cli_retval cmd_sprunkernel(int argc, char **argv);

#endif
