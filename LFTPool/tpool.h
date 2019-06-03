#ifndef __TPOOL_H__
#define __TPOOL_H__

enum schedule_type {
    ROUND_ROBIN,
    LEAST_LOAD
};

//初始化线程池
void *tpool_init(int num_worker_threads);

//增加工作化线程
int tpool_inc_threads(void *pool, int num_inc);

//减少工作线程
void tpool_dec_threads(void *pool, int num_dec);

//添加任务 routine：任务函数指针
int tpool_add_work(void *pool, void(*routine)(void *), void *arg);
/*
@finish:  1, complete remaining works before return
        0, drop remaining works and return directly
*/
void tpool_destroy(void *pool, int finish);

/* set thread schedule algorithm, default is round-robin */
//修改线程池的任务分配方式
void set_thread_schedule_algorithm(void *pool, enum schedule_type type);

#endif
