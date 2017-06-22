#include "../include/operations.h"

char plugin_name[80] = "mult";

m_complex* mult(m_complex *first, m_complex *second){
	m_complex *ans = malloc(sizeof(m_complex));
	ans->re = first->re*second->re - first->im*second->im;
	ans->im = first->im*second->re + first->re*second->im;
	return ans;

}
