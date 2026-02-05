#include <err.h>
#include <stdlib.h>
#include <malloc_np.h>

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
	ptr = rallocx(ptr, s, 0);
	if (ptr == nullptr)
		err(1, "mallocx(%lu)", s);
	return (ptr);
}
