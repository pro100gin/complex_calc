#include "../include/operations.h"

char plugin_name[80] = "divi";

m_complex* divi(m_complex *first, m_complex *second){
	m_complex *ans = malloc(sizeof(m_complex));
	m_complex *temp = malloc(sizeof(m_complex));

	temp->re = second->re;
	temp->im = -second->im;

	first = mult(first, temp);
	second = mult(second, temp);

	if(second->re){
		ans->re += first->re/second->re;
		ans->im += first->im/second->re;
	}
	if(second->im){
		ans->re += first->im/second->re;
		ans->im += first->re/second->im;
	}
	return ans;
}
