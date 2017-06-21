#include "../include/operations.h"

char *plugin_name = "add";

m_complex* add(m_complex *first, m_complex *second){
	m_complex *ans = malloc(sizeof(m_complex));
	ans->re = first->re + second->re;
	ans->im = first->im + second->im;
	;
	return ans;
}
