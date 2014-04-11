#include "a.h"
#include "b.h"
#include "d.h"
#include "e.h"
#include "f.h"
#include "g.h"
#include "h.h"
#include "i.h"
#include "j.h"
#include "l.h"
#include "m.h"
#include "n.h"
#include "ng.h"
#include "o.h"
#include "oo.h"
#include "p.h"
#include "r.h"
#include "s.h"
#include "t.h"
#include "th.h"
#include "tlh.h"
#include "u.h"
#include "v.h"
#include "w.h"
#include "x.h"
#include "y.h"
#include "z.h"

typedef	struct tlng_letter	tlng_letter;
struct tlng_letter {
	char *ltr;
	char *bfr;
} tlng_letters[] = {
	{ "tlh", tlng_tlh_data },
	{ "ng", tlng_ng_data },
	{ "th", tlng_th_data },
	{ "oo", tlng_oo_data },
	{ "ee", tlng_i_data },
	{ "l", tlng_l_data },
	{ "i", tlng_i_data },
	{ "o", tlng_o_data },
	{ "n", tlng_n_data },
	{ "f", tlng_f_data },
	{ "b", tlng_b_data },
	{ "d", tlng_d_data },
	{ "g", tlng_g_data },
	{ "a", tlng_a_data },
	{ "m", tlng_m_data },
	{ "x", tlng_x_data },
	{ "h", tlng_h_data },
	{ "v", tlng_v_data },
	{ "j", tlng_j_data },
	{ "e", tlng_e_data },
	{ "s", tlng_s_data },
	{ "y", tlng_y_data },
	{ "w", tlng_w_data },
	{ "p", tlng_p_data },
	{ "t", tlng_t_data },
	{ "r", tlng_r_data },
	{ "u", tlng_u_data },
	{ "z", tlng_z_data },
	{ NULL, NULL },
}

