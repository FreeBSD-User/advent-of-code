#include <err.h>
#include <stdlib.h>
#include <malloc_np.h>

static inline void *
s_malloc(size_t s)
{
	void *ptr = malloc(s);
	if (ptr == nullptr)
		err(1, "malloc(%lu)", s);
	return (ptr);
}

static inline void *
s_mallocx(size_t s)
{
	void *ptr = mallocx(s, 0);
	if (ptr == nullptr)
		err(1, "mallocx(%lu)", s);
	return (ptr);
}

static inline void *
s_rallocx(void *ptr, size_t s)
{
	if (ptr == nullptr)
		ptr = s_mallocx(s);
	else
		ptr = rallocx(ptr, s, 0);
	if (ptr == nullptr)
		err(1, "rallocx(%lu)", s);
	return (ptr);
}
