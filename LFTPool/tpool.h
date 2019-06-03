#ifndef __TPOOL_H__
#define __TPOOL_H__

enum schedule_type {
    ROUND_ROBIN,
    LEAST_LOAD
};

//��ʼ���̳߳�
void *tpool_init(int num_worker_threads);

//���ӹ������߳�
int tpool_inc_threads(void *pool, int num_inc);

//���ٹ����߳�
void tpool_dec_threads(void *pool, int num_dec);

//������� routine��������ָ��
int tpool_add_work(void *pool, void(*routine)(void *), void *arg);
/*
@finish:  1, complete remaining works before return
        0, drop remaining works and return directly
*/
void tpool_destroy(void *pool, int finish);

/* set thread schedule algorithm, default is round-robin */
//�޸��̳߳ص�������䷽ʽ
void set_thread_schedule_algorithm(void *pool, enum schedule_type type);

#endif
