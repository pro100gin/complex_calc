#include "../include/main.h"

char** file_filter(int *file_count){
    int len;
    struct dirent **entry;
    char **names;
    int i = 0;
    int k = 0;
    (*file_count)=0;
    (*file_count) = scandir("lib", &entry, 0, alphasort);
    if(*file_count<0){
       perror("scandir error");
       exit(-1);
    }
    if((names = malloc((*file_count -2)*sizeof(char*))) == NULL){
        perror("malloc error");
        exit(-1);
    }
    names[0] = malloc(255);
    for(i = 2; i <(*file_count); ++i){
	len = strlen(entry[i]->d_name);
	if(entry[i]->d_name[0]=='l' && entry[i]->d_name[1]=='i' &&
	entry[i]->d_name[2]=='b' && entry[i]->d_name[len-3]=='.' &&
	entry[i]->d_name[len-2]=='s' && entry[i]->d_name[len-1]=='o'){
            if((names[k] = malloc(255)) == NULL){
	        perror("malloc error");
	        exit(-1);
	    }
            strcpy(names[k], entry[i]->d_name);
            k++;
	}
    }
    (*file_count) = k;
    return names;
}


int main(){
	int count;
	int i;
	char **plugins  = file_filter(&count);

	m_complex *first = malloc(sizeof(m_complex));
	m_complex *second = malloc(sizeof(m_complex));
	m_complex *ans = malloc(sizeof(m_complex));

	char ch, dir[80];

	m_complex* (**func) (m_complex*, m_complex*);
	//chdir("..");
	chdir("lib");
	getcwd(dir, 255);
	void* bd;
	char **name;

	name = malloc(count*sizeof(char*));
	func = malloc(count * 8 /*sizeof(m_complex (*) (m_complex*, m_complex*))*/);
	getchar();
	for(i = 0; i< count; ++i){
		char path[80];
		sprintf(path, "%s/%s",dir, plugins[i]);
		printf("%s\n", path);
		if(!(bd = dlopen(path, RTLD_NOW))){
			perror("dlopen error");
			//exit(-1);
		}
		name[i] = dlsym(bd, "plugin_name");
		printf("%s\n", name[i]);
		func[i] = dlsym(bd, name[i]);
		getchar();
	}

	printf("\033[2J");
	printf("\033[0;0f");
	while(1){
		for(i = 0; i< count; ++i){
			printf("%d. %s\n", i+1, name[i]);
		}
		printf("%d. exit\n", count + 1);
		ch = getchar();
		printf("\033[2J");
		printf("\033[0;0f");
		if(ch>='0'&&ch<='3'){
			printf("Input re of 1st number:\n");
			scanf("%lf", &first->re);
			printf("\nInput im of 1st number:\n");
			scanf("%lf", &first->im);
			printf("\nInput re of 2nd number:\n");
			scanf("%lf", &second->re);
			printf("\nInput im of 2nd number:\n");
			scanf("%lf", &second->im);
			ans = func[ch-49] (first, second);
			printf("\nans: %.3lf %.3lfi\n", ans->re, ans->im);
			ch = getchar();
			ch = getchar();
		}
		else if(ch - 49 == count){
			break;
		}
		printf("\033[2J");
		printf("\033[0;0f");
	}
	dlclose(bd);
	return 0;
}
