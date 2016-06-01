





typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;







typedef long int __quad_t;
typedef unsigned long int __u_quad_t;


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;



typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;
typedef __pid_t pid_t;





typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;


typedef __clock_t clock_t;





typedef __time_t time_t;



typedef __clockid_t clockid_t;
typedef __timer_t timer_t;
typedef long unsigned int size_t;



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));


typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

typedef int register_t __attribute__ ((__mode__ (__word__)));






static __inline unsigned int
__bswap_32 (unsigned int __bsx)
{
  return __builtin_bswap32 (__bsx);
}
static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{
  return __builtin_bswap64 (__bsx);
}




typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;



typedef __sigset_t sigset_t;





struct timespec
  {
    __time_t tv_sec;
    __syscall_slong_t tv_nsec;
  };

struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };


typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;

extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);





__extension__
extern unsigned int gnu_dev_major (unsigned long long int __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__
extern unsigned int gnu_dev_minor (unsigned long long int __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__
extern unsigned long long int gnu_dev_makedev (unsigned int __major,
            unsigned int __minor)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));






typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
typedef unsigned long int pthread_t;


union pthread_attr_t
{
  char __size[56];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;





typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;

    unsigned int __nusers;



    int __kind;

    short __spins;
    short __elision;
    __pthread_list_t __list;
  } __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;




typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;





typedef union
{

  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
    int __writer;
    int __shared;
    signed char __rwelision;




    unsigned char __pad1[7];


    unsigned long int __pad2;


    unsigned int __flags;

  } __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;







typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef unsigned int uint32_t;



typedef unsigned long int uint64_t;
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;

typedef long int int_least64_t;






typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;

typedef unsigned long int uint_least64_t;
typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;


typedef unsigned long int uintptr_t;
typedef long int intmax_t;
typedef unsigned long int uintmax_t;






struct iovec
  {
    void *iov_base;
    size_t iov_len;
  };
extern ssize_t readv (int __fd, const struct iovec *__iovec, int __count)
  ;
extern ssize_t writev (int __fd, const struct iovec *__iovec, int __count)
  ;
extern ssize_t preadv (int __fd, const struct iovec *__iovec, int __count,
         __off_t __offset) ;
extern ssize_t pwritev (int __fd, const struct iovec *__iovec, int __count,
   __off_t __offset) ;









struct sched_param
  {
    int __sched_priority;
  };










struct __sched_param
  {
    int __sched_priority;
  };
typedef unsigned long int __cpu_mask;






typedef struct
{
  __cpu_mask __bits[1024 / (8 * sizeof (__cpu_mask))];
} cpu_set_t;


extern int __sched_cpucount (size_t __setsize, const cpu_set_t *__setp)
  __attribute__ ((__nothrow__ , __leaf__));
extern cpu_set_t *__sched_cpualloc (size_t __count) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void __sched_cpufree (cpu_set_t *__set) __attribute__ ((__nothrow__ , __leaf__));









extern int sched_setparam (__pid_t __pid, const struct sched_param *__param)
     __attribute__ ((__nothrow__ , __leaf__));


extern int sched_getparam (__pid_t __pid, struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__));


extern int sched_setscheduler (__pid_t __pid, int __policy,
          const struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__));


extern int sched_getscheduler (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));


extern int sched_yield (void) __attribute__ ((__nothrow__ , __leaf__));


extern int sched_get_priority_max (int __algorithm) __attribute__ ((__nothrow__ , __leaf__));


extern int sched_get_priority_min (int __algorithm) __attribute__ ((__nothrow__ , __leaf__));


extern int sched_rr_get_interval (__pid_t __pid, struct timespec *__t) __attribute__ ((__nothrow__ , __leaf__));














struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;


  long int tm_gmtoff;
  const char *tm_zone;




};








struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };


struct sigevent;



extern clock_t clock (void) __attribute__ ((__nothrow__ , __leaf__));


extern time_t time (time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));


extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));





extern size_t strftime (char *__restrict __s, size_t __maxsize,
   const char *__restrict __format,
   const struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));

typedef struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
} *__locale_t;


typedef __locale_t locale_t;

extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     const char *__restrict __format,
     const struct tm *__restrict __tp,
     __locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));



extern struct tm *gmtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));



extern struct tm *localtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));





extern struct tm *gmtime_r (const time_t *__restrict __timer,
       struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));



extern struct tm *localtime_r (const time_t *__restrict __timer,
          struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));





extern char *asctime (const struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));


extern char *ctime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));







extern char *asctime_r (const struct tm *__restrict __tp,
   char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));


extern char *ctime_r (const time_t *__restrict __timer,
        char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));




extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;




extern char *tzname[2];



extern void tzset (void) __attribute__ ((__nothrow__ , __leaf__));



extern int daylight;
extern long int timezone;





extern int stime (const time_t *__when) __attribute__ ((__nothrow__ , __leaf__));
extern time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));


extern time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));


extern int dysize (int __year) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int nanosleep (const struct timespec *__requested_time,
        struct timespec *__remaining);



extern int clock_getres (clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__ , __leaf__));


extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __attribute__ ((__nothrow__ , __leaf__));


extern int clock_settime (clockid_t __clock_id, const struct timespec *__tp)
     __attribute__ ((__nothrow__ , __leaf__));






extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       const struct timespec *__req,
       struct timespec *__rem);


extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__ , __leaf__));




extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) __attribute__ ((__nothrow__ , __leaf__));


extern int timer_delete (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));


extern int timer_settime (timer_t __timerid, int __flags,
     const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) __attribute__ ((__nothrow__ , __leaf__));


extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     __attribute__ ((__nothrow__ , __leaf__));


extern int timer_getoverrun (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));





extern int timespec_get (struct timespec *__ts, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







typedef long int __jmp_buf[8];



enum
{
  PTHREAD_CREATE_JOINABLE,

  PTHREAD_CREATE_DETACHED

};



enum
{
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP

  ,
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL





};




enum
{
  PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_ROBUST,
  PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST
};





enum
{
  PTHREAD_PRIO_NONE,
  PTHREAD_PRIO_INHERIT,
  PTHREAD_PRIO_PROTECT
};
enum
{
  PTHREAD_RWLOCK_PREFER_READER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
  PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP
};
enum
{
  PTHREAD_INHERIT_SCHED,

  PTHREAD_EXPLICIT_SCHED

};



enum
{
  PTHREAD_SCOPE_SYSTEM,

  PTHREAD_SCOPE_PROCESS

};



enum
{
  PTHREAD_PROCESS_PRIVATE,

  PTHREAD_PROCESS_SHARED

};
struct _pthread_cleanup_buffer
{
  void (*__routine) (void *);
  void *__arg;
  int __canceltype;
  struct _pthread_cleanup_buffer *__prev;
};


enum
{
  PTHREAD_CANCEL_ENABLE,

  PTHREAD_CANCEL_DISABLE

};
enum
{
  PTHREAD_CANCEL_DEFERRED,

  PTHREAD_CANCEL_ASYNCHRONOUS

};





extern int pthread_create (pthread_t *__restrict __newthread,
      const pthread_attr_t *__restrict __attr,
      void *(*__start_routine) (void *),
      void *__restrict __arg) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3)));





extern void pthread_exit (void *__retval) __attribute__ ((__noreturn__));







extern int pthread_join (pthread_t __th, void **__thread_return);
extern int pthread_detach (pthread_t __th) __attribute__ ((__nothrow__ , __leaf__));



extern pthread_t pthread_self (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern int pthread_equal (pthread_t __thread1, pthread_t __thread2)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));







extern int pthread_attr_init (pthread_attr_t *__attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_attr_destroy (pthread_attr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_attr_getdetachstate (const pthread_attr_t *__attr,
     int *__detachstate)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setdetachstate (pthread_attr_t *__attr,
     int __detachstate)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_attr_getguardsize (const pthread_attr_t *__attr,
          size_t *__guardsize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setguardsize (pthread_attr_t *__attr,
          size_t __guardsize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_attr_getschedparam (const pthread_attr_t *__restrict __attr,
           struct sched_param *__restrict __param)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setschedparam (pthread_attr_t *__restrict __attr,
           const struct sched_param *__restrict
           __param) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_getschedpolicy (const pthread_attr_t *__restrict
     __attr, int *__restrict __policy)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setschedpolicy (pthread_attr_t *__attr, int __policy)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_attr_getinheritsched (const pthread_attr_t *__restrict
      __attr, int *__restrict __inherit)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setinheritsched (pthread_attr_t *__attr,
      int __inherit)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_attr_getscope (const pthread_attr_t *__restrict __attr,
      int *__restrict __scope)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setscope (pthread_attr_t *__attr, int __scope)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_attr_getstackaddr (const pthread_attr_t *__restrict
          __attr, void **__restrict __stackaddr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__deprecated__));





extern int pthread_attr_setstackaddr (pthread_attr_t *__attr,
          void *__stackaddr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__));


extern int pthread_attr_getstacksize (const pthread_attr_t *__restrict
          __attr, size_t *__restrict __stacksize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern int pthread_attr_setstacksize (pthread_attr_t *__attr,
          size_t __stacksize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_attr_getstack (const pthread_attr_t *__restrict __attr,
      void **__restrict __stackaddr,
      size_t *__restrict __stacksize)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3)));




extern int pthread_attr_setstack (pthread_attr_t *__attr, void *__stackaddr,
      size_t __stacksize) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_setschedparam (pthread_t __target_thread, int __policy,
      const struct sched_param *__param)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));


extern int pthread_getschedparam (pthread_t __target_thread,
      int *__restrict __policy,
      struct sched_param *__restrict __param)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));


extern int pthread_setschedprio (pthread_t __target_thread, int __prio)
     __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_once (pthread_once_t *__once_control,
    void (*__init_routine) (void)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_setcancelstate (int __state, int *__oldstate);



extern int pthread_setcanceltype (int __type, int *__oldtype);


extern int pthread_cancel (pthread_t __th);




extern void pthread_testcancel (void);




typedef struct
{
  struct
  {
    __jmp_buf __cancel_jmp_buf;
    int __mask_was_saved;
  } __cancel_jmp_buf[1];
  void *__pad[4];
} __pthread_unwind_buf_t __attribute__ ((__aligned__));
struct __pthread_cleanup_frame
{
  void (*__cancel_routine) (void *);
  void *__cancel_arg;
  int __do_it;
  int __cancel_type;
};
extern void __pthread_register_cancel (__pthread_unwind_buf_t *__buf)
     ;
extern void __pthread_unregister_cancel (__pthread_unwind_buf_t *__buf)
  ;
extern void __pthread_unwind_next (__pthread_unwind_buf_t *__buf)
     __attribute__ ((__noreturn__))

     __attribute__ ((__weak__))

     ;



struct __jmp_buf_tag;
extern int __sigsetjmp (struct __jmp_buf_tag *__env, int __savemask) __attribute__ ((__nothrow__));





extern int pthread_mutex_init (pthread_mutex_t *__mutex,
          const pthread_mutexattr_t *__mutexattr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_mutex_destroy (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_mutex_trylock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_mutex_lock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_mutex_timedlock (pthread_mutex_t *__restrict __mutex,
        const struct timespec *__restrict
        __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));



extern int pthread_mutex_unlock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_mutex_getprioceiling (const pthread_mutex_t *
      __restrict __mutex,
      int *__restrict __prioceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern int pthread_mutex_setprioceiling (pthread_mutex_t *__restrict __mutex,
      int __prioceiling,
      int *__restrict __old_ceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));




extern int pthread_mutex_consistent (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_init (pthread_mutexattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_mutexattr_destroy (pthread_mutexattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_mutexattr_getpshared (const pthread_mutexattr_t *
      __restrict __attr,
      int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_mutexattr_setpshared (pthread_mutexattr_t *__attr,
      int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_mutexattr_gettype (const pthread_mutexattr_t *__restrict
          __attr, int *__restrict __kind)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern int pthread_mutexattr_settype (pthread_mutexattr_t *__attr, int __kind)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_mutexattr_getprotocol (const pthread_mutexattr_t *
       __restrict __attr,
       int *__restrict __protocol)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern int pthread_mutexattr_setprotocol (pthread_mutexattr_t *__attr,
       int __protocol)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_mutexattr_getprioceiling (const pthread_mutexattr_t *
          __restrict __attr,
          int *__restrict __prioceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_mutexattr_setprioceiling (pthread_mutexattr_t *__attr,
          int __prioceiling)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_mutexattr_getrobust (const pthread_mutexattr_t *__attr,
     int *__robustness)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));







extern int pthread_mutexattr_setrobust (pthread_mutexattr_t *__attr,
     int __robustness)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_init (pthread_rwlock_t *__restrict __rwlock,
    const pthread_rwlockattr_t *__restrict
    __attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlock_destroy (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlock_rdlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlock_tryrdlock (pthread_rwlock_t *__rwlock)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_rwlock_timedrdlock (pthread_rwlock_t *__restrict __rwlock,
           const struct timespec *__restrict
           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));



extern int pthread_rwlock_wrlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlock_trywrlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_rwlock_timedwrlock (pthread_rwlock_t *__restrict __rwlock,
           const struct timespec *__restrict
           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));



extern int pthread_rwlock_unlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





extern int pthread_rwlockattr_init (pthread_rwlockattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlockattr_destroy (pthread_rwlockattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlockattr_getpshared (const pthread_rwlockattr_t *
       __restrict __attr,
       int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_rwlockattr_setpshared (pthread_rwlockattr_t *__attr,
       int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlockattr_getkind_np (const pthread_rwlockattr_t *
       __restrict __attr,
       int *__restrict __pref)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_rwlockattr_setkind_np (pthread_rwlockattr_t *__attr,
       int __pref) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int pthread_cond_init (pthread_cond_t *__restrict __cond,
         const pthread_condattr_t *__restrict __cond_attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_cond_destroy (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_cond_signal (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_cond_broadcast (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));






extern int pthread_cond_wait (pthread_cond_t *__restrict __cond,
         pthread_mutex_t *__restrict __mutex)
     __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_cond_timedwait (pthread_cond_t *__restrict __cond,
       pthread_mutex_t *__restrict __mutex,
       const struct timespec *__restrict __abstime)
     __attribute__ ((__nonnull__ (1, 2, 3)));




extern int pthread_condattr_init (pthread_condattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_condattr_destroy (pthread_condattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_condattr_getpshared (const pthread_condattr_t *
     __restrict __attr,
     int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_condattr_setpshared (pthread_condattr_t *__attr,
     int __pshared) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_condattr_getclock (const pthread_condattr_t *
          __restrict __attr,
          __clockid_t *__restrict __clock_id)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_condattr_setclock (pthread_condattr_t *__attr,
          __clockid_t __clock_id)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_init (pthread_spinlock_t *__lock, int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_spin_destroy (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_spin_lock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_spin_trylock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_spin_unlock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));






extern int pthread_barrier_init (pthread_barrier_t *__restrict __barrier,
     const pthread_barrierattr_t *__restrict
     __attr, unsigned int __count)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_barrier_destroy (pthread_barrier_t *__barrier)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_barrier_wait (pthread_barrier_t *__barrier)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_barrierattr_init (pthread_barrierattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_barrierattr_destroy (pthread_barrierattr_t *__attr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_barrierattr_getpshared (const pthread_barrierattr_t *
        __restrict __attr,
        int *__restrict __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_barrierattr_setpshared (pthread_barrierattr_t *__attr,
        int __pshared)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_key_create (pthread_key_t *__key,
          void (*__destr_function) (void *))
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_key_delete (pthread_key_t __key) __attribute__ ((__nothrow__ , __leaf__));


extern void *pthread_getspecific (pthread_key_t __key) __attribute__ ((__nothrow__ , __leaf__));


extern int pthread_setspecific (pthread_key_t __key,
    const void *__pointer) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int pthread_getcpuclockid (pthread_t __thread_id,
      __clockid_t *__clock_id)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int pthread_atfork (void (*__prepare) (void),
      void (*__parent) (void),
      void (*__child) (void)) __attribute__ ((__nothrow__ , __leaf__));

typedef struct xcb_connection_t xcb_connection_t;
typedef struct {
    void *data;
    int rem;
    int index;
} xcb_generic_iterator_t;






typedef struct {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
} xcb_generic_reply_t;






typedef struct {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t pad[7];
    uint32_t full_sequence;
} xcb_generic_event_t;
typedef struct {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t event_type;
    uint16_t pad1;
    uint32_t pad[5];
    uint32_t full_sequence;
} xcb_ge_event_t;






typedef struct {
    uint8_t response_type;
    uint8_t error_code;
    uint16_t sequence;
    uint32_t resource_id;
    uint16_t minor_code;
    uint8_t major_code;
    uint8_t pad0;
    uint32_t pad[5];
    uint32_t full_sequence;
} xcb_generic_error_t;






typedef struct {
    unsigned int sequence;
} xcb_void_cookie_t;



typedef struct xcb_char2b_t {
    uint8_t byte1;
    uint8_t byte2;
} xcb_char2b_t;




typedef struct xcb_char2b_iterator_t {
    xcb_char2b_t *data;
    int rem;
    int index;
} xcb_char2b_iterator_t;

typedef uint32_t xcb_window_t;




typedef struct xcb_window_iterator_t {
    xcb_window_t *data;
    int rem;
    int index;
} xcb_window_iterator_t;

typedef uint32_t xcb_pixmap_t;




typedef struct xcb_pixmap_iterator_t {
    xcb_pixmap_t *data;
    int rem;
    int index;
} xcb_pixmap_iterator_t;

typedef uint32_t xcb_cursor_t;




typedef struct xcb_cursor_iterator_t {
    xcb_cursor_t *data;
    int rem;
    int index;
} xcb_cursor_iterator_t;

typedef uint32_t xcb_font_t;




typedef struct xcb_font_iterator_t {
    xcb_font_t *data;
    int rem;
    int index;
} xcb_font_iterator_t;

typedef uint32_t xcb_gcontext_t;




typedef struct xcb_gcontext_iterator_t {
    xcb_gcontext_t *data;
    int rem;
    int index;
} xcb_gcontext_iterator_t;

typedef uint32_t xcb_colormap_t;




typedef struct xcb_colormap_iterator_t {
    xcb_colormap_t *data;
    int rem;
    int index;
} xcb_colormap_iterator_t;

typedef uint32_t xcb_atom_t;




typedef struct xcb_atom_iterator_t {
    xcb_atom_t *data;
    int rem;
    int index;
} xcb_atom_iterator_t;

typedef uint32_t xcb_drawable_t;




typedef struct xcb_drawable_iterator_t {
    xcb_drawable_t *data;
    int rem;
    int index;
} xcb_drawable_iterator_t;

typedef uint32_t xcb_fontable_t;




typedef struct xcb_fontable_iterator_t {
    xcb_fontable_t *data;
    int rem;
    int index;
} xcb_fontable_iterator_t;

typedef uint32_t xcb_visualid_t;




typedef struct xcb_visualid_iterator_t {
    xcb_visualid_t *data;
    int rem;
    int index;
} xcb_visualid_iterator_t;

typedef uint32_t xcb_timestamp_t;




typedef struct xcb_timestamp_iterator_t {
    xcb_timestamp_t *data;
    int rem;
    int index;
} xcb_timestamp_iterator_t;

typedef uint32_t xcb_keysym_t;




typedef struct xcb_keysym_iterator_t {
    xcb_keysym_t *data;
    int rem;
    int index;
} xcb_keysym_iterator_t;

typedef uint8_t xcb_keycode_t;




typedef struct xcb_keycode_iterator_t {
    xcb_keycode_t *data;
    int rem;
    int index;
} xcb_keycode_iterator_t;

typedef uint8_t xcb_button_t;




typedef struct xcb_button_iterator_t {
    xcb_button_t *data;
    int rem;
    int index;
} xcb_button_iterator_t;




typedef struct xcb_point_t {
    int16_t x;
    int16_t y;
} xcb_point_t;




typedef struct xcb_point_iterator_t {
    xcb_point_t *data;
    int rem;
    int index;
} xcb_point_iterator_t;




typedef struct xcb_rectangle_t {
    int16_t x;
    int16_t y;
    uint16_t width;
    uint16_t height;
} xcb_rectangle_t;




typedef struct xcb_rectangle_iterator_t {
    xcb_rectangle_t *data;
    int rem;
    int index;
} xcb_rectangle_iterator_t;




typedef struct xcb_arc_t {
    int16_t x;
    int16_t y;
    uint16_t width;
    uint16_t height;
    int16_t angle1;
    int16_t angle2;
} xcb_arc_t;




typedef struct xcb_arc_iterator_t {
    xcb_arc_t *data;
    int rem;
    int index;
} xcb_arc_iterator_t;




typedef struct xcb_format_t {
    uint8_t depth;
    uint8_t bits_per_pixel;
    uint8_t scanline_pad;
    uint8_t pad0[5];
} xcb_format_t;




typedef struct xcb_format_iterator_t {
    xcb_format_t *data;
    int rem;
    int index;
} xcb_format_iterator_t;

typedef enum xcb_visual_class_t {
    XCB_VISUAL_CLASS_STATIC_GRAY = 0,
    XCB_VISUAL_CLASS_GRAY_SCALE = 1,
    XCB_VISUAL_CLASS_STATIC_COLOR = 2,
    XCB_VISUAL_CLASS_PSEUDO_COLOR = 3,
    XCB_VISUAL_CLASS_TRUE_COLOR = 4,
    XCB_VISUAL_CLASS_DIRECT_COLOR = 5
} xcb_visual_class_t;




typedef struct xcb_visualtype_t {
    xcb_visualid_t visual_id;
    uint8_t _class;
    uint8_t bits_per_rgb_value;
    uint16_t colormap_entries;
    uint32_t red_mask;
    uint32_t green_mask;
    uint32_t blue_mask;
    uint8_t pad0[4];
} xcb_visualtype_t;




typedef struct xcb_visualtype_iterator_t {
    xcb_visualtype_t *data;
    int rem;
    int index;
} xcb_visualtype_iterator_t;




typedef struct xcb_depth_t {
    uint8_t depth;
    uint8_t pad0;
    uint16_t visuals_len;
    uint8_t pad1[4];
} xcb_depth_t;




typedef struct xcb_depth_iterator_t {
    xcb_depth_t *data;
    int rem;
    int index;
} xcb_depth_iterator_t;

typedef enum xcb_event_mask_t {
    XCB_EVENT_MASK_NO_EVENT = 0,
    XCB_EVENT_MASK_KEY_PRESS = 1,
    XCB_EVENT_MASK_KEY_RELEASE = 2,
    XCB_EVENT_MASK_BUTTON_PRESS = 4,
    XCB_EVENT_MASK_BUTTON_RELEASE = 8,
    XCB_EVENT_MASK_ENTER_WINDOW = 16,
    XCB_EVENT_MASK_LEAVE_WINDOW = 32,
    XCB_EVENT_MASK_POINTER_MOTION = 64,
    XCB_EVENT_MASK_POINTER_MOTION_HINT = 128,
    XCB_EVENT_MASK_BUTTON_1_MOTION = 256,
    XCB_EVENT_MASK_BUTTON_2_MOTION = 512,
    XCB_EVENT_MASK_BUTTON_3_MOTION = 1024,
    XCB_EVENT_MASK_BUTTON_4_MOTION = 2048,
    XCB_EVENT_MASK_BUTTON_5_MOTION = 4096,
    XCB_EVENT_MASK_BUTTON_MOTION = 8192,
    XCB_EVENT_MASK_KEYMAP_STATE = 16384,
    XCB_EVENT_MASK_EXPOSURE = 32768,
    XCB_EVENT_MASK_VISIBILITY_CHANGE = 65536,
    XCB_EVENT_MASK_STRUCTURE_NOTIFY = 131072,
    XCB_EVENT_MASK_RESIZE_REDIRECT = 262144,
    XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY = 524288,
    XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT = 1048576,
    XCB_EVENT_MASK_FOCUS_CHANGE = 2097152,
    XCB_EVENT_MASK_PROPERTY_CHANGE = 4194304,
    XCB_EVENT_MASK_COLOR_MAP_CHANGE = 8388608,
    XCB_EVENT_MASK_OWNER_GRAB_BUTTON = 16777216
} xcb_event_mask_t;

typedef enum xcb_backing_store_t {
    XCB_BACKING_STORE_NOT_USEFUL = 0,
    XCB_BACKING_STORE_WHEN_MAPPED = 1,
    XCB_BACKING_STORE_ALWAYS = 2
} xcb_backing_store_t;




typedef struct xcb_screen_t {
    xcb_window_t root;
    xcb_colormap_t default_colormap;
    uint32_t white_pixel;
    uint32_t black_pixel;
    uint32_t current_input_masks;
    uint16_t width_in_pixels;
    uint16_t height_in_pixels;
    uint16_t width_in_millimeters;
    uint16_t height_in_millimeters;
    uint16_t min_installed_maps;
    uint16_t max_installed_maps;
    xcb_visualid_t root_visual;
    uint8_t backing_stores;
    uint8_t save_unders;
    uint8_t root_depth;
    uint8_t allowed_depths_len;
} xcb_screen_t;




typedef struct xcb_screen_iterator_t {
    xcb_screen_t *data;
    int rem;
    int index;
} xcb_screen_iterator_t;




typedef struct xcb_setup_request_t {
    uint8_t byte_order;
    uint8_t pad0;
    uint16_t protocol_major_version;
    uint16_t protocol_minor_version;
    uint16_t authorization_protocol_name_len;
    uint16_t authorization_protocol_data_len;
    uint8_t pad1[2];
} xcb_setup_request_t;




typedef struct xcb_setup_request_iterator_t {
    xcb_setup_request_t *data;
    int rem;
    int index;
} xcb_setup_request_iterator_t;




typedef struct xcb_setup_failed_t {
    uint8_t status;
    uint8_t reason_len;
    uint16_t protocol_major_version;
    uint16_t protocol_minor_version;
    uint16_t length;
} xcb_setup_failed_t;




typedef struct xcb_setup_failed_iterator_t {
    xcb_setup_failed_t *data;
    int rem;
    int index;
} xcb_setup_failed_iterator_t;




typedef struct xcb_setup_authenticate_t {
    uint8_t status;
    uint8_t pad0[5];
    uint16_t length;
} xcb_setup_authenticate_t;




typedef struct xcb_setup_authenticate_iterator_t {
    xcb_setup_authenticate_t *data;
    int rem;
    int index;
} xcb_setup_authenticate_iterator_t;

typedef enum xcb_image_order_t {
    XCB_IMAGE_ORDER_LSB_FIRST = 0,
    XCB_IMAGE_ORDER_MSB_FIRST = 1
} xcb_image_order_t;




typedef struct xcb_setup_t {
    uint8_t status;
    uint8_t pad0;
    uint16_t protocol_major_version;
    uint16_t protocol_minor_version;
    uint16_t length;
    uint32_t release_number;
    uint32_t resource_id_base;
    uint32_t resource_id_mask;
    uint32_t motion_buffer_size;
    uint16_t vendor_len;
    uint16_t maximum_request_length;
    uint8_t roots_len;
    uint8_t pixmap_formats_len;
    uint8_t image_byte_order;
    uint8_t bitmap_format_bit_order;
    uint8_t bitmap_format_scanline_unit;
    uint8_t bitmap_format_scanline_pad;
    xcb_keycode_t min_keycode;
    xcb_keycode_t max_keycode;
    uint8_t pad1[4];
} xcb_setup_t;




typedef struct xcb_setup_iterator_t {
    xcb_setup_t *data;
    int rem;
    int index;
} xcb_setup_iterator_t;

typedef enum xcb_mod_mask_t {
    XCB_MOD_MASK_SHIFT = 1,
    XCB_MOD_MASK_LOCK = 2,
    XCB_MOD_MASK_CONTROL = 4,
    XCB_MOD_MASK_1 = 8,
    XCB_MOD_MASK_2 = 16,
    XCB_MOD_MASK_3 = 32,
    XCB_MOD_MASK_4 = 64,
    XCB_MOD_MASK_5 = 128,
    XCB_MOD_MASK_ANY = 32768
} xcb_mod_mask_t;

typedef enum xcb_key_but_mask_t {
    XCB_KEY_BUT_MASK_SHIFT = 1,
    XCB_KEY_BUT_MASK_LOCK = 2,
    XCB_KEY_BUT_MASK_CONTROL = 4,
    XCB_KEY_BUT_MASK_MOD_1 = 8,
    XCB_KEY_BUT_MASK_MOD_2 = 16,
    XCB_KEY_BUT_MASK_MOD_3 = 32,
    XCB_KEY_BUT_MASK_MOD_4 = 64,
    XCB_KEY_BUT_MASK_MOD_5 = 128,
    XCB_KEY_BUT_MASK_BUTTON_1 = 256,
    XCB_KEY_BUT_MASK_BUTTON_2 = 512,
    XCB_KEY_BUT_MASK_BUTTON_3 = 1024,
    XCB_KEY_BUT_MASK_BUTTON_4 = 2048,
    XCB_KEY_BUT_MASK_BUTTON_5 = 4096
} xcb_key_but_mask_t;

typedef enum xcb_window_enum_t {
    XCB_WINDOW_NONE = 0
} xcb_window_enum_t;







typedef struct xcb_key_press_event_t {
    uint8_t response_type;
    xcb_keycode_t detail;
    uint16_t sequence;
    xcb_timestamp_t time;
    xcb_window_t root;
    xcb_window_t event;
    xcb_window_t child;
    int16_t root_x;
    int16_t root_y;
    int16_t event_x;
    int16_t event_y;
    uint16_t state;
    uint8_t same_screen;
    uint8_t pad0;
} xcb_key_press_event_t;




typedef xcb_key_press_event_t xcb_key_release_event_t;

typedef enum xcb_button_mask_t {
    XCB_BUTTON_MASK_1 = 256,
    XCB_BUTTON_MASK_2 = 512,
    XCB_BUTTON_MASK_3 = 1024,
    XCB_BUTTON_MASK_4 = 2048,
    XCB_BUTTON_MASK_5 = 4096,
    XCB_BUTTON_MASK_ANY = 32768
} xcb_button_mask_t;







typedef struct xcb_button_press_event_t {
    uint8_t response_type;
    xcb_button_t detail;
    uint16_t sequence;
    xcb_timestamp_t time;
    xcb_window_t root;
    xcb_window_t event;
    xcb_window_t child;
    int16_t root_x;
    int16_t root_y;
    int16_t event_x;
    int16_t event_y;
    uint16_t state;
    uint8_t same_screen;
    uint8_t pad0;
} xcb_button_press_event_t;




typedef xcb_button_press_event_t xcb_button_release_event_t;

typedef enum xcb_motion_t {
    XCB_MOTION_NORMAL = 0,
    XCB_MOTION_HINT = 1
} xcb_motion_t;







typedef struct xcb_motion_notify_event_t {
    uint8_t response_type;
    uint8_t detail;
    uint16_t sequence;
    xcb_timestamp_t time;
    xcb_window_t root;
    xcb_window_t event;
    xcb_window_t child;
    int16_t root_x;
    int16_t root_y;
    int16_t event_x;
    int16_t event_y;
    uint16_t state;
    uint8_t same_screen;
    uint8_t pad0;
} xcb_motion_notify_event_t;

typedef enum xcb_notify_detail_t {
    XCB_NOTIFY_DETAIL_ANCESTOR = 0,
    XCB_NOTIFY_DETAIL_VIRTUAL = 1,
    XCB_NOTIFY_DETAIL_INFERIOR = 2,
    XCB_NOTIFY_DETAIL_NONLINEAR = 3,
    XCB_NOTIFY_DETAIL_NONLINEAR_VIRTUAL = 4,
    XCB_NOTIFY_DETAIL_POINTER = 5,
    XCB_NOTIFY_DETAIL_POINTER_ROOT = 6,
    XCB_NOTIFY_DETAIL_NONE = 7
} xcb_notify_detail_t;

typedef enum xcb_notify_mode_t {
    XCB_NOTIFY_MODE_NORMAL = 0,
    XCB_NOTIFY_MODE_GRAB = 1,
    XCB_NOTIFY_MODE_UNGRAB = 2,
    XCB_NOTIFY_MODE_WHILE_GRABBED = 3
} xcb_notify_mode_t;







typedef struct xcb_enter_notify_event_t {
    uint8_t response_type;
    uint8_t detail;
    uint16_t sequence;
    xcb_timestamp_t time;
    xcb_window_t root;
    xcb_window_t event;
    xcb_window_t child;
    int16_t root_x;
    int16_t root_y;
    int16_t event_x;
    int16_t event_y;
    uint16_t state;
    uint8_t mode;
    uint8_t same_screen_focus;
} xcb_enter_notify_event_t;




typedef xcb_enter_notify_event_t xcb_leave_notify_event_t;







typedef struct xcb_focus_in_event_t {
    uint8_t response_type;
    uint8_t detail;
    uint16_t sequence;
    xcb_window_t event;
    uint8_t mode;
    uint8_t pad0[3];
} xcb_focus_in_event_t;




typedef xcb_focus_in_event_t xcb_focus_out_event_t;







typedef struct xcb_keymap_notify_event_t {
    uint8_t response_type;
    uint8_t keys[31];
} xcb_keymap_notify_event_t;







typedef struct xcb_expose_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_window_t window;
    uint16_t x;
    uint16_t y;
    uint16_t width;
    uint16_t height;
    uint16_t count;
    uint8_t pad1[2];
} xcb_expose_event_t;







typedef struct xcb_graphics_exposure_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_drawable_t drawable;
    uint16_t x;
    uint16_t y;
    uint16_t width;
    uint16_t height;
    uint16_t minor_opcode;
    uint16_t count;
    uint8_t major_opcode;
    uint8_t pad1[3];
} xcb_graphics_exposure_event_t;







typedef struct xcb_no_exposure_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_drawable_t drawable;
    uint16_t minor_opcode;
    uint8_t major_opcode;
    uint8_t pad1;
} xcb_no_exposure_event_t;

typedef enum xcb_visibility_t {
    XCB_VISIBILITY_UNOBSCURED = 0,
    XCB_VISIBILITY_PARTIALLY_OBSCURED = 1,
    XCB_VISIBILITY_FULLY_OBSCURED = 2
} xcb_visibility_t;







typedef struct xcb_visibility_notify_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_window_t window;
    uint8_t state;
    uint8_t pad1[3];
} xcb_visibility_notify_event_t;







typedef struct xcb_create_notify_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_window_t parent;
    xcb_window_t window;
    int16_t x;
    int16_t y;
    uint16_t width;
    uint16_t height;
    uint16_t border_width;
    uint8_t override_redirect;
    uint8_t pad1;
} xcb_create_notify_event_t;







typedef struct xcb_destroy_notify_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_window_t event;
    xcb_window_t window;
} xcb_destroy_notify_event_t;







typedef struct xcb_unmap_notify_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_window_t event;
    xcb_window_t window;
    uint8_t from_configure;
    uint8_t pad1[3];
} xcb_unmap_notify_event_t;







typedef struct xcb_map_notify_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_window_t event;
    xcb_window_t window;
    uint8_t override_redirect;
    uint8_t pad1[3];
} xcb_map_notify_event_t;







typedef struct xcb_map_request_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_window_t parent;
    xcb_window_t window;
} xcb_map_request_event_t;







typedef struct xcb_reparent_notify_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_window_t event;
    xcb_window_t window;
    xcb_window_t parent;
    int16_t x;
    int16_t y;
    uint8_t override_redirect;
    uint8_t pad1[3];
} xcb_reparent_notify_event_t;







typedef struct xcb_configure_notify_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_window_t event;
    xcb_window_t window;
    xcb_window_t above_sibling;
    int16_t x;
    int16_t y;
    uint16_t width;
    uint16_t height;
    uint16_t border_width;
    uint8_t override_redirect;
    uint8_t pad1;
} xcb_configure_notify_event_t;







typedef struct xcb_configure_request_event_t {
    uint8_t response_type;
    uint8_t stack_mode;
    uint16_t sequence;
    xcb_window_t parent;
    xcb_window_t window;
    xcb_window_t sibling;
    int16_t x;
    int16_t y;
    uint16_t width;
    uint16_t height;
    uint16_t border_width;
    uint16_t value_mask;
} xcb_configure_request_event_t;







typedef struct xcb_gravity_notify_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_window_t event;
    xcb_window_t window;
    int16_t x;
    int16_t y;
} xcb_gravity_notify_event_t;







typedef struct xcb_resize_request_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_window_t window;
    uint16_t width;
    uint16_t height;
} xcb_resize_request_event_t;

typedef enum xcb_place_t {
    XCB_PLACE_ON_TOP = 0,


    XCB_PLACE_ON_BOTTOM = 1


} xcb_place_t;







typedef struct xcb_circulate_notify_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_window_t event;
    xcb_window_t window;
    uint8_t pad1[4];
    uint8_t place;
    uint8_t pad2[3];
} xcb_circulate_notify_event_t;




typedef xcb_circulate_notify_event_t xcb_circulate_request_event_t;

typedef enum xcb_property_t {
    XCB_PROPERTY_NEW_VALUE = 0,
    XCB_PROPERTY_DELETE = 1
} xcb_property_t;







typedef struct xcb_property_notify_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_window_t window;
    xcb_atom_t atom;
    xcb_timestamp_t time;
    uint8_t state;
    uint8_t pad1[3];
} xcb_property_notify_event_t;







typedef struct xcb_selection_clear_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_timestamp_t time;
    xcb_window_t owner;
    xcb_atom_t selection;
} xcb_selection_clear_event_t;

typedef enum xcb_time_t {
    XCB_TIME_CURRENT_TIME = 0
} xcb_time_t;

typedef enum xcb_atom_enum_t {
    XCB_ATOM_NONE = 0,
    XCB_ATOM_ANY = 0,
    XCB_ATOM_PRIMARY = 1,
    XCB_ATOM_SECONDARY = 2,
    XCB_ATOM_ARC = 3,
    XCB_ATOM_ATOM = 4,
    XCB_ATOM_BITMAP = 5,
    XCB_ATOM_CARDINAL = 6,
    XCB_ATOM_COLORMAP = 7,
    XCB_ATOM_CURSOR = 8,
    XCB_ATOM_CUT_BUFFER0 = 9,
    XCB_ATOM_CUT_BUFFER1 = 10,
    XCB_ATOM_CUT_BUFFER2 = 11,
    XCB_ATOM_CUT_BUFFER3 = 12,
    XCB_ATOM_CUT_BUFFER4 = 13,
    XCB_ATOM_CUT_BUFFER5 = 14,
    XCB_ATOM_CUT_BUFFER6 = 15,
    XCB_ATOM_CUT_BUFFER7 = 16,
    XCB_ATOM_DRAWABLE = 17,
    XCB_ATOM_FONT = 18,
    XCB_ATOM_INTEGER = 19,
    XCB_ATOM_PIXMAP = 20,
    XCB_ATOM_POINT = 21,
    XCB_ATOM_RECTANGLE = 22,
    XCB_ATOM_RESOURCE_MANAGER = 23,
    XCB_ATOM_RGB_COLOR_MAP = 24,
    XCB_ATOM_RGB_BEST_MAP = 25,
    XCB_ATOM_RGB_BLUE_MAP = 26,
    XCB_ATOM_RGB_DEFAULT_MAP = 27,
    XCB_ATOM_RGB_GRAY_MAP = 28,
    XCB_ATOM_RGB_GREEN_MAP = 29,
    XCB_ATOM_RGB_RED_MAP = 30,
    XCB_ATOM_STRING = 31,
    XCB_ATOM_VISUALID = 32,
    XCB_ATOM_WINDOW = 33,
    XCB_ATOM_WM_COMMAND = 34,
    XCB_ATOM_WM_HINTS = 35,
    XCB_ATOM_WM_CLIENT_MACHINE = 36,
    XCB_ATOM_WM_ICON_NAME = 37,
    XCB_ATOM_WM_ICON_SIZE = 38,
    XCB_ATOM_WM_NAME = 39,
    XCB_ATOM_WM_NORMAL_HINTS = 40,
    XCB_ATOM_WM_SIZE_HINTS = 41,
    XCB_ATOM_WM_ZOOM_HINTS = 42,
    XCB_ATOM_MIN_SPACE = 43,
    XCB_ATOM_NORM_SPACE = 44,
    XCB_ATOM_MAX_SPACE = 45,
    XCB_ATOM_END_SPACE = 46,
    XCB_ATOM_SUPERSCRIPT_X = 47,
    XCB_ATOM_SUPERSCRIPT_Y = 48,
    XCB_ATOM_SUBSCRIPT_X = 49,
    XCB_ATOM_SUBSCRIPT_Y = 50,
    XCB_ATOM_UNDERLINE_POSITION = 51,
    XCB_ATOM_UNDERLINE_THICKNESS = 52,
    XCB_ATOM_STRIKEOUT_ASCENT = 53,
    XCB_ATOM_STRIKEOUT_DESCENT = 54,
    XCB_ATOM_ITALIC_ANGLE = 55,
    XCB_ATOM_X_HEIGHT = 56,
    XCB_ATOM_QUAD_WIDTH = 57,
    XCB_ATOM_WEIGHT = 58,
    XCB_ATOM_POINT_SIZE = 59,
    XCB_ATOM_RESOLUTION = 60,
    XCB_ATOM_COPYRIGHT = 61,
    XCB_ATOM_NOTICE = 62,
    XCB_ATOM_FONT_NAME = 63,
    XCB_ATOM_FAMILY_NAME = 64,
    XCB_ATOM_FULL_NAME = 65,
    XCB_ATOM_CAP_HEIGHT = 66,
    XCB_ATOM_WM_CLASS = 67,
    XCB_ATOM_WM_TRANSIENT_FOR = 68
} xcb_atom_enum_t;







typedef struct xcb_selection_request_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_timestamp_t time;
    xcb_window_t owner;
    xcb_window_t requestor;
    xcb_atom_t selection;
    xcb_atom_t target;
    xcb_atom_t property;
} xcb_selection_request_event_t;







typedef struct xcb_selection_notify_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_timestamp_t time;
    xcb_window_t requestor;
    xcb_atom_t selection;
    xcb_atom_t target;
    xcb_atom_t property;
} xcb_selection_notify_event_t;

typedef enum xcb_colormap_state_t {
    XCB_COLORMAP_STATE_UNINSTALLED = 0,


    XCB_COLORMAP_STATE_INSTALLED = 1


} xcb_colormap_state_t;

typedef enum xcb_colormap_enum_t {
    XCB_COLORMAP_NONE = 0
} xcb_colormap_enum_t;







typedef struct xcb_colormap_notify_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    xcb_window_t window;
    xcb_colormap_t colormap;
    uint8_t _new;
    uint8_t state;
    uint8_t pad1[2];
} xcb_colormap_notify_event_t;




typedef union xcb_client_message_data_t {
    uint8_t data8[20];
    uint16_t data16[10];
    uint32_t data32[5];
} xcb_client_message_data_t;




typedef struct xcb_client_message_data_iterator_t {
    xcb_client_message_data_t *data;
    int rem;
    int index;
} xcb_client_message_data_iterator_t;







typedef struct xcb_client_message_event_t {
    uint8_t response_type;
    uint8_t format;
    uint16_t sequence;
    xcb_window_t window;
    xcb_atom_t type;
    xcb_client_message_data_t data;
} xcb_client_message_event_t;

typedef enum xcb_mapping_t {
    XCB_MAPPING_MODIFIER = 0,
    XCB_MAPPING_KEYBOARD = 1,
    XCB_MAPPING_POINTER = 2
} xcb_mapping_t;







typedef struct xcb_mapping_notify_event_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint8_t request;
    xcb_keycode_t first_keycode;
    uint8_t count;
    uint8_t pad1;
} xcb_mapping_notify_event_t;







typedef struct xcb_ge_generic_event_t {
    uint8_t response_type;
    uint8_t extension;
    uint16_t sequence;
    uint32_t length;
    uint16_t event_type;
    uint8_t pad0[22];
    uint32_t full_sequence;
} xcb_ge_generic_event_t;







typedef struct xcb_request_error_t {
    uint8_t response_type;
    uint8_t error_code;
    uint16_t sequence;
    uint32_t bad_value;
    uint16_t minor_opcode;
    uint8_t major_opcode;
    uint8_t pad0;
} xcb_request_error_t;







typedef struct xcb_value_error_t {
    uint8_t response_type;
    uint8_t error_code;
    uint16_t sequence;
    uint32_t bad_value;
    uint16_t minor_opcode;
    uint8_t major_opcode;
    uint8_t pad0;
} xcb_value_error_t;




typedef xcb_value_error_t xcb_window_error_t;




typedef xcb_value_error_t xcb_pixmap_error_t;




typedef xcb_value_error_t xcb_atom_error_t;




typedef xcb_value_error_t xcb_cursor_error_t;




typedef xcb_value_error_t xcb_font_error_t;




typedef xcb_request_error_t xcb_match_error_t;




typedef xcb_value_error_t xcb_drawable_error_t;




typedef xcb_request_error_t xcb_access_error_t;




typedef xcb_request_error_t xcb_alloc_error_t;




typedef xcb_value_error_t xcb_colormap_error_t;




typedef xcb_value_error_t xcb_g_context_error_t;




typedef xcb_value_error_t xcb_id_choice_error_t;




typedef xcb_request_error_t xcb_name_error_t;




typedef xcb_request_error_t xcb_length_error_t;




typedef xcb_request_error_t xcb_implementation_error_t;

typedef enum xcb_window_class_t {
    XCB_WINDOW_CLASS_COPY_FROM_PARENT = 0,
    XCB_WINDOW_CLASS_INPUT_OUTPUT = 1,
    XCB_WINDOW_CLASS_INPUT_ONLY = 2
} xcb_window_class_t;

typedef enum xcb_cw_t {
    XCB_CW_BACK_PIXMAP = 1,
    XCB_CW_BACK_PIXEL = 2,




    XCB_CW_BORDER_PIXMAP = 4,
    XCB_CW_BORDER_PIXEL = 8,




    XCB_CW_BIT_GRAVITY = 16,


    XCB_CW_WIN_GRAVITY = 32,



    XCB_CW_BACKING_STORE = 64,
    XCB_CW_BACKING_PLANES = 128,




    XCB_CW_BACKING_PIXEL = 256,






    XCB_CW_OVERRIDE_REDIRECT = 512,




    XCB_CW_SAVE_UNDER = 1024,



    XCB_CW_EVENT_MASK = 2048,



    XCB_CW_DONT_PROPAGATE = 4096,



    XCB_CW_COLORMAP = 8192,
    XCB_CW_CURSOR = 16384




} xcb_cw_t;

typedef enum xcb_back_pixmap_t {
    XCB_BACK_PIXMAP_NONE = 0,
    XCB_BACK_PIXMAP_PARENT_RELATIVE = 1
} xcb_back_pixmap_t;

typedef enum xcb_gravity_t {
    XCB_GRAVITY_BIT_FORGET = 0,
    XCB_GRAVITY_WIN_UNMAP = 0,
    XCB_GRAVITY_NORTH_WEST = 1,
    XCB_GRAVITY_NORTH = 2,
    XCB_GRAVITY_NORTH_EAST = 3,
    XCB_GRAVITY_WEST = 4,
    XCB_GRAVITY_CENTER = 5,
    XCB_GRAVITY_EAST = 6,
    XCB_GRAVITY_SOUTH_WEST = 7,
    XCB_GRAVITY_SOUTH = 8,
    XCB_GRAVITY_SOUTH_EAST = 9,
    XCB_GRAVITY_STATIC = 10
} xcb_gravity_t;







typedef struct xcb_create_window_request_t {
    uint8_t major_opcode;
    uint8_t depth;
    uint16_t length;
    xcb_window_t wid;
    xcb_window_t parent;
    int16_t x;
    int16_t y;
    uint16_t width;
    uint16_t height;
    uint16_t border_width;
    uint16_t _class;
    xcb_visualid_t visual;
    uint32_t value_mask;
} xcb_create_window_request_t;







typedef struct xcb_change_window_attributes_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
    uint32_t value_mask;
} xcb_change_window_attributes_request_t;

typedef enum xcb_map_state_t {
    XCB_MAP_STATE_UNMAPPED = 0,
    XCB_MAP_STATE_UNVIEWABLE = 1,
    XCB_MAP_STATE_VIEWABLE = 2
} xcb_map_state_t;




typedef struct xcb_get_window_attributes_cookie_t {
    unsigned int sequence;
} xcb_get_window_attributes_cookie_t;







typedef struct xcb_get_window_attributes_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
} xcb_get_window_attributes_request_t;




typedef struct xcb_get_window_attributes_reply_t {
    uint8_t response_type;
    uint8_t backing_store;
    uint16_t sequence;
    uint32_t length;
    xcb_visualid_t visual;
    uint16_t _class;
    uint8_t bit_gravity;
    uint8_t win_gravity;
    uint32_t backing_planes;
    uint32_t backing_pixel;
    uint8_t save_under;
    uint8_t map_is_installed;
    uint8_t map_state;
    uint8_t override_redirect;
    xcb_colormap_t colormap;
    uint32_t all_event_masks;
    uint32_t your_event_mask;
    uint16_t do_not_propagate_mask;
    uint8_t pad0[2];
} xcb_get_window_attributes_reply_t;







typedef struct xcb_destroy_window_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
} xcb_destroy_window_request_t;







typedef struct xcb_destroy_subwindows_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
} xcb_destroy_subwindows_request_t;

typedef enum xcb_set_mode_t {
    XCB_SET_MODE_INSERT = 0,
    XCB_SET_MODE_DELETE = 1
} xcb_set_mode_t;







typedef struct xcb_change_save_set_request_t {
    uint8_t major_opcode;
    uint8_t mode;
    uint16_t length;
    xcb_window_t window;
} xcb_change_save_set_request_t;







typedef struct xcb_reparent_window_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
    xcb_window_t parent;
    int16_t x;
    int16_t y;
} xcb_reparent_window_request_t;







typedef struct xcb_map_window_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
} xcb_map_window_request_t;







typedef struct xcb_map_subwindows_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
} xcb_map_subwindows_request_t;







typedef struct xcb_unmap_window_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
} xcb_unmap_window_request_t;







typedef struct xcb_unmap_subwindows_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
} xcb_unmap_subwindows_request_t;

typedef enum xcb_config_window_t {
    XCB_CONFIG_WINDOW_X = 1,
    XCB_CONFIG_WINDOW_Y = 2,
    XCB_CONFIG_WINDOW_WIDTH = 4,
    XCB_CONFIG_WINDOW_HEIGHT = 8,
    XCB_CONFIG_WINDOW_BORDER_WIDTH = 16,
    XCB_CONFIG_WINDOW_SIBLING = 32,
    XCB_CONFIG_WINDOW_STACK_MODE = 64
} xcb_config_window_t;

typedef enum xcb_stack_mode_t {
    XCB_STACK_MODE_ABOVE = 0,
    XCB_STACK_MODE_BELOW = 1,
    XCB_STACK_MODE_TOP_IF = 2,
    XCB_STACK_MODE_BOTTOM_IF = 3,
    XCB_STACK_MODE_OPPOSITE = 4
} xcb_stack_mode_t;







typedef struct xcb_configure_window_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
    uint16_t value_mask;
    uint8_t pad1[2];
} xcb_configure_window_request_t;

typedef enum xcb_circulate_t {
    XCB_CIRCULATE_RAISE_LOWEST = 0,
    XCB_CIRCULATE_LOWER_HIGHEST = 1
} xcb_circulate_t;







typedef struct xcb_circulate_window_request_t {
    uint8_t major_opcode;
    uint8_t direction;
    uint16_t length;
    xcb_window_t window;
} xcb_circulate_window_request_t;




typedef struct xcb_get_geometry_cookie_t {
    unsigned int sequence;
} xcb_get_geometry_cookie_t;







typedef struct xcb_get_geometry_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_drawable_t drawable;
} xcb_get_geometry_request_t;




typedef struct xcb_get_geometry_reply_t {
    uint8_t response_type;
    uint8_t depth;
    uint16_t sequence;
    uint32_t length;
    xcb_window_t root;
    int16_t x;
    int16_t y;
    uint16_t width;
    uint16_t height;
    uint16_t border_width;
    uint8_t pad0[2];
} xcb_get_geometry_reply_t;




typedef struct xcb_query_tree_cookie_t {
    unsigned int sequence;
} xcb_query_tree_cookie_t;







typedef struct xcb_query_tree_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
} xcb_query_tree_request_t;




typedef struct xcb_query_tree_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    xcb_window_t root;
    xcb_window_t parent;
    uint16_t children_len;
    uint8_t pad1[14];
} xcb_query_tree_reply_t;




typedef struct xcb_intern_atom_cookie_t {
    unsigned int sequence;
} xcb_intern_atom_cookie_t;







typedef struct xcb_intern_atom_request_t {
    uint8_t major_opcode;
    uint8_t only_if_exists;
    uint16_t length;
    uint16_t name_len;
    uint8_t pad0[2];
} xcb_intern_atom_request_t;




typedef struct xcb_intern_atom_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    xcb_atom_t atom;
} xcb_intern_atom_reply_t;




typedef struct xcb_get_atom_name_cookie_t {
    unsigned int sequence;
} xcb_get_atom_name_cookie_t;







typedef struct xcb_get_atom_name_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_atom_t atom;
} xcb_get_atom_name_request_t;




typedef struct xcb_get_atom_name_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t name_len;
    uint8_t pad1[22];
} xcb_get_atom_name_reply_t;

typedef enum xcb_prop_mode_t {
    XCB_PROP_MODE_REPLACE = 0,


    XCB_PROP_MODE_PREPEND = 1,




    XCB_PROP_MODE_APPEND = 2




} xcb_prop_mode_t;







typedef struct xcb_change_property_request_t {
    uint8_t major_opcode;
    uint8_t mode;
    uint16_t length;
    xcb_window_t window;
    xcb_atom_t property;
    xcb_atom_t type;
    uint8_t format;
    uint8_t pad0[3];
    uint32_t data_len;
} xcb_change_property_request_t;







typedef struct xcb_delete_property_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
    xcb_atom_t property;
} xcb_delete_property_request_t;

typedef enum xcb_get_property_type_t {
    XCB_GET_PROPERTY_TYPE_ANY = 0
} xcb_get_property_type_t;




typedef struct xcb_get_property_cookie_t {
    unsigned int sequence;
} xcb_get_property_cookie_t;







typedef struct xcb_get_property_request_t {
    uint8_t major_opcode;
    uint8_t _delete;
    uint16_t length;
    xcb_window_t window;
    xcb_atom_t property;
    xcb_atom_t type;
    uint32_t long_offset;
    uint32_t long_length;
} xcb_get_property_request_t;




typedef struct xcb_get_property_reply_t {
    uint8_t response_type;
    uint8_t format;
    uint16_t sequence;
    uint32_t length;
    xcb_atom_t type;
    uint32_t bytes_after;
    uint32_t value_len;
    uint8_t pad0[12];
} xcb_get_property_reply_t;




typedef struct xcb_list_properties_cookie_t {
    unsigned int sequence;
} xcb_list_properties_cookie_t;







typedef struct xcb_list_properties_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
} xcb_list_properties_request_t;




typedef struct xcb_list_properties_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t atoms_len;
    uint8_t pad1[22];
} xcb_list_properties_reply_t;







typedef struct xcb_set_selection_owner_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t owner;
    xcb_atom_t selection;
    xcb_timestamp_t time;
} xcb_set_selection_owner_request_t;




typedef struct xcb_get_selection_owner_cookie_t {
    unsigned int sequence;
} xcb_get_selection_owner_cookie_t;







typedef struct xcb_get_selection_owner_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_atom_t selection;
} xcb_get_selection_owner_request_t;




typedef struct xcb_get_selection_owner_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    xcb_window_t owner;
} xcb_get_selection_owner_reply_t;







typedef struct xcb_convert_selection_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t requestor;
    xcb_atom_t selection;
    xcb_atom_t target;
    xcb_atom_t property;
    xcb_timestamp_t time;
} xcb_convert_selection_request_t;

typedef enum xcb_send_event_dest_t {
    XCB_SEND_EVENT_DEST_POINTER_WINDOW = 0,
    XCB_SEND_EVENT_DEST_ITEM_FOCUS = 1
} xcb_send_event_dest_t;







typedef struct xcb_send_event_request_t {
    uint8_t major_opcode;
    uint8_t propagate;
    uint16_t length;
    xcb_window_t destination;
    uint32_t event_mask;
    char event[32];
} xcb_send_event_request_t;

typedef enum xcb_grab_mode_t {
    XCB_GRAB_MODE_SYNC = 0,




    XCB_GRAB_MODE_ASYNC = 1


} xcb_grab_mode_t;

typedef enum xcb_grab_status_t {
    XCB_GRAB_STATUS_SUCCESS = 0,
    XCB_GRAB_STATUS_ALREADY_GRABBED = 1,
    XCB_GRAB_STATUS_INVALID_TIME = 2,
    XCB_GRAB_STATUS_NOT_VIEWABLE = 3,
    XCB_GRAB_STATUS_FROZEN = 4
} xcb_grab_status_t;

typedef enum xcb_cursor_enum_t {
    XCB_CURSOR_NONE = 0
} xcb_cursor_enum_t;




typedef struct xcb_grab_pointer_cookie_t {
    unsigned int sequence;
} xcb_grab_pointer_cookie_t;







typedef struct xcb_grab_pointer_request_t {
    uint8_t major_opcode;
    uint8_t owner_events;
    uint16_t length;
    xcb_window_t grab_window;
    uint16_t event_mask;
    uint8_t pointer_mode;
    uint8_t keyboard_mode;
    xcb_window_t confine_to;
    xcb_cursor_t cursor;
    xcb_timestamp_t time;
} xcb_grab_pointer_request_t;




typedef struct xcb_grab_pointer_reply_t {
    uint8_t response_type;
    uint8_t status;
    uint16_t sequence;
    uint32_t length;
} xcb_grab_pointer_reply_t;







typedef struct xcb_ungrab_pointer_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_timestamp_t time;
} xcb_ungrab_pointer_request_t;

typedef enum xcb_button_index_t {
    XCB_BUTTON_INDEX_ANY = 0,


    XCB_BUTTON_INDEX_1 = 1,


    XCB_BUTTON_INDEX_2 = 2,


    XCB_BUTTON_INDEX_3 = 3,


    XCB_BUTTON_INDEX_4 = 4,


    XCB_BUTTON_INDEX_5 = 5


} xcb_button_index_t;







typedef struct xcb_grab_button_request_t {
    uint8_t major_opcode;
    uint8_t owner_events;
    uint16_t length;
    xcb_window_t grab_window;
    uint16_t event_mask;
    uint8_t pointer_mode;
    uint8_t keyboard_mode;
    xcb_window_t confine_to;
    xcb_cursor_t cursor;
    uint8_t button;
    uint8_t pad0;
    uint16_t modifiers;
} xcb_grab_button_request_t;







typedef struct xcb_ungrab_button_request_t {
    uint8_t major_opcode;
    uint8_t button;
    uint16_t length;
    xcb_window_t grab_window;
    uint16_t modifiers;
    uint8_t pad0[2];
} xcb_ungrab_button_request_t;







typedef struct xcb_change_active_pointer_grab_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_cursor_t cursor;
    xcb_timestamp_t time;
    uint16_t event_mask;
    uint8_t pad1[2];
} xcb_change_active_pointer_grab_request_t;




typedef struct xcb_grab_keyboard_cookie_t {
    unsigned int sequence;
} xcb_grab_keyboard_cookie_t;







typedef struct xcb_grab_keyboard_request_t {
    uint8_t major_opcode;
    uint8_t owner_events;
    uint16_t length;
    xcb_window_t grab_window;
    xcb_timestamp_t time;
    uint8_t pointer_mode;
    uint8_t keyboard_mode;
    uint8_t pad0[2];
} xcb_grab_keyboard_request_t;




typedef struct xcb_grab_keyboard_reply_t {
    uint8_t response_type;
    uint8_t status;
    uint16_t sequence;
    uint32_t length;
} xcb_grab_keyboard_reply_t;







typedef struct xcb_ungrab_keyboard_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_timestamp_t time;
} xcb_ungrab_keyboard_request_t;

typedef enum xcb_grab_t {
    XCB_GRAB_ANY = 0
} xcb_grab_t;







typedef struct xcb_grab_key_request_t {
    uint8_t major_opcode;
    uint8_t owner_events;
    uint16_t length;
    xcb_window_t grab_window;
    uint16_t modifiers;
    xcb_keycode_t key;
    uint8_t pointer_mode;
    uint8_t keyboard_mode;
    uint8_t pad0[3];
} xcb_grab_key_request_t;







typedef struct xcb_ungrab_key_request_t {
    uint8_t major_opcode;
    xcb_keycode_t key;
    uint16_t length;
    xcb_window_t grab_window;
    uint16_t modifiers;
    uint8_t pad0[2];
} xcb_ungrab_key_request_t;

typedef enum xcb_allow_t {
    XCB_ALLOW_ASYNC_POINTER = 0,
    XCB_ALLOW_SYNC_POINTER = 1,
    XCB_ALLOW_REPLAY_POINTER = 2,
    XCB_ALLOW_ASYNC_KEYBOARD = 3,






    XCB_ALLOW_SYNC_KEYBOARD = 4,
    XCB_ALLOW_REPLAY_KEYBOARD = 5,
    XCB_ALLOW_ASYNC_BOTH = 6,





    XCB_ALLOW_SYNC_BOTH = 7
} xcb_allow_t;







typedef struct xcb_allow_events_request_t {
    uint8_t major_opcode;
    uint8_t mode;
    uint16_t length;
    xcb_timestamp_t time;
} xcb_allow_events_request_t;







typedef struct xcb_grab_server_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
} xcb_grab_server_request_t;







typedef struct xcb_ungrab_server_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
} xcb_ungrab_server_request_t;




typedef struct xcb_query_pointer_cookie_t {
    unsigned int sequence;
} xcb_query_pointer_cookie_t;







typedef struct xcb_query_pointer_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
} xcb_query_pointer_request_t;




typedef struct xcb_query_pointer_reply_t {
    uint8_t response_type;
    uint8_t same_screen;
    uint16_t sequence;
    uint32_t length;
    xcb_window_t root;
    xcb_window_t child;
    int16_t root_x;
    int16_t root_y;
    int16_t win_x;
    int16_t win_y;
    uint16_t mask;
    uint8_t pad0[2];
} xcb_query_pointer_reply_t;




typedef struct xcb_timecoord_t {
    xcb_timestamp_t time;
    int16_t x;
    int16_t y;
} xcb_timecoord_t;




typedef struct xcb_timecoord_iterator_t {
    xcb_timecoord_t *data;
    int rem;
    int index;
} xcb_timecoord_iterator_t;




typedef struct xcb_get_motion_events_cookie_t {
    unsigned int sequence;
} xcb_get_motion_events_cookie_t;







typedef struct xcb_get_motion_events_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
    xcb_timestamp_t start;
    xcb_timestamp_t stop;
} xcb_get_motion_events_request_t;




typedef struct xcb_get_motion_events_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint32_t events_len;
    uint8_t pad1[20];
} xcb_get_motion_events_reply_t;




typedef struct xcb_translate_coordinates_cookie_t {
    unsigned int sequence;
} xcb_translate_coordinates_cookie_t;







typedef struct xcb_translate_coordinates_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t src_window;
    xcb_window_t dst_window;
    int16_t src_x;
    int16_t src_y;
} xcb_translate_coordinates_request_t;




typedef struct xcb_translate_coordinates_reply_t {
    uint8_t response_type;
    uint8_t same_screen;
    uint16_t sequence;
    uint32_t length;
    xcb_window_t child;
    int16_t dst_x;
    int16_t dst_y;
} xcb_translate_coordinates_reply_t;







typedef struct xcb_warp_pointer_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t src_window;
    xcb_window_t dst_window;
    int16_t src_x;
    int16_t src_y;
    uint16_t src_width;
    uint16_t src_height;
    int16_t dst_x;
    int16_t dst_y;
} xcb_warp_pointer_request_t;

typedef enum xcb_input_focus_t {
    XCB_INPUT_FOCUS_NONE = 0,


    XCB_INPUT_FOCUS_POINTER_ROOT = 1,




    XCB_INPUT_FOCUS_PARENT = 2,



    XCB_INPUT_FOCUS_FOLLOW_KEYBOARD = 3


} xcb_input_focus_t;







typedef struct xcb_set_input_focus_request_t {
    uint8_t major_opcode;
    uint8_t revert_to;
    uint16_t length;
    xcb_window_t focus;
    xcb_timestamp_t time;
} xcb_set_input_focus_request_t;




typedef struct xcb_get_input_focus_cookie_t {
    unsigned int sequence;
} xcb_get_input_focus_cookie_t;







typedef struct xcb_get_input_focus_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
} xcb_get_input_focus_request_t;




typedef struct xcb_get_input_focus_reply_t {
    uint8_t response_type;
    uint8_t revert_to;
    uint16_t sequence;
    uint32_t length;
    xcb_window_t focus;
} xcb_get_input_focus_reply_t;




typedef struct xcb_query_keymap_cookie_t {
    unsigned int sequence;
} xcb_query_keymap_cookie_t;







typedef struct xcb_query_keymap_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
} xcb_query_keymap_request_t;




typedef struct xcb_query_keymap_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint8_t keys[32];
} xcb_query_keymap_reply_t;







typedef struct xcb_open_font_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_font_t fid;
    uint16_t name_len;
    uint8_t pad1[2];
} xcb_open_font_request_t;







typedef struct xcb_close_font_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_font_t font;
} xcb_close_font_request_t;

typedef enum xcb_font_draw_t {
    XCB_FONT_DRAW_LEFT_TO_RIGHT = 0,
    XCB_FONT_DRAW_RIGHT_TO_LEFT = 1
} xcb_font_draw_t;




typedef struct xcb_fontprop_t {
    xcb_atom_t name;
    uint32_t value;
} xcb_fontprop_t;




typedef struct xcb_fontprop_iterator_t {
    xcb_fontprop_t *data;
    int rem;
    int index;
} xcb_fontprop_iterator_t;




typedef struct xcb_charinfo_t {
    int16_t left_side_bearing;
    int16_t right_side_bearing;
    int16_t character_width;
    int16_t ascent;
    int16_t descent;
    uint16_t attributes;
} xcb_charinfo_t;




typedef struct xcb_charinfo_iterator_t {
    xcb_charinfo_t *data;
    int rem;
    int index;
} xcb_charinfo_iterator_t;




typedef struct xcb_query_font_cookie_t {
    unsigned int sequence;
} xcb_query_font_cookie_t;







typedef struct xcb_query_font_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_fontable_t font;
} xcb_query_font_request_t;




typedef struct xcb_query_font_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    xcb_charinfo_t min_bounds;
    uint8_t pad1[4];
    xcb_charinfo_t max_bounds;
    uint8_t pad2[4];
    uint16_t min_char_or_byte2;
    uint16_t max_char_or_byte2;
    uint16_t default_char;
    uint16_t properties_len;
    uint8_t draw_direction;
    uint8_t min_byte1;
    uint8_t max_byte1;
    uint8_t all_chars_exist;
    int16_t font_ascent;
    int16_t font_descent;
    uint32_t char_infos_len;
} xcb_query_font_reply_t;




typedef struct xcb_query_text_extents_cookie_t {
    unsigned int sequence;
} xcb_query_text_extents_cookie_t;







typedef struct xcb_query_text_extents_request_t {
    uint8_t major_opcode;
    uint8_t odd_length;
    uint16_t length;
    xcb_fontable_t font;
} xcb_query_text_extents_request_t;




typedef struct xcb_query_text_extents_reply_t {
    uint8_t response_type;
    uint8_t draw_direction;
    uint16_t sequence;
    uint32_t length;
    int16_t font_ascent;
    int16_t font_descent;
    int16_t overall_ascent;
    int16_t overall_descent;
    int32_t overall_width;
    int32_t overall_left;
    int32_t overall_right;
} xcb_query_text_extents_reply_t;




typedef struct xcb_str_t {
    uint8_t name_len;
} xcb_str_t;




typedef struct xcb_str_iterator_t {
    xcb_str_t *data;
    int rem;
    int index;
} xcb_str_iterator_t;




typedef struct xcb_list_fonts_cookie_t {
    unsigned int sequence;
} xcb_list_fonts_cookie_t;







typedef struct xcb_list_fonts_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    uint16_t max_names;
    uint16_t pattern_len;
} xcb_list_fonts_request_t;




typedef struct xcb_list_fonts_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t names_len;
    uint8_t pad1[22];
} xcb_list_fonts_reply_t;




typedef struct xcb_list_fonts_with_info_cookie_t {
    unsigned int sequence;
} xcb_list_fonts_with_info_cookie_t;







typedef struct xcb_list_fonts_with_info_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    uint16_t max_names;
    uint16_t pattern_len;
} xcb_list_fonts_with_info_request_t;




typedef struct xcb_list_fonts_with_info_reply_t {
    uint8_t response_type;
    uint8_t name_len;
    uint16_t sequence;
    uint32_t length;
    xcb_charinfo_t min_bounds;
    uint8_t pad0[4];
    xcb_charinfo_t max_bounds;
    uint8_t pad1[4];
    uint16_t min_char_or_byte2;
    uint16_t max_char_or_byte2;
    uint16_t default_char;
    uint16_t properties_len;
    uint8_t draw_direction;
    uint8_t min_byte1;
    uint8_t max_byte1;
    uint8_t all_chars_exist;
    int16_t font_ascent;
    int16_t font_descent;
    uint32_t replies_hint;
} xcb_list_fonts_with_info_reply_t;







typedef struct xcb_set_font_path_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    uint16_t font_qty;
    uint8_t pad1[2];
} xcb_set_font_path_request_t;




typedef struct xcb_get_font_path_cookie_t {
    unsigned int sequence;
} xcb_get_font_path_cookie_t;







typedef struct xcb_get_font_path_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
} xcb_get_font_path_request_t;




typedef struct xcb_get_font_path_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t path_len;
    uint8_t pad1[22];
} xcb_get_font_path_reply_t;







typedef struct xcb_create_pixmap_request_t {
    uint8_t major_opcode;
    uint8_t depth;
    uint16_t length;
    xcb_pixmap_t pid;
    xcb_drawable_t drawable;
    uint16_t width;
    uint16_t height;
} xcb_create_pixmap_request_t;







typedef struct xcb_free_pixmap_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_pixmap_t pixmap;
} xcb_free_pixmap_request_t;

typedef enum xcb_gc_t {
    XCB_GC_FUNCTION = 1,


    XCB_GC_PLANE_MASK = 2,







    XCB_GC_FOREGROUND = 4,


    XCB_GC_BACKGROUND = 8,


    XCB_GC_LINE_WIDTH = 16,



    XCB_GC_LINE_STYLE = 32,
    XCB_GC_CAP_STYLE = 64,
    XCB_GC_JOIN_STYLE = 128,







    XCB_GC_FILL_STYLE = 256,
    XCB_GC_FILL_RULE = 512,


    XCB_GC_TILE = 1024,
    XCB_GC_STIPPLE = 2048,
    XCB_GC_TILE_STIPPLE_ORIGIN_X = 4096,


    XCB_GC_TILE_STIPPLE_ORIGIN_Y = 8192,


    XCB_GC_FONT = 16384,


    XCB_GC_SUBWINDOW_MODE = 32768,
    XCB_GC_GRAPHICS_EXPOSURES = 65536,




    XCB_GC_CLIP_ORIGIN_X = 131072,


    XCB_GC_CLIP_ORIGIN_Y = 262144,


    XCB_GC_CLIP_MASK = 524288,
    XCB_GC_DASH_OFFSET = 1048576,


    XCB_GC_DASH_LIST = 2097152,


    XCB_GC_ARC_MODE = 4194304


} xcb_gc_t;

typedef enum xcb_gx_t {
    XCB_GX_CLEAR = 0,
    XCB_GX_AND = 1,
    XCB_GX_AND_REVERSE = 2,
    XCB_GX_COPY = 3,
    XCB_GX_AND_INVERTED = 4,
    XCB_GX_NOOP = 5,
    XCB_GX_XOR = 6,
    XCB_GX_OR = 7,
    XCB_GX_NOR = 8,
    XCB_GX_EQUIV = 9,
    XCB_GX_INVERT = 10,
    XCB_GX_OR_REVERSE = 11,
    XCB_GX_COPY_INVERTED = 12,
    XCB_GX_OR_INVERTED = 13,
    XCB_GX_NAND = 14,
    XCB_GX_SET = 15
} xcb_gx_t;

typedef enum xcb_line_style_t {
    XCB_LINE_STYLE_SOLID = 0,
    XCB_LINE_STYLE_ON_OFF_DASH = 1,
    XCB_LINE_STYLE_DOUBLE_DASH = 2
} xcb_line_style_t;

typedef enum xcb_cap_style_t {
    XCB_CAP_STYLE_NOT_LAST = 0,
    XCB_CAP_STYLE_BUTT = 1,
    XCB_CAP_STYLE_ROUND = 2,
    XCB_CAP_STYLE_PROJECTING = 3
} xcb_cap_style_t;

typedef enum xcb_join_style_t {
    XCB_JOIN_STYLE_MITER = 0,
    XCB_JOIN_STYLE_ROUND = 1,
    XCB_JOIN_STYLE_BEVEL = 2
} xcb_join_style_t;

typedef enum xcb_fill_style_t {
    XCB_FILL_STYLE_SOLID = 0,
    XCB_FILL_STYLE_TILED = 1,
    XCB_FILL_STYLE_STIPPLED = 2,
    XCB_FILL_STYLE_OPAQUE_STIPPLED = 3
} xcb_fill_style_t;

typedef enum xcb_fill_rule_t {
    XCB_FILL_RULE_EVEN_ODD = 0,
    XCB_FILL_RULE_WINDING = 1
} xcb_fill_rule_t;

typedef enum xcb_subwindow_mode_t {
    XCB_SUBWINDOW_MODE_CLIP_BY_CHILDREN = 0,
    XCB_SUBWINDOW_MODE_INCLUDE_INFERIORS = 1
} xcb_subwindow_mode_t;

typedef enum xcb_arc_mode_t {
    XCB_ARC_MODE_CHORD = 0,
    XCB_ARC_MODE_PIE_SLICE = 1
} xcb_arc_mode_t;







typedef struct xcb_create_gc_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_gcontext_t cid;
    xcb_drawable_t drawable;
    uint32_t value_mask;
} xcb_create_gc_request_t;







typedef struct xcb_change_gc_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_gcontext_t gc;
    uint32_t value_mask;
} xcb_change_gc_request_t;







typedef struct xcb_copy_gc_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_gcontext_t src_gc;
    xcb_gcontext_t dst_gc;
    uint32_t value_mask;
} xcb_copy_gc_request_t;







typedef struct xcb_set_dashes_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_gcontext_t gc;
    uint16_t dash_offset;
    uint16_t dashes_len;
} xcb_set_dashes_request_t;

typedef enum xcb_clip_ordering_t {
    XCB_CLIP_ORDERING_UNSORTED = 0,
    XCB_CLIP_ORDERING_Y_SORTED = 1,
    XCB_CLIP_ORDERING_YX_SORTED = 2,
    XCB_CLIP_ORDERING_YX_BANDED = 3
} xcb_clip_ordering_t;







typedef struct xcb_set_clip_rectangles_request_t {
    uint8_t major_opcode;
    uint8_t ordering;
    uint16_t length;
    xcb_gcontext_t gc;
    int16_t clip_x_origin;
    int16_t clip_y_origin;
} xcb_set_clip_rectangles_request_t;







typedef struct xcb_free_gc_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_gcontext_t gc;
} xcb_free_gc_request_t;







typedef struct xcb_clear_area_request_t {
    uint8_t major_opcode;
    uint8_t exposures;
    uint16_t length;
    xcb_window_t window;
    int16_t x;
    int16_t y;
    uint16_t width;
    uint16_t height;
} xcb_clear_area_request_t;







typedef struct xcb_copy_area_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_drawable_t src_drawable;
    xcb_drawable_t dst_drawable;
    xcb_gcontext_t gc;
    int16_t src_x;
    int16_t src_y;
    int16_t dst_x;
    int16_t dst_y;
    uint16_t width;
    uint16_t height;
} xcb_copy_area_request_t;







typedef struct xcb_copy_plane_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_drawable_t src_drawable;
    xcb_drawable_t dst_drawable;
    xcb_gcontext_t gc;
    int16_t src_x;
    int16_t src_y;
    int16_t dst_x;
    int16_t dst_y;
    uint16_t width;
    uint16_t height;
    uint32_t bit_plane;
} xcb_copy_plane_request_t;

typedef enum xcb_coord_mode_t {
    XCB_COORD_MODE_ORIGIN = 0,


    XCB_COORD_MODE_PREVIOUS = 1


} xcb_coord_mode_t;







typedef struct xcb_poly_point_request_t {
    uint8_t major_opcode;
    uint8_t coordinate_mode;
    uint16_t length;
    xcb_drawable_t drawable;
    xcb_gcontext_t gc;
} xcb_poly_point_request_t;







typedef struct xcb_poly_line_request_t {
    uint8_t major_opcode;
    uint8_t coordinate_mode;
    uint16_t length;
    xcb_drawable_t drawable;
    xcb_gcontext_t gc;
} xcb_poly_line_request_t;




typedef struct xcb_segment_t {
    int16_t x1;
    int16_t y1;
    int16_t x2;
    int16_t y2;
} xcb_segment_t;




typedef struct xcb_segment_iterator_t {
    xcb_segment_t *data;
    int rem;
    int index;
} xcb_segment_iterator_t;







typedef struct xcb_poly_segment_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_drawable_t drawable;
    xcb_gcontext_t gc;
} xcb_poly_segment_request_t;







typedef struct xcb_poly_rectangle_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_drawable_t drawable;
    xcb_gcontext_t gc;
} xcb_poly_rectangle_request_t;







typedef struct xcb_poly_arc_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_drawable_t drawable;
    xcb_gcontext_t gc;
} xcb_poly_arc_request_t;

typedef enum xcb_poly_shape_t {
    XCB_POLY_SHAPE_COMPLEX = 0,
    XCB_POLY_SHAPE_NONCONVEX = 1,
    XCB_POLY_SHAPE_CONVEX = 2
} xcb_poly_shape_t;







typedef struct xcb_fill_poly_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_drawable_t drawable;
    xcb_gcontext_t gc;
    uint8_t shape;
    uint8_t coordinate_mode;
    uint8_t pad1[2];
} xcb_fill_poly_request_t;







typedef struct xcb_poly_fill_rectangle_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_drawable_t drawable;
    xcb_gcontext_t gc;
} xcb_poly_fill_rectangle_request_t;







typedef struct xcb_poly_fill_arc_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_drawable_t drawable;
    xcb_gcontext_t gc;
} xcb_poly_fill_arc_request_t;

typedef enum xcb_image_format_t {
    XCB_IMAGE_FORMAT_XY_BITMAP = 0,
    XCB_IMAGE_FORMAT_XY_PIXMAP = 1,
    XCB_IMAGE_FORMAT_Z_PIXMAP = 2
} xcb_image_format_t;







typedef struct xcb_put_image_request_t {
    uint8_t major_opcode;
    uint8_t format;
    uint16_t length;
    xcb_drawable_t drawable;
    xcb_gcontext_t gc;
    uint16_t width;
    uint16_t height;
    int16_t dst_x;
    int16_t dst_y;
    uint8_t left_pad;
    uint8_t depth;
    uint8_t pad0[2];
} xcb_put_image_request_t;




typedef struct xcb_get_image_cookie_t {
    unsigned int sequence;
} xcb_get_image_cookie_t;







typedef struct xcb_get_image_request_t {
    uint8_t major_opcode;
    uint8_t format;
    uint16_t length;
    xcb_drawable_t drawable;
    int16_t x;
    int16_t y;
    uint16_t width;
    uint16_t height;
    uint32_t plane_mask;
} xcb_get_image_request_t;




typedef struct xcb_get_image_reply_t {
    uint8_t response_type;
    uint8_t depth;
    uint16_t sequence;
    uint32_t length;
    xcb_visualid_t visual;
    uint8_t pad0[20];
} xcb_get_image_reply_t;







typedef struct xcb_poly_text_8_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_drawable_t drawable;
    xcb_gcontext_t gc;
    int16_t x;
    int16_t y;
} xcb_poly_text_8_request_t;







typedef struct xcb_poly_text_16_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_drawable_t drawable;
    xcb_gcontext_t gc;
    int16_t x;
    int16_t y;
} xcb_poly_text_16_request_t;







typedef struct xcb_image_text_8_request_t {
    uint8_t major_opcode;
    uint8_t string_len;
    uint16_t length;
    xcb_drawable_t drawable;
    xcb_gcontext_t gc;
    int16_t x;
    int16_t y;
} xcb_image_text_8_request_t;







typedef struct xcb_image_text_16_request_t {
    uint8_t major_opcode;
    uint8_t string_len;
    uint16_t length;
    xcb_drawable_t drawable;
    xcb_gcontext_t gc;
    int16_t x;
    int16_t y;
} xcb_image_text_16_request_t;

typedef enum xcb_colormap_alloc_t {
    XCB_COLORMAP_ALLOC_NONE = 0,
    XCB_COLORMAP_ALLOC_ALL = 1
} xcb_colormap_alloc_t;







typedef struct xcb_create_colormap_request_t {
    uint8_t major_opcode;
    uint8_t alloc;
    uint16_t length;
    xcb_colormap_t mid;
    xcb_window_t window;
    xcb_visualid_t visual;
} xcb_create_colormap_request_t;







typedef struct xcb_free_colormap_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_colormap_t cmap;
} xcb_free_colormap_request_t;







typedef struct xcb_copy_colormap_and_free_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_colormap_t mid;
    xcb_colormap_t src_cmap;
} xcb_copy_colormap_and_free_request_t;







typedef struct xcb_install_colormap_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_colormap_t cmap;
} xcb_install_colormap_request_t;







typedef struct xcb_uninstall_colormap_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_colormap_t cmap;
} xcb_uninstall_colormap_request_t;




typedef struct xcb_list_installed_colormaps_cookie_t {
    unsigned int sequence;
} xcb_list_installed_colormaps_cookie_t;







typedef struct xcb_list_installed_colormaps_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
} xcb_list_installed_colormaps_request_t;




typedef struct xcb_list_installed_colormaps_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t cmaps_len;
    uint8_t pad1[22];
} xcb_list_installed_colormaps_reply_t;




typedef struct xcb_alloc_color_cookie_t {
    unsigned int sequence;
} xcb_alloc_color_cookie_t;







typedef struct xcb_alloc_color_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_colormap_t cmap;
    uint16_t red;
    uint16_t green;
    uint16_t blue;
    uint8_t pad1[2];
} xcb_alloc_color_request_t;




typedef struct xcb_alloc_color_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t red;
    uint16_t green;
    uint16_t blue;
    uint8_t pad1[2];
    uint32_t pixel;
} xcb_alloc_color_reply_t;




typedef struct xcb_alloc_named_color_cookie_t {
    unsigned int sequence;
} xcb_alloc_named_color_cookie_t;







typedef struct xcb_alloc_named_color_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_colormap_t cmap;
    uint16_t name_len;
    uint8_t pad1[2];
} xcb_alloc_named_color_request_t;




typedef struct xcb_alloc_named_color_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint32_t pixel;
    uint16_t exact_red;
    uint16_t exact_green;
    uint16_t exact_blue;
    uint16_t visual_red;
    uint16_t visual_green;
    uint16_t visual_blue;
} xcb_alloc_named_color_reply_t;




typedef struct xcb_alloc_color_cells_cookie_t {
    unsigned int sequence;
} xcb_alloc_color_cells_cookie_t;







typedef struct xcb_alloc_color_cells_request_t {
    uint8_t major_opcode;
    uint8_t contiguous;
    uint16_t length;
    xcb_colormap_t cmap;
    uint16_t colors;
    uint16_t planes;
} xcb_alloc_color_cells_request_t;




typedef struct xcb_alloc_color_cells_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t pixels_len;
    uint16_t masks_len;
    uint8_t pad1[20];
} xcb_alloc_color_cells_reply_t;




typedef struct xcb_alloc_color_planes_cookie_t {
    unsigned int sequence;
} xcb_alloc_color_planes_cookie_t;







typedef struct xcb_alloc_color_planes_request_t {
    uint8_t major_opcode;
    uint8_t contiguous;
    uint16_t length;
    xcb_colormap_t cmap;
    uint16_t colors;
    uint16_t reds;
    uint16_t greens;
    uint16_t blues;
} xcb_alloc_color_planes_request_t;




typedef struct xcb_alloc_color_planes_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t pixels_len;
    uint8_t pad1[2];
    uint32_t red_mask;
    uint32_t green_mask;
    uint32_t blue_mask;
    uint8_t pad2[8];
} xcb_alloc_color_planes_reply_t;







typedef struct xcb_free_colors_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_colormap_t cmap;
    uint32_t plane_mask;
} xcb_free_colors_request_t;

typedef enum xcb_color_flag_t {
    XCB_COLOR_FLAG_RED = 1,
    XCB_COLOR_FLAG_GREEN = 2,
    XCB_COLOR_FLAG_BLUE = 4
} xcb_color_flag_t;




typedef struct xcb_coloritem_t {
    uint32_t pixel;
    uint16_t red;
    uint16_t green;
    uint16_t blue;
    uint8_t flags;
    uint8_t pad0;
} xcb_coloritem_t;




typedef struct xcb_coloritem_iterator_t {
    xcb_coloritem_t *data;
    int rem;
    int index;
} xcb_coloritem_iterator_t;







typedef struct xcb_store_colors_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_colormap_t cmap;
} xcb_store_colors_request_t;







typedef struct xcb_store_named_color_request_t {
    uint8_t major_opcode;
    uint8_t flags;
    uint16_t length;
    xcb_colormap_t cmap;
    uint32_t pixel;
    uint16_t name_len;
    uint8_t pad0[2];
} xcb_store_named_color_request_t;




typedef struct xcb_rgb_t {
    uint16_t red;
    uint16_t green;
    uint16_t blue;
    uint8_t pad0[2];
} xcb_rgb_t;




typedef struct xcb_rgb_iterator_t {
    xcb_rgb_t *data;
    int rem;
    int index;
} xcb_rgb_iterator_t;




typedef struct xcb_query_colors_cookie_t {
    unsigned int sequence;
} xcb_query_colors_cookie_t;







typedef struct xcb_query_colors_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_colormap_t cmap;
} xcb_query_colors_request_t;




typedef struct xcb_query_colors_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t colors_len;
    uint8_t pad1[22];
} xcb_query_colors_reply_t;




typedef struct xcb_lookup_color_cookie_t {
    unsigned int sequence;
} xcb_lookup_color_cookie_t;







typedef struct xcb_lookup_color_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_colormap_t cmap;
    uint16_t name_len;
    uint8_t pad1[2];
} xcb_lookup_color_request_t;




typedef struct xcb_lookup_color_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t exact_red;
    uint16_t exact_green;
    uint16_t exact_blue;
    uint16_t visual_red;
    uint16_t visual_green;
    uint16_t visual_blue;
} xcb_lookup_color_reply_t;

typedef enum xcb_pixmap_enum_t {
    XCB_PIXMAP_NONE = 0
} xcb_pixmap_enum_t;







typedef struct xcb_create_cursor_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_cursor_t cid;
    xcb_pixmap_t source;
    xcb_pixmap_t mask;
    uint16_t fore_red;
    uint16_t fore_green;
    uint16_t fore_blue;
    uint16_t back_red;
    uint16_t back_green;
    uint16_t back_blue;
    uint16_t x;
    uint16_t y;
} xcb_create_cursor_request_t;

typedef enum xcb_font_enum_t {
    XCB_FONT_NONE = 0
} xcb_font_enum_t;







typedef struct xcb_create_glyph_cursor_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_cursor_t cid;
    xcb_font_t source_font;
    xcb_font_t mask_font;
    uint16_t source_char;
    uint16_t mask_char;
    uint16_t fore_red;
    uint16_t fore_green;
    uint16_t fore_blue;
    uint16_t back_red;
    uint16_t back_green;
    uint16_t back_blue;
} xcb_create_glyph_cursor_request_t;







typedef struct xcb_free_cursor_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_cursor_t cursor;
} xcb_free_cursor_request_t;







typedef struct xcb_recolor_cursor_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_cursor_t cursor;
    uint16_t fore_red;
    uint16_t fore_green;
    uint16_t fore_blue;
    uint16_t back_red;
    uint16_t back_green;
    uint16_t back_blue;
} xcb_recolor_cursor_request_t;

typedef enum xcb_query_shape_of_t {
    XCB_QUERY_SHAPE_OF_LARGEST_CURSOR = 0,
    XCB_QUERY_SHAPE_OF_FASTEST_TILE = 1,
    XCB_QUERY_SHAPE_OF_FASTEST_STIPPLE = 2
} xcb_query_shape_of_t;




typedef struct xcb_query_best_size_cookie_t {
    unsigned int sequence;
} xcb_query_best_size_cookie_t;







typedef struct xcb_query_best_size_request_t {
    uint8_t major_opcode;
    uint8_t _class;
    uint16_t length;
    xcb_drawable_t drawable;
    uint16_t width;
    uint16_t height;
} xcb_query_best_size_request_t;




typedef struct xcb_query_best_size_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t width;
    uint16_t height;
} xcb_query_best_size_reply_t;




typedef struct xcb_query_extension_cookie_t {
    unsigned int sequence;
} xcb_query_extension_cookie_t;







typedef struct xcb_query_extension_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    uint16_t name_len;
    uint8_t pad1[2];
} xcb_query_extension_request_t;




typedef struct xcb_query_extension_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint8_t present;
    uint8_t major_opcode;
    uint8_t first_event;
    uint8_t first_error;
} xcb_query_extension_reply_t;




typedef struct xcb_list_extensions_cookie_t {
    unsigned int sequence;
} xcb_list_extensions_cookie_t;







typedef struct xcb_list_extensions_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
} xcb_list_extensions_request_t;




typedef struct xcb_list_extensions_reply_t {
    uint8_t response_type;
    uint8_t names_len;
    uint16_t sequence;
    uint32_t length;
    uint8_t pad0[24];
} xcb_list_extensions_reply_t;







typedef struct xcb_change_keyboard_mapping_request_t {
    uint8_t major_opcode;
    uint8_t keycode_count;
    uint16_t length;
    xcb_keycode_t first_keycode;
    uint8_t keysyms_per_keycode;
    uint8_t pad0[2];
} xcb_change_keyboard_mapping_request_t;




typedef struct xcb_get_keyboard_mapping_cookie_t {
    unsigned int sequence;
} xcb_get_keyboard_mapping_cookie_t;







typedef struct xcb_get_keyboard_mapping_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_keycode_t first_keycode;
    uint8_t count;
} xcb_get_keyboard_mapping_request_t;




typedef struct xcb_get_keyboard_mapping_reply_t {
    uint8_t response_type;
    uint8_t keysyms_per_keycode;
    uint16_t sequence;
    uint32_t length;
    uint8_t pad0[24];
} xcb_get_keyboard_mapping_reply_t;

typedef enum xcb_kb_t {
    XCB_KB_KEY_CLICK_PERCENT = 1,
    XCB_KB_BELL_PERCENT = 2,
    XCB_KB_BELL_PITCH = 4,
    XCB_KB_BELL_DURATION = 8,
    XCB_KB_LED = 16,
    XCB_KB_LED_MODE = 32,
    XCB_KB_KEY = 64,
    XCB_KB_AUTO_REPEAT_MODE = 128
} xcb_kb_t;

typedef enum xcb_led_mode_t {
    XCB_LED_MODE_OFF = 0,
    XCB_LED_MODE_ON = 1
} xcb_led_mode_t;

typedef enum xcb_auto_repeat_mode_t {
    XCB_AUTO_REPEAT_MODE_OFF = 0,
    XCB_AUTO_REPEAT_MODE_ON = 1,
    XCB_AUTO_REPEAT_MODE_DEFAULT = 2
} xcb_auto_repeat_mode_t;







typedef struct xcb_change_keyboard_control_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    uint32_t value_mask;
} xcb_change_keyboard_control_request_t;




typedef struct xcb_get_keyboard_control_cookie_t {
    unsigned int sequence;
} xcb_get_keyboard_control_cookie_t;







typedef struct xcb_get_keyboard_control_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
} xcb_get_keyboard_control_request_t;




typedef struct xcb_get_keyboard_control_reply_t {
    uint8_t response_type;
    uint8_t global_auto_repeat;
    uint16_t sequence;
    uint32_t length;
    uint32_t led_mask;
    uint8_t key_click_percent;
    uint8_t bell_percent;
    uint16_t bell_pitch;
    uint16_t bell_duration;
    uint8_t pad0[2];
    uint8_t auto_repeats[32];
} xcb_get_keyboard_control_reply_t;







typedef struct xcb_bell_request_t {
    uint8_t major_opcode;
    int8_t percent;
    uint16_t length;
} xcb_bell_request_t;







typedef struct xcb_change_pointer_control_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    int16_t acceleration_numerator;
    int16_t acceleration_denominator;
    int16_t threshold;
    uint8_t do_acceleration;
    uint8_t do_threshold;
} xcb_change_pointer_control_request_t;




typedef struct xcb_get_pointer_control_cookie_t {
    unsigned int sequence;
} xcb_get_pointer_control_cookie_t;







typedef struct xcb_get_pointer_control_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
} xcb_get_pointer_control_request_t;




typedef struct xcb_get_pointer_control_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t acceleration_numerator;
    uint16_t acceleration_denominator;
    uint16_t threshold;
    uint8_t pad1[18];
} xcb_get_pointer_control_reply_t;

typedef enum xcb_blanking_t {
    XCB_BLANKING_NOT_PREFERRED = 0,
    XCB_BLANKING_PREFERRED = 1,
    XCB_BLANKING_DEFAULT = 2
} xcb_blanking_t;

typedef enum xcb_exposures_t {
    XCB_EXPOSURES_NOT_ALLOWED = 0,
    XCB_EXPOSURES_ALLOWED = 1,
    XCB_EXPOSURES_DEFAULT = 2
} xcb_exposures_t;







typedef struct xcb_set_screen_saver_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    int16_t timeout;
    int16_t interval;
    uint8_t prefer_blanking;
    uint8_t allow_exposures;
} xcb_set_screen_saver_request_t;




typedef struct xcb_get_screen_saver_cookie_t {
    unsigned int sequence;
} xcb_get_screen_saver_cookie_t;







typedef struct xcb_get_screen_saver_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
} xcb_get_screen_saver_request_t;




typedef struct xcb_get_screen_saver_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t timeout;
    uint16_t interval;
    uint8_t prefer_blanking;
    uint8_t allow_exposures;
    uint8_t pad1[18];
} xcb_get_screen_saver_reply_t;

typedef enum xcb_host_mode_t {
    XCB_HOST_MODE_INSERT = 0,
    XCB_HOST_MODE_DELETE = 1
} xcb_host_mode_t;

typedef enum xcb_family_t {
    XCB_FAMILY_INTERNET = 0,
    XCB_FAMILY_DECNET = 1,
    XCB_FAMILY_CHAOS = 2,
    XCB_FAMILY_SERVER_INTERPRETED = 5,
    XCB_FAMILY_INTERNET_6 = 6
} xcb_family_t;







typedef struct xcb_change_hosts_request_t {
    uint8_t major_opcode;
    uint8_t mode;
    uint16_t length;
    uint8_t family;
    uint8_t pad0;
    uint16_t address_len;
} xcb_change_hosts_request_t;




typedef struct xcb_host_t {
    uint8_t family;
    uint8_t pad0;
    uint16_t address_len;
} xcb_host_t;




typedef struct xcb_host_iterator_t {
    xcb_host_t *data;
    int rem;
    int index;
} xcb_host_iterator_t;




typedef struct xcb_list_hosts_cookie_t {
    unsigned int sequence;
} xcb_list_hosts_cookie_t;







typedef struct xcb_list_hosts_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
} xcb_list_hosts_request_t;




typedef struct xcb_list_hosts_reply_t {
    uint8_t response_type;
    uint8_t mode;
    uint16_t sequence;
    uint32_t length;
    uint16_t hosts_len;
    uint8_t pad0[22];
} xcb_list_hosts_reply_t;

typedef enum xcb_access_control_t {
    XCB_ACCESS_CONTROL_DISABLE = 0,
    XCB_ACCESS_CONTROL_ENABLE = 1
} xcb_access_control_t;







typedef struct xcb_set_access_control_request_t {
    uint8_t major_opcode;
    uint8_t mode;
    uint16_t length;
} xcb_set_access_control_request_t;

typedef enum xcb_close_down_t {
    XCB_CLOSE_DOWN_DESTROY_ALL = 0,
    XCB_CLOSE_DOWN_RETAIN_PERMANENT = 1,
    XCB_CLOSE_DOWN_RETAIN_TEMPORARY = 2
} xcb_close_down_t;







typedef struct xcb_set_close_down_mode_request_t {
    uint8_t major_opcode;
    uint8_t mode;
    uint16_t length;
} xcb_set_close_down_mode_request_t;

typedef enum xcb_kill_t {
    XCB_KILL_ALL_TEMPORARY = 0
} xcb_kill_t;







typedef struct xcb_kill_client_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    uint32_t resource;
} xcb_kill_client_request_t;







typedef struct xcb_rotate_properties_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
    xcb_window_t window;
    uint16_t atoms_len;
    int16_t delta;
} xcb_rotate_properties_request_t;

typedef enum xcb_screen_saver_t {
    XCB_SCREEN_SAVER_RESET = 0,
    XCB_SCREEN_SAVER_ACTIVE = 1
} xcb_screen_saver_t;







typedef struct xcb_force_screen_saver_request_t {
    uint8_t major_opcode;
    uint8_t mode;
    uint16_t length;
} xcb_force_screen_saver_request_t;

typedef enum xcb_mapping_status_t {
    XCB_MAPPING_STATUS_SUCCESS = 0,
    XCB_MAPPING_STATUS_BUSY = 1,
    XCB_MAPPING_STATUS_FAILURE = 2
} xcb_mapping_status_t;




typedef struct xcb_set_pointer_mapping_cookie_t {
    unsigned int sequence;
} xcb_set_pointer_mapping_cookie_t;







typedef struct xcb_set_pointer_mapping_request_t {
    uint8_t major_opcode;
    uint8_t map_len;
    uint16_t length;
} xcb_set_pointer_mapping_request_t;




typedef struct xcb_set_pointer_mapping_reply_t {
    uint8_t response_type;
    uint8_t status;
    uint16_t sequence;
    uint32_t length;
} xcb_set_pointer_mapping_reply_t;




typedef struct xcb_get_pointer_mapping_cookie_t {
    unsigned int sequence;
} xcb_get_pointer_mapping_cookie_t;







typedef struct xcb_get_pointer_mapping_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
} xcb_get_pointer_mapping_request_t;




typedef struct xcb_get_pointer_mapping_reply_t {
    uint8_t response_type;
    uint8_t map_len;
    uint16_t sequence;
    uint32_t length;
    uint8_t pad0[24];
} xcb_get_pointer_mapping_reply_t;

typedef enum xcb_map_index_t {
    XCB_MAP_INDEX_SHIFT = 0,
    XCB_MAP_INDEX_LOCK = 1,
    XCB_MAP_INDEX_CONTROL = 2,
    XCB_MAP_INDEX_1 = 3,
    XCB_MAP_INDEX_2 = 4,
    XCB_MAP_INDEX_3 = 5,
    XCB_MAP_INDEX_4 = 6,
    XCB_MAP_INDEX_5 = 7
} xcb_map_index_t;




typedef struct xcb_set_modifier_mapping_cookie_t {
    unsigned int sequence;
} xcb_set_modifier_mapping_cookie_t;







typedef struct xcb_set_modifier_mapping_request_t {
    uint8_t major_opcode;
    uint8_t keycodes_per_modifier;
    uint16_t length;
} xcb_set_modifier_mapping_request_t;




typedef struct xcb_set_modifier_mapping_reply_t {
    uint8_t response_type;
    uint8_t status;
    uint16_t sequence;
    uint32_t length;
} xcb_set_modifier_mapping_reply_t;




typedef struct xcb_get_modifier_mapping_cookie_t {
    unsigned int sequence;
} xcb_get_modifier_mapping_cookie_t;







typedef struct xcb_get_modifier_mapping_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
} xcb_get_modifier_mapping_request_t;




typedef struct xcb_get_modifier_mapping_reply_t {
    uint8_t response_type;
    uint8_t keycodes_per_modifier;
    uint16_t sequence;
    uint32_t length;
    uint8_t pad0[24];
} xcb_get_modifier_mapping_reply_t;







typedef struct xcb_no_operation_request_t {
    uint8_t major_opcode;
    uint8_t pad0;
    uint16_t length;
} xcb_no_operation_request_t;
void
xcb_char2b_next (xcb_char2b_iterator_t *i );
xcb_generic_iterator_t
xcb_char2b_end (xcb_char2b_iterator_t i );
void
xcb_window_next (xcb_window_iterator_t *i );
xcb_generic_iterator_t
xcb_window_end (xcb_window_iterator_t i );
void
xcb_pixmap_next (xcb_pixmap_iterator_t *i );
xcb_generic_iterator_t
xcb_pixmap_end (xcb_pixmap_iterator_t i );
void
xcb_cursor_next (xcb_cursor_iterator_t *i );
xcb_generic_iterator_t
xcb_cursor_end (xcb_cursor_iterator_t i );
void
xcb_font_next (xcb_font_iterator_t *i );
xcb_generic_iterator_t
xcb_font_end (xcb_font_iterator_t i );
void
xcb_gcontext_next (xcb_gcontext_iterator_t *i );
xcb_generic_iterator_t
xcb_gcontext_end (xcb_gcontext_iterator_t i );
void
xcb_colormap_next (xcb_colormap_iterator_t *i );
xcb_generic_iterator_t
xcb_colormap_end (xcb_colormap_iterator_t i );
void
xcb_atom_next (xcb_atom_iterator_t *i );
xcb_generic_iterator_t
xcb_atom_end (xcb_atom_iterator_t i );
void
xcb_drawable_next (xcb_drawable_iterator_t *i );
xcb_generic_iterator_t
xcb_drawable_end (xcb_drawable_iterator_t i );
void
xcb_fontable_next (xcb_fontable_iterator_t *i );
xcb_generic_iterator_t
xcb_fontable_end (xcb_fontable_iterator_t i );
void
xcb_visualid_next (xcb_visualid_iterator_t *i );
xcb_generic_iterator_t
xcb_visualid_end (xcb_visualid_iterator_t i );
void
xcb_timestamp_next (xcb_timestamp_iterator_t *i );
xcb_generic_iterator_t
xcb_timestamp_end (xcb_timestamp_iterator_t i );
void
xcb_keysym_next (xcb_keysym_iterator_t *i );
xcb_generic_iterator_t
xcb_keysym_end (xcb_keysym_iterator_t i );
void
xcb_keycode_next (xcb_keycode_iterator_t *i );
xcb_generic_iterator_t
xcb_keycode_end (xcb_keycode_iterator_t i );
void
xcb_button_next (xcb_button_iterator_t *i );
xcb_generic_iterator_t
xcb_button_end (xcb_button_iterator_t i );
void
xcb_point_next (xcb_point_iterator_t *i );
xcb_generic_iterator_t
xcb_point_end (xcb_point_iterator_t i );
void
xcb_rectangle_next (xcb_rectangle_iterator_t *i );
xcb_generic_iterator_t
xcb_rectangle_end (xcb_rectangle_iterator_t i );
void
xcb_arc_next (xcb_arc_iterator_t *i );
xcb_generic_iterator_t
xcb_arc_end (xcb_arc_iterator_t i );
void
xcb_format_next (xcb_format_iterator_t *i );
xcb_generic_iterator_t
xcb_format_end (xcb_format_iterator_t i );
void
xcb_visualtype_next (xcb_visualtype_iterator_t *i );
xcb_generic_iterator_t
xcb_visualtype_end (xcb_visualtype_iterator_t i );

int
xcb_depth_sizeof (const void *_buffer );

xcb_visualtype_t *
xcb_depth_visuals (const xcb_depth_t *R );

int
xcb_depth_visuals_length (const xcb_depth_t *R );

xcb_visualtype_iterator_t
xcb_depth_visuals_iterator (const xcb_depth_t *R );
void
xcb_depth_next (xcb_depth_iterator_t *i );
xcb_generic_iterator_t
xcb_depth_end (xcb_depth_iterator_t i );

int
xcb_screen_sizeof (const void *_buffer );

int
xcb_screen_allowed_depths_length (const xcb_screen_t *R );

xcb_depth_iterator_t
xcb_screen_allowed_depths_iterator (const xcb_screen_t *R );
void
xcb_screen_next (xcb_screen_iterator_t *i );
xcb_generic_iterator_t
xcb_screen_end (xcb_screen_iterator_t i );

int
xcb_setup_request_sizeof (const void *_buffer );

char *
xcb_setup_request_authorization_protocol_name (const xcb_setup_request_t *R );

int
xcb_setup_request_authorization_protocol_name_length (const xcb_setup_request_t *R );

xcb_generic_iterator_t
xcb_setup_request_authorization_protocol_name_end (const xcb_setup_request_t *R );

char *
xcb_setup_request_authorization_protocol_data (const xcb_setup_request_t *R );

int
xcb_setup_request_authorization_protocol_data_length (const xcb_setup_request_t *R );

xcb_generic_iterator_t
xcb_setup_request_authorization_protocol_data_end (const xcb_setup_request_t *R );
void
xcb_setup_request_next (xcb_setup_request_iterator_t *i );
xcb_generic_iterator_t
xcb_setup_request_end (xcb_setup_request_iterator_t i );

int
xcb_setup_failed_sizeof (const void *_buffer );

char *
xcb_setup_failed_reason (const xcb_setup_failed_t *R );

int
xcb_setup_failed_reason_length (const xcb_setup_failed_t *R );

xcb_generic_iterator_t
xcb_setup_failed_reason_end (const xcb_setup_failed_t *R );
void
xcb_setup_failed_next (xcb_setup_failed_iterator_t *i );
xcb_generic_iterator_t
xcb_setup_failed_end (xcb_setup_failed_iterator_t i );

int
xcb_setup_authenticate_sizeof (const void *_buffer );

char *
xcb_setup_authenticate_reason (const xcb_setup_authenticate_t *R );

int
xcb_setup_authenticate_reason_length (const xcb_setup_authenticate_t *R );

xcb_generic_iterator_t
xcb_setup_authenticate_reason_end (const xcb_setup_authenticate_t *R );
void
xcb_setup_authenticate_next (xcb_setup_authenticate_iterator_t *i );
xcb_generic_iterator_t
xcb_setup_authenticate_end (xcb_setup_authenticate_iterator_t i );

int
xcb_setup_sizeof (const void *_buffer );

char *
xcb_setup_vendor (const xcb_setup_t *R );

int
xcb_setup_vendor_length (const xcb_setup_t *R );

xcb_generic_iterator_t
xcb_setup_vendor_end (const xcb_setup_t *R );

xcb_format_t *
xcb_setup_pixmap_formats (const xcb_setup_t *R );

int
xcb_setup_pixmap_formats_length (const xcb_setup_t *R );

xcb_format_iterator_t
xcb_setup_pixmap_formats_iterator (const xcb_setup_t *R );

int
xcb_setup_roots_length (const xcb_setup_t *R );

xcb_screen_iterator_t
xcb_setup_roots_iterator (const xcb_setup_t *R );
void
xcb_setup_next (xcb_setup_iterator_t *i );
xcb_generic_iterator_t
xcb_setup_end (xcb_setup_iterator_t i );
void
xcb_client_message_data_next (xcb_client_message_data_iterator_t *i );
xcb_generic_iterator_t
xcb_client_message_data_end (xcb_client_message_data_iterator_t i );

int
xcb_create_window_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_create_window_checked (xcb_connection_t *c ,
                           uint8_t depth ,
                           xcb_window_t wid ,
                           xcb_window_t parent ,
                           int16_t x ,
                           int16_t y ,
                           uint16_t width ,
                           uint16_t height ,
                           uint16_t border_width ,
                           uint16_t _class ,
                           xcb_visualid_t visual ,
                           uint32_t value_mask ,
                           const uint32_t *value_list );
xcb_void_cookie_t
xcb_create_window (xcb_connection_t *c ,
                   uint8_t depth ,
                   xcb_window_t wid ,
                   xcb_window_t parent ,
                   int16_t x ,
                   int16_t y ,
                   uint16_t width ,
                   uint16_t height ,
                   uint16_t border_width ,
                   uint16_t _class ,
                   xcb_visualid_t visual ,
                   uint32_t value_mask ,
                   const uint32_t *value_list );

int
xcb_change_window_attributes_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_change_window_attributes_checked (xcb_connection_t *c ,
                                      xcb_window_t window ,
                                      uint32_t value_mask ,
                                      const uint32_t *value_list );
xcb_void_cookie_t
xcb_change_window_attributes (xcb_connection_t *c ,
                              xcb_window_t window ,
                              uint32_t value_mask ,
                              const uint32_t *value_list );
xcb_get_window_attributes_cookie_t
xcb_get_window_attributes (xcb_connection_t *c ,
                           xcb_window_t window );
xcb_get_window_attributes_cookie_t
xcb_get_window_attributes_unchecked (xcb_connection_t *c ,
                                     xcb_window_t window );
xcb_get_window_attributes_reply_t *
xcb_get_window_attributes_reply (xcb_connection_t *c ,
                                 xcb_get_window_attributes_cookie_t cookie ,
                                 xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_destroy_window_checked (xcb_connection_t *c ,
                            xcb_window_t window );
xcb_void_cookie_t
xcb_destroy_window (xcb_connection_t *c ,
                    xcb_window_t window );
xcb_void_cookie_t
xcb_destroy_subwindows_checked (xcb_connection_t *c ,
                                xcb_window_t window );
xcb_void_cookie_t
xcb_destroy_subwindows (xcb_connection_t *c ,
                        xcb_window_t window );
xcb_void_cookie_t
xcb_change_save_set_checked (xcb_connection_t *c ,
                             uint8_t mode ,
                             xcb_window_t window );
xcb_void_cookie_t
xcb_change_save_set (xcb_connection_t *c ,
                     uint8_t mode ,
                     xcb_window_t window );
xcb_void_cookie_t
xcb_reparent_window_checked (xcb_connection_t *c ,
                             xcb_window_t window ,
                             xcb_window_t parent ,
                             int16_t x ,
                             int16_t y );
xcb_void_cookie_t
xcb_reparent_window (xcb_connection_t *c ,
                     xcb_window_t window ,
                     xcb_window_t parent ,
                     int16_t x ,
                     int16_t y );
xcb_void_cookie_t
xcb_map_window_checked (xcb_connection_t *c ,
                        xcb_window_t window );
xcb_void_cookie_t
xcb_map_window (xcb_connection_t *c ,
                xcb_window_t window );
xcb_void_cookie_t
xcb_map_subwindows_checked (xcb_connection_t *c ,
                            xcb_window_t window );
xcb_void_cookie_t
xcb_map_subwindows (xcb_connection_t *c ,
                    xcb_window_t window );
xcb_void_cookie_t
xcb_unmap_window_checked (xcb_connection_t *c ,
                          xcb_window_t window );
xcb_void_cookie_t
xcb_unmap_window (xcb_connection_t *c ,
                  xcb_window_t window );
xcb_void_cookie_t
xcb_unmap_subwindows_checked (xcb_connection_t *c ,
                              xcb_window_t window );
xcb_void_cookie_t
xcb_unmap_subwindows (xcb_connection_t *c ,
                      xcb_window_t window );

int
xcb_configure_window_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_configure_window_checked (xcb_connection_t *c ,
                              xcb_window_t window ,
                              uint16_t value_mask ,
                              const uint32_t *value_list );
xcb_void_cookie_t
xcb_configure_window (xcb_connection_t *c ,
                      xcb_window_t window ,
                      uint16_t value_mask ,
                      const uint32_t *value_list );
xcb_void_cookie_t
xcb_circulate_window_checked (xcb_connection_t *c ,
                              uint8_t direction ,
                              xcb_window_t window );
xcb_void_cookie_t
xcb_circulate_window (xcb_connection_t *c ,
                      uint8_t direction ,
                      xcb_window_t window );
xcb_get_geometry_cookie_t
xcb_get_geometry (xcb_connection_t *c ,
                  xcb_drawable_t drawable );
xcb_get_geometry_cookie_t
xcb_get_geometry_unchecked (xcb_connection_t *c ,
                            xcb_drawable_t drawable );
xcb_get_geometry_reply_t *
xcb_get_geometry_reply (xcb_connection_t *c ,
                        xcb_get_geometry_cookie_t cookie ,
                        xcb_generic_error_t **e );

int
xcb_query_tree_sizeof (const void *_buffer );
xcb_query_tree_cookie_t
xcb_query_tree (xcb_connection_t *c ,
                xcb_window_t window );
xcb_query_tree_cookie_t
xcb_query_tree_unchecked (xcb_connection_t *c ,
                          xcb_window_t window );

xcb_window_t *
xcb_query_tree_children (const xcb_query_tree_reply_t *R );

int
xcb_query_tree_children_length (const xcb_query_tree_reply_t *R );

xcb_generic_iterator_t
xcb_query_tree_children_end (const xcb_query_tree_reply_t *R );
xcb_query_tree_reply_t *
xcb_query_tree_reply (xcb_connection_t *c ,
                      xcb_query_tree_cookie_t cookie ,
                      xcb_generic_error_t **e );

int
xcb_intern_atom_sizeof (const void *_buffer );
xcb_intern_atom_cookie_t
xcb_intern_atom (xcb_connection_t *c ,
                 uint8_t only_if_exists ,
                 uint16_t name_len ,
                 const char *name );
xcb_intern_atom_cookie_t
xcb_intern_atom_unchecked (xcb_connection_t *c ,
                           uint8_t only_if_exists ,
                           uint16_t name_len ,
                           const char *name );
xcb_intern_atom_reply_t *
xcb_intern_atom_reply (xcb_connection_t *c ,
                       xcb_intern_atom_cookie_t cookie ,
                       xcb_generic_error_t **e );

int
xcb_get_atom_name_sizeof (const void *_buffer );
xcb_get_atom_name_cookie_t
xcb_get_atom_name (xcb_connection_t *c ,
                   xcb_atom_t atom );
xcb_get_atom_name_cookie_t
xcb_get_atom_name_unchecked (xcb_connection_t *c ,
                             xcb_atom_t atom );

char *
xcb_get_atom_name_name (const xcb_get_atom_name_reply_t *R );

int
xcb_get_atom_name_name_length (const xcb_get_atom_name_reply_t *R );

xcb_generic_iterator_t
xcb_get_atom_name_name_end (const xcb_get_atom_name_reply_t *R );
xcb_get_atom_name_reply_t *
xcb_get_atom_name_reply (xcb_connection_t *c ,
                         xcb_get_atom_name_cookie_t cookie ,
                         xcb_generic_error_t **e );

int
xcb_change_property_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_change_property_checked (xcb_connection_t *c ,
                             uint8_t mode ,
                             xcb_window_t window ,
                             xcb_atom_t property ,
                             xcb_atom_t type ,
                             uint8_t format ,
                             uint32_t data_len ,
                             const void *data );
xcb_void_cookie_t
xcb_change_property (xcb_connection_t *c ,
                     uint8_t mode ,
                     xcb_window_t window ,
                     xcb_atom_t property ,
                     xcb_atom_t type ,
                     uint8_t format ,
                     uint32_t data_len ,
                     const void *data );
xcb_void_cookie_t
xcb_delete_property_checked (xcb_connection_t *c ,
                             xcb_window_t window ,
                             xcb_atom_t property );
xcb_void_cookie_t
xcb_delete_property (xcb_connection_t *c ,
                     xcb_window_t window ,
                     xcb_atom_t property );

int
xcb_get_property_sizeof (const void *_buffer );
xcb_get_property_cookie_t
xcb_get_property (xcb_connection_t *c ,
                  uint8_t _delete ,
                  xcb_window_t window ,
                  xcb_atom_t property ,
                  xcb_atom_t type ,
                  uint32_t long_offset ,
                  uint32_t long_length );
xcb_get_property_cookie_t
xcb_get_property_unchecked (xcb_connection_t *c ,
                            uint8_t _delete ,
                            xcb_window_t window ,
                            xcb_atom_t property ,
                            xcb_atom_t type ,
                            uint32_t long_offset ,
                            uint32_t long_length );

void *
xcb_get_property_value (const xcb_get_property_reply_t *R );

int
xcb_get_property_value_length (const xcb_get_property_reply_t *R );

xcb_generic_iterator_t
xcb_get_property_value_end (const xcb_get_property_reply_t *R );
xcb_get_property_reply_t *
xcb_get_property_reply (xcb_connection_t *c ,
                        xcb_get_property_cookie_t cookie ,
                        xcb_generic_error_t **e );

int
xcb_list_properties_sizeof (const void *_buffer );
xcb_list_properties_cookie_t
xcb_list_properties (xcb_connection_t *c ,
                     xcb_window_t window );
xcb_list_properties_cookie_t
xcb_list_properties_unchecked (xcb_connection_t *c ,
                               xcb_window_t window );

xcb_atom_t *
xcb_list_properties_atoms (const xcb_list_properties_reply_t *R );

int
xcb_list_properties_atoms_length (const xcb_list_properties_reply_t *R );

xcb_generic_iterator_t
xcb_list_properties_atoms_end (const xcb_list_properties_reply_t *R );
xcb_list_properties_reply_t *
xcb_list_properties_reply (xcb_connection_t *c ,
                           xcb_list_properties_cookie_t cookie ,
                           xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_set_selection_owner_checked (xcb_connection_t *c ,
                                 xcb_window_t owner ,
                                 xcb_atom_t selection ,
                                 xcb_timestamp_t time );
xcb_void_cookie_t
xcb_set_selection_owner (xcb_connection_t *c ,
                         xcb_window_t owner ,
                         xcb_atom_t selection ,
                         xcb_timestamp_t time );
xcb_get_selection_owner_cookie_t
xcb_get_selection_owner (xcb_connection_t *c ,
                         xcb_atom_t selection );
xcb_get_selection_owner_cookie_t
xcb_get_selection_owner_unchecked (xcb_connection_t *c ,
                                   xcb_atom_t selection );
xcb_get_selection_owner_reply_t *
xcb_get_selection_owner_reply (xcb_connection_t *c ,
                               xcb_get_selection_owner_cookie_t cookie ,
                               xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_convert_selection_checked (xcb_connection_t *c ,
                               xcb_window_t requestor ,
                               xcb_atom_t selection ,
                               xcb_atom_t target ,
                               xcb_atom_t property ,
                               xcb_timestamp_t time );
xcb_void_cookie_t
xcb_convert_selection (xcb_connection_t *c ,
                       xcb_window_t requestor ,
                       xcb_atom_t selection ,
                       xcb_atom_t target ,
                       xcb_atom_t property ,
                       xcb_timestamp_t time );
xcb_void_cookie_t
xcb_send_event_checked (xcb_connection_t *c ,
                        uint8_t propagate ,
                        xcb_window_t destination ,
                        uint32_t event_mask ,
                        const char *event );
xcb_void_cookie_t
xcb_send_event (xcb_connection_t *c ,
                uint8_t propagate ,
                xcb_window_t destination ,
                uint32_t event_mask ,
                const char *event );
xcb_grab_pointer_cookie_t
xcb_grab_pointer (xcb_connection_t *c ,
                  uint8_t owner_events ,
                  xcb_window_t grab_window ,
                  uint16_t event_mask ,
                  uint8_t pointer_mode ,
                  uint8_t keyboard_mode ,
                  xcb_window_t confine_to ,
                  xcb_cursor_t cursor ,
                  xcb_timestamp_t time );
xcb_grab_pointer_cookie_t
xcb_grab_pointer_unchecked (xcb_connection_t *c ,
                            uint8_t owner_events ,
                            xcb_window_t grab_window ,
                            uint16_t event_mask ,
                            uint8_t pointer_mode ,
                            uint8_t keyboard_mode ,
                            xcb_window_t confine_to ,
                            xcb_cursor_t cursor ,
                            xcb_timestamp_t time );
xcb_grab_pointer_reply_t *
xcb_grab_pointer_reply (xcb_connection_t *c ,
                        xcb_grab_pointer_cookie_t cookie ,
                        xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_ungrab_pointer_checked (xcb_connection_t *c ,
                            xcb_timestamp_t time );
xcb_void_cookie_t
xcb_ungrab_pointer (xcb_connection_t *c ,
                    xcb_timestamp_t time );
xcb_void_cookie_t
xcb_grab_button_checked (xcb_connection_t *c ,
                         uint8_t owner_events ,
                         xcb_window_t grab_window ,
                         uint16_t event_mask ,
                         uint8_t pointer_mode ,
                         uint8_t keyboard_mode ,
                         xcb_window_t confine_to ,
                         xcb_cursor_t cursor ,
                         uint8_t button ,
                         uint16_t modifiers );
xcb_void_cookie_t
xcb_grab_button (xcb_connection_t *c ,
                 uint8_t owner_events ,
                 xcb_window_t grab_window ,
                 uint16_t event_mask ,
                 uint8_t pointer_mode ,
                 uint8_t keyboard_mode ,
                 xcb_window_t confine_to ,
                 xcb_cursor_t cursor ,
                 uint8_t button ,
                 uint16_t modifiers );
xcb_void_cookie_t
xcb_ungrab_button_checked (xcb_connection_t *c ,
                           uint8_t button ,
                           xcb_window_t grab_window ,
                           uint16_t modifiers );
xcb_void_cookie_t
xcb_ungrab_button (xcb_connection_t *c ,
                   uint8_t button ,
                   xcb_window_t grab_window ,
                   uint16_t modifiers );
xcb_void_cookie_t
xcb_change_active_pointer_grab_checked (xcb_connection_t *c ,
                                        xcb_cursor_t cursor ,
                                        xcb_timestamp_t time ,
                                        uint16_t event_mask );
xcb_void_cookie_t
xcb_change_active_pointer_grab (xcb_connection_t *c ,
                                xcb_cursor_t cursor ,
                                xcb_timestamp_t time ,
                                uint16_t event_mask );
xcb_grab_keyboard_cookie_t
xcb_grab_keyboard (xcb_connection_t *c ,
                   uint8_t owner_events ,
                   xcb_window_t grab_window ,
                   xcb_timestamp_t time ,
                   uint8_t pointer_mode ,
                   uint8_t keyboard_mode );
xcb_grab_keyboard_cookie_t
xcb_grab_keyboard_unchecked (xcb_connection_t *c ,
                             uint8_t owner_events ,
                             xcb_window_t grab_window ,
                             xcb_timestamp_t time ,
                             uint8_t pointer_mode ,
                             uint8_t keyboard_mode );
xcb_grab_keyboard_reply_t *
xcb_grab_keyboard_reply (xcb_connection_t *c ,
                         xcb_grab_keyboard_cookie_t cookie ,
                         xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_ungrab_keyboard_checked (xcb_connection_t *c ,
                             xcb_timestamp_t time );
xcb_void_cookie_t
xcb_ungrab_keyboard (xcb_connection_t *c ,
                     xcb_timestamp_t time );
xcb_void_cookie_t
xcb_grab_key_checked (xcb_connection_t *c ,
                      uint8_t owner_events ,
                      xcb_window_t grab_window ,
                      uint16_t modifiers ,
                      xcb_keycode_t key ,
                      uint8_t pointer_mode ,
                      uint8_t keyboard_mode );
xcb_void_cookie_t
xcb_grab_key (xcb_connection_t *c ,
              uint8_t owner_events ,
              xcb_window_t grab_window ,
              uint16_t modifiers ,
              xcb_keycode_t key ,
              uint8_t pointer_mode ,
              uint8_t keyboard_mode );
xcb_void_cookie_t
xcb_ungrab_key_checked (xcb_connection_t *c ,
                        xcb_keycode_t key ,
                        xcb_window_t grab_window ,
                        uint16_t modifiers );
xcb_void_cookie_t
xcb_ungrab_key (xcb_connection_t *c ,
                xcb_keycode_t key ,
                xcb_window_t grab_window ,
                uint16_t modifiers );
xcb_void_cookie_t
xcb_allow_events_checked (xcb_connection_t *c ,
                          uint8_t mode ,
                          xcb_timestamp_t time );
xcb_void_cookie_t
xcb_allow_events (xcb_connection_t *c ,
                  uint8_t mode ,
                  xcb_timestamp_t time );
xcb_void_cookie_t
xcb_grab_server_checked (xcb_connection_t *c );
xcb_void_cookie_t
xcb_grab_server (xcb_connection_t *c );
xcb_void_cookie_t
xcb_ungrab_server_checked (xcb_connection_t *c );
xcb_void_cookie_t
xcb_ungrab_server (xcb_connection_t *c );
xcb_query_pointer_cookie_t
xcb_query_pointer (xcb_connection_t *c ,
                   xcb_window_t window );
xcb_query_pointer_cookie_t
xcb_query_pointer_unchecked (xcb_connection_t *c ,
                             xcb_window_t window );
xcb_query_pointer_reply_t *
xcb_query_pointer_reply (xcb_connection_t *c ,
                         xcb_query_pointer_cookie_t cookie ,
                         xcb_generic_error_t **e );
void
xcb_timecoord_next (xcb_timecoord_iterator_t *i );
xcb_generic_iterator_t
xcb_timecoord_end (xcb_timecoord_iterator_t i );

int
xcb_get_motion_events_sizeof (const void *_buffer );
xcb_get_motion_events_cookie_t
xcb_get_motion_events (xcb_connection_t *c ,
                       xcb_window_t window ,
                       xcb_timestamp_t start ,
                       xcb_timestamp_t stop );
xcb_get_motion_events_cookie_t
xcb_get_motion_events_unchecked (xcb_connection_t *c ,
                                 xcb_window_t window ,
                                 xcb_timestamp_t start ,
                                 xcb_timestamp_t stop );

xcb_timecoord_t *
xcb_get_motion_events_events (const xcb_get_motion_events_reply_t *R );

int
xcb_get_motion_events_events_length (const xcb_get_motion_events_reply_t *R );

xcb_timecoord_iterator_t
xcb_get_motion_events_events_iterator (const xcb_get_motion_events_reply_t *R );
xcb_get_motion_events_reply_t *
xcb_get_motion_events_reply (xcb_connection_t *c ,
                             xcb_get_motion_events_cookie_t cookie ,
                             xcb_generic_error_t **e );
xcb_translate_coordinates_cookie_t
xcb_translate_coordinates (xcb_connection_t *c ,
                           xcb_window_t src_window ,
                           xcb_window_t dst_window ,
                           int16_t src_x ,
                           int16_t src_y );
xcb_translate_coordinates_cookie_t
xcb_translate_coordinates_unchecked (xcb_connection_t *c ,
                                     xcb_window_t src_window ,
                                     xcb_window_t dst_window ,
                                     int16_t src_x ,
                                     int16_t src_y );
xcb_translate_coordinates_reply_t *
xcb_translate_coordinates_reply (xcb_connection_t *c ,
                                 xcb_translate_coordinates_cookie_t cookie ,
                                 xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_warp_pointer_checked (xcb_connection_t *c ,
                          xcb_window_t src_window ,
                          xcb_window_t dst_window ,
                          int16_t src_x ,
                          int16_t src_y ,
                          uint16_t src_width ,
                          uint16_t src_height ,
                          int16_t dst_x ,
                          int16_t dst_y );
xcb_void_cookie_t
xcb_warp_pointer (xcb_connection_t *c ,
                  xcb_window_t src_window ,
                  xcb_window_t dst_window ,
                  int16_t src_x ,
                  int16_t src_y ,
                  uint16_t src_width ,
                  uint16_t src_height ,
                  int16_t dst_x ,
                  int16_t dst_y );
xcb_void_cookie_t
xcb_set_input_focus_checked (xcb_connection_t *c ,
                             uint8_t revert_to ,
                             xcb_window_t focus ,
                             xcb_timestamp_t time );
xcb_void_cookie_t
xcb_set_input_focus (xcb_connection_t *c ,
                     uint8_t revert_to ,
                     xcb_window_t focus ,
                     xcb_timestamp_t time );
xcb_get_input_focus_cookie_t
xcb_get_input_focus (xcb_connection_t *c );
xcb_get_input_focus_cookie_t
xcb_get_input_focus_unchecked (xcb_connection_t *c );
xcb_get_input_focus_reply_t *
xcb_get_input_focus_reply (xcb_connection_t *c ,
                           xcb_get_input_focus_cookie_t cookie ,
                           xcb_generic_error_t **e );
xcb_query_keymap_cookie_t
xcb_query_keymap (xcb_connection_t *c );
xcb_query_keymap_cookie_t
xcb_query_keymap_unchecked (xcb_connection_t *c );
xcb_query_keymap_reply_t *
xcb_query_keymap_reply (xcb_connection_t *c ,
                        xcb_query_keymap_cookie_t cookie ,
                        xcb_generic_error_t **e );

int
xcb_open_font_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_open_font_checked (xcb_connection_t *c ,
                       xcb_font_t fid ,
                       uint16_t name_len ,
                       const char *name );
xcb_void_cookie_t
xcb_open_font (xcb_connection_t *c ,
               xcb_font_t fid ,
               uint16_t name_len ,
               const char *name );
xcb_void_cookie_t
xcb_close_font_checked (xcb_connection_t *c ,
                        xcb_font_t font );
xcb_void_cookie_t
xcb_close_font (xcb_connection_t *c ,
                xcb_font_t font );
void
xcb_fontprop_next (xcb_fontprop_iterator_t *i );
xcb_generic_iterator_t
xcb_fontprop_end (xcb_fontprop_iterator_t i );
void
xcb_charinfo_next (xcb_charinfo_iterator_t *i );
xcb_generic_iterator_t
xcb_charinfo_end (xcb_charinfo_iterator_t i );

int
xcb_query_font_sizeof (const void *_buffer );
xcb_query_font_cookie_t
xcb_query_font (xcb_connection_t *c ,
                xcb_fontable_t font );
xcb_query_font_cookie_t
xcb_query_font_unchecked (xcb_connection_t *c ,
                          xcb_fontable_t font );

xcb_fontprop_t *
xcb_query_font_properties (const xcb_query_font_reply_t *R );

int
xcb_query_font_properties_length (const xcb_query_font_reply_t *R );

xcb_fontprop_iterator_t
xcb_query_font_properties_iterator (const xcb_query_font_reply_t *R );

xcb_charinfo_t *
xcb_query_font_char_infos (const xcb_query_font_reply_t *R );

int
xcb_query_font_char_infos_length (const xcb_query_font_reply_t *R );

xcb_charinfo_iterator_t
xcb_query_font_char_infos_iterator (const xcb_query_font_reply_t *R );
xcb_query_font_reply_t *
xcb_query_font_reply (xcb_connection_t *c ,
                      xcb_query_font_cookie_t cookie ,
                      xcb_generic_error_t **e );

int
xcb_query_text_extents_sizeof (const void *_buffer ,
                               uint32_t string_len );
xcb_query_text_extents_cookie_t
xcb_query_text_extents (xcb_connection_t *c ,
                        xcb_fontable_t font ,
                        uint32_t string_len ,
                        const xcb_char2b_t *string );
xcb_query_text_extents_cookie_t
xcb_query_text_extents_unchecked (xcb_connection_t *c ,
                                  xcb_fontable_t font ,
                                  uint32_t string_len ,
                                  const xcb_char2b_t *string );
xcb_query_text_extents_reply_t *
xcb_query_text_extents_reply (xcb_connection_t *c ,
                              xcb_query_text_extents_cookie_t cookie ,
                              xcb_generic_error_t **e );

int
xcb_str_sizeof (const void *_buffer );

char *
xcb_str_name (const xcb_str_t *R );

int
xcb_str_name_length (const xcb_str_t *R );

xcb_generic_iterator_t
xcb_str_name_end (const xcb_str_t *R );
void
xcb_str_next (xcb_str_iterator_t *i );
xcb_generic_iterator_t
xcb_str_end (xcb_str_iterator_t i );

int
xcb_list_fonts_sizeof (const void *_buffer );
xcb_list_fonts_cookie_t
xcb_list_fonts (xcb_connection_t *c ,
                uint16_t max_names ,
                uint16_t pattern_len ,
                const char *pattern );
xcb_list_fonts_cookie_t
xcb_list_fonts_unchecked (xcb_connection_t *c ,
                          uint16_t max_names ,
                          uint16_t pattern_len ,
                          const char *pattern );

int
xcb_list_fonts_names_length (const xcb_list_fonts_reply_t *R );

xcb_str_iterator_t
xcb_list_fonts_names_iterator (const xcb_list_fonts_reply_t *R );
xcb_list_fonts_reply_t *
xcb_list_fonts_reply (xcb_connection_t *c ,
                      xcb_list_fonts_cookie_t cookie ,
                      xcb_generic_error_t **e );

int
xcb_list_fonts_with_info_sizeof (const void *_buffer );
xcb_list_fonts_with_info_cookie_t
xcb_list_fonts_with_info (xcb_connection_t *c ,
                          uint16_t max_names ,
                          uint16_t pattern_len ,
                          const char *pattern );
xcb_list_fonts_with_info_cookie_t
xcb_list_fonts_with_info_unchecked (xcb_connection_t *c ,
                                    uint16_t max_names ,
                                    uint16_t pattern_len ,
                                    const char *pattern );

xcb_fontprop_t *
xcb_list_fonts_with_info_properties (const xcb_list_fonts_with_info_reply_t *R );

int
xcb_list_fonts_with_info_properties_length (const xcb_list_fonts_with_info_reply_t *R );

xcb_fontprop_iterator_t
xcb_list_fonts_with_info_properties_iterator (const xcb_list_fonts_with_info_reply_t *R );

char *
xcb_list_fonts_with_info_name (const xcb_list_fonts_with_info_reply_t *R );

int
xcb_list_fonts_with_info_name_length (const xcb_list_fonts_with_info_reply_t *R );

xcb_generic_iterator_t
xcb_list_fonts_with_info_name_end (const xcb_list_fonts_with_info_reply_t *R );
xcb_list_fonts_with_info_reply_t *
xcb_list_fonts_with_info_reply (xcb_connection_t *c ,
                                xcb_list_fonts_with_info_cookie_t cookie ,
                                xcb_generic_error_t **e );

int
xcb_set_font_path_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_set_font_path_checked (xcb_connection_t *c ,
                           uint16_t font_qty ,
                           const xcb_str_t *font );
xcb_void_cookie_t
xcb_set_font_path (xcb_connection_t *c ,
                   uint16_t font_qty ,
                   const xcb_str_t *font );

int
xcb_get_font_path_sizeof (const void *_buffer );
xcb_get_font_path_cookie_t
xcb_get_font_path (xcb_connection_t *c );
xcb_get_font_path_cookie_t
xcb_get_font_path_unchecked (xcb_connection_t *c );

int
xcb_get_font_path_path_length (const xcb_get_font_path_reply_t *R );

xcb_str_iterator_t
xcb_get_font_path_path_iterator (const xcb_get_font_path_reply_t *R );
xcb_get_font_path_reply_t *
xcb_get_font_path_reply (xcb_connection_t *c ,
                         xcb_get_font_path_cookie_t cookie ,
                         xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_create_pixmap_checked (xcb_connection_t *c ,
                           uint8_t depth ,
                           xcb_pixmap_t pid ,
                           xcb_drawable_t drawable ,
                           uint16_t width ,
                           uint16_t height );
xcb_void_cookie_t
xcb_create_pixmap (xcb_connection_t *c ,
                   uint8_t depth ,
                   xcb_pixmap_t pid ,
                   xcb_drawable_t drawable ,
                   uint16_t width ,
                   uint16_t height );
xcb_void_cookie_t
xcb_free_pixmap_checked (xcb_connection_t *c ,
                         xcb_pixmap_t pixmap );
xcb_void_cookie_t
xcb_free_pixmap (xcb_connection_t *c ,
                 xcb_pixmap_t pixmap );

int
xcb_create_gc_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_create_gc_checked (xcb_connection_t *c ,
                       xcb_gcontext_t cid ,
                       xcb_drawable_t drawable ,
                       uint32_t value_mask ,
                       const uint32_t *value_list );
xcb_void_cookie_t
xcb_create_gc (xcb_connection_t *c ,
               xcb_gcontext_t cid ,
               xcb_drawable_t drawable ,
               uint32_t value_mask ,
               const uint32_t *value_list );

int
xcb_change_gc_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_change_gc_checked (xcb_connection_t *c ,
                       xcb_gcontext_t gc ,
                       uint32_t value_mask ,
                       const uint32_t *value_list );
xcb_void_cookie_t
xcb_change_gc (xcb_connection_t *c ,
               xcb_gcontext_t gc ,
               uint32_t value_mask ,
               const uint32_t *value_list );
xcb_void_cookie_t
xcb_copy_gc_checked (xcb_connection_t *c ,
                     xcb_gcontext_t src_gc ,
                     xcb_gcontext_t dst_gc ,
                     uint32_t value_mask );
xcb_void_cookie_t
xcb_copy_gc (xcb_connection_t *c ,
             xcb_gcontext_t src_gc ,
             xcb_gcontext_t dst_gc ,
             uint32_t value_mask );

int
xcb_set_dashes_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_set_dashes_checked (xcb_connection_t *c ,
                        xcb_gcontext_t gc ,
                        uint16_t dash_offset ,
                        uint16_t dashes_len ,
                        const uint8_t *dashes );
xcb_void_cookie_t
xcb_set_dashes (xcb_connection_t *c ,
                xcb_gcontext_t gc ,
                uint16_t dash_offset ,
                uint16_t dashes_len ,
                const uint8_t *dashes );

int
xcb_set_clip_rectangles_sizeof (const void *_buffer ,
                                uint32_t rectangles_len );
xcb_void_cookie_t
xcb_set_clip_rectangles_checked (xcb_connection_t *c ,
                                 uint8_t ordering ,
                                 xcb_gcontext_t gc ,
                                 int16_t clip_x_origin ,
                                 int16_t clip_y_origin ,
                                 uint32_t rectangles_len ,
                                 const xcb_rectangle_t *rectangles );
xcb_void_cookie_t
xcb_set_clip_rectangles (xcb_connection_t *c ,
                         uint8_t ordering ,
                         xcb_gcontext_t gc ,
                         int16_t clip_x_origin ,
                         int16_t clip_y_origin ,
                         uint32_t rectangles_len ,
                         const xcb_rectangle_t *rectangles );
xcb_void_cookie_t
xcb_free_gc_checked (xcb_connection_t *c ,
                     xcb_gcontext_t gc );
xcb_void_cookie_t
xcb_free_gc (xcb_connection_t *c ,
             xcb_gcontext_t gc );
xcb_void_cookie_t
xcb_clear_area_checked (xcb_connection_t *c ,
                        uint8_t exposures ,
                        xcb_window_t window ,
                        int16_t x ,
                        int16_t y ,
                        uint16_t width ,
                        uint16_t height );
xcb_void_cookie_t
xcb_clear_area (xcb_connection_t *c ,
                uint8_t exposures ,
                xcb_window_t window ,
                int16_t x ,
                int16_t y ,
                uint16_t width ,
                uint16_t height );
xcb_void_cookie_t
xcb_copy_area_checked (xcb_connection_t *c ,
                       xcb_drawable_t src_drawable ,
                       xcb_drawable_t dst_drawable ,
                       xcb_gcontext_t gc ,
                       int16_t src_x ,
                       int16_t src_y ,
                       int16_t dst_x ,
                       int16_t dst_y ,
                       uint16_t width ,
                       uint16_t height );
xcb_void_cookie_t
xcb_copy_area (xcb_connection_t *c ,
               xcb_drawable_t src_drawable ,
               xcb_drawable_t dst_drawable ,
               xcb_gcontext_t gc ,
               int16_t src_x ,
               int16_t src_y ,
               int16_t dst_x ,
               int16_t dst_y ,
               uint16_t width ,
               uint16_t height );
xcb_void_cookie_t
xcb_copy_plane_checked (xcb_connection_t *c ,
                        xcb_drawable_t src_drawable ,
                        xcb_drawable_t dst_drawable ,
                        xcb_gcontext_t gc ,
                        int16_t src_x ,
                        int16_t src_y ,
                        int16_t dst_x ,
                        int16_t dst_y ,
                        uint16_t width ,
                        uint16_t height ,
                        uint32_t bit_plane );
xcb_void_cookie_t
xcb_copy_plane (xcb_connection_t *c ,
                xcb_drawable_t src_drawable ,
                xcb_drawable_t dst_drawable ,
                xcb_gcontext_t gc ,
                int16_t src_x ,
                int16_t src_y ,
                int16_t dst_x ,
                int16_t dst_y ,
                uint16_t width ,
                uint16_t height ,
                uint32_t bit_plane );

int
xcb_poly_point_sizeof (const void *_buffer ,
                       uint32_t points_len );
xcb_void_cookie_t
xcb_poly_point_checked (xcb_connection_t *c ,
                        uint8_t coordinate_mode ,
                        xcb_drawable_t drawable ,
                        xcb_gcontext_t gc ,
                        uint32_t points_len ,
                        const xcb_point_t *points );
xcb_void_cookie_t
xcb_poly_point (xcb_connection_t *c ,
                uint8_t coordinate_mode ,
                xcb_drawable_t drawable ,
                xcb_gcontext_t gc ,
                uint32_t points_len ,
                const xcb_point_t *points );

int
xcb_poly_line_sizeof (const void *_buffer ,
                      uint32_t points_len );
xcb_void_cookie_t
xcb_poly_line_checked (xcb_connection_t *c ,
                       uint8_t coordinate_mode ,
                       xcb_drawable_t drawable ,
                       xcb_gcontext_t gc ,
                       uint32_t points_len ,
                       const xcb_point_t *points );
xcb_void_cookie_t
xcb_poly_line (xcb_connection_t *c ,
               uint8_t coordinate_mode ,
               xcb_drawable_t drawable ,
               xcb_gcontext_t gc ,
               uint32_t points_len ,
               const xcb_point_t *points );
void
xcb_segment_next (xcb_segment_iterator_t *i );
xcb_generic_iterator_t
xcb_segment_end (xcb_segment_iterator_t i );

int
xcb_poly_segment_sizeof (const void *_buffer ,
                         uint32_t segments_len );
xcb_void_cookie_t
xcb_poly_segment_checked (xcb_connection_t *c ,
                          xcb_drawable_t drawable ,
                          xcb_gcontext_t gc ,
                          uint32_t segments_len ,
                          const xcb_segment_t *segments );
xcb_void_cookie_t
xcb_poly_segment (xcb_connection_t *c ,
                  xcb_drawable_t drawable ,
                  xcb_gcontext_t gc ,
                  uint32_t segments_len ,
                  const xcb_segment_t *segments );

int
xcb_poly_rectangle_sizeof (const void *_buffer ,
                           uint32_t rectangles_len );
xcb_void_cookie_t
xcb_poly_rectangle_checked (xcb_connection_t *c ,
                            xcb_drawable_t drawable ,
                            xcb_gcontext_t gc ,
                            uint32_t rectangles_len ,
                            const xcb_rectangle_t *rectangles );
xcb_void_cookie_t
xcb_poly_rectangle (xcb_connection_t *c ,
                    xcb_drawable_t drawable ,
                    xcb_gcontext_t gc ,
                    uint32_t rectangles_len ,
                    const xcb_rectangle_t *rectangles );

int
xcb_poly_arc_sizeof (const void *_buffer ,
                     uint32_t arcs_len );
xcb_void_cookie_t
xcb_poly_arc_checked (xcb_connection_t *c ,
                      xcb_drawable_t drawable ,
                      xcb_gcontext_t gc ,
                      uint32_t arcs_len ,
                      const xcb_arc_t *arcs );
xcb_void_cookie_t
xcb_poly_arc (xcb_connection_t *c ,
              xcb_drawable_t drawable ,
              xcb_gcontext_t gc ,
              uint32_t arcs_len ,
              const xcb_arc_t *arcs );

int
xcb_fill_poly_sizeof (const void *_buffer ,
                      uint32_t points_len );
xcb_void_cookie_t
xcb_fill_poly_checked (xcb_connection_t *c ,
                       xcb_drawable_t drawable ,
                       xcb_gcontext_t gc ,
                       uint8_t shape ,
                       uint8_t coordinate_mode ,
                       uint32_t points_len ,
                       const xcb_point_t *points );
xcb_void_cookie_t
xcb_fill_poly (xcb_connection_t *c ,
               xcb_drawable_t drawable ,
               xcb_gcontext_t gc ,
               uint8_t shape ,
               uint8_t coordinate_mode ,
               uint32_t points_len ,
               const xcb_point_t *points );

int
xcb_poly_fill_rectangle_sizeof (const void *_buffer ,
                                uint32_t rectangles_len );
xcb_void_cookie_t
xcb_poly_fill_rectangle_checked (xcb_connection_t *c ,
                                 xcb_drawable_t drawable ,
                                 xcb_gcontext_t gc ,
                                 uint32_t rectangles_len ,
                                 const xcb_rectangle_t *rectangles );
xcb_void_cookie_t
xcb_poly_fill_rectangle (xcb_connection_t *c ,
                         xcb_drawable_t drawable ,
                         xcb_gcontext_t gc ,
                         uint32_t rectangles_len ,
                         const xcb_rectangle_t *rectangles );

int
xcb_poly_fill_arc_sizeof (const void *_buffer ,
                          uint32_t arcs_len );
xcb_void_cookie_t
xcb_poly_fill_arc_checked (xcb_connection_t *c ,
                           xcb_drawable_t drawable ,
                           xcb_gcontext_t gc ,
                           uint32_t arcs_len ,
                           const xcb_arc_t *arcs );
xcb_void_cookie_t
xcb_poly_fill_arc (xcb_connection_t *c ,
                   xcb_drawable_t drawable ,
                   xcb_gcontext_t gc ,
                   uint32_t arcs_len ,
                   const xcb_arc_t *arcs );

int
xcb_put_image_sizeof (const void *_buffer ,
                      uint32_t data_len );
xcb_void_cookie_t
xcb_put_image_checked (xcb_connection_t *c ,
                       uint8_t format ,
                       xcb_drawable_t drawable ,
                       xcb_gcontext_t gc ,
                       uint16_t width ,
                       uint16_t height ,
                       int16_t dst_x ,
                       int16_t dst_y ,
                       uint8_t left_pad ,
                       uint8_t depth ,
                       uint32_t data_len ,
                       const uint8_t *data );
xcb_void_cookie_t
xcb_put_image (xcb_connection_t *c ,
               uint8_t format ,
               xcb_drawable_t drawable ,
               xcb_gcontext_t gc ,
               uint16_t width ,
               uint16_t height ,
               int16_t dst_x ,
               int16_t dst_y ,
               uint8_t left_pad ,
               uint8_t depth ,
               uint32_t data_len ,
               const uint8_t *data );

int
xcb_get_image_sizeof (const void *_buffer );
xcb_get_image_cookie_t
xcb_get_image (xcb_connection_t *c ,
               uint8_t format ,
               xcb_drawable_t drawable ,
               int16_t x ,
               int16_t y ,
               uint16_t width ,
               uint16_t height ,
               uint32_t plane_mask );
xcb_get_image_cookie_t
xcb_get_image_unchecked (xcb_connection_t *c ,
                         uint8_t format ,
                         xcb_drawable_t drawable ,
                         int16_t x ,
                         int16_t y ,
                         uint16_t width ,
                         uint16_t height ,
                         uint32_t plane_mask );

uint8_t *
xcb_get_image_data (const xcb_get_image_reply_t *R );

int
xcb_get_image_data_length (const xcb_get_image_reply_t *R );

xcb_generic_iterator_t
xcb_get_image_data_end (const xcb_get_image_reply_t *R );
xcb_get_image_reply_t *
xcb_get_image_reply (xcb_connection_t *c ,
                     xcb_get_image_cookie_t cookie ,
                     xcb_generic_error_t **e );

int
xcb_poly_text_8_sizeof (const void *_buffer ,
                        uint32_t items_len );
xcb_void_cookie_t
xcb_poly_text_8_checked (xcb_connection_t *c ,
                         xcb_drawable_t drawable ,
                         xcb_gcontext_t gc ,
                         int16_t x ,
                         int16_t y ,
                         uint32_t items_len ,
                         const uint8_t *items );
xcb_void_cookie_t
xcb_poly_text_8 (xcb_connection_t *c ,
                 xcb_drawable_t drawable ,
                 xcb_gcontext_t gc ,
                 int16_t x ,
                 int16_t y ,
                 uint32_t items_len ,
                 const uint8_t *items );

int
xcb_poly_text_16_sizeof (const void *_buffer ,
                         uint32_t items_len );
xcb_void_cookie_t
xcb_poly_text_16_checked (xcb_connection_t *c ,
                          xcb_drawable_t drawable ,
                          xcb_gcontext_t gc ,
                          int16_t x ,
                          int16_t y ,
                          uint32_t items_len ,
                          const uint8_t *items );
xcb_void_cookie_t
xcb_poly_text_16 (xcb_connection_t *c ,
                  xcb_drawable_t drawable ,
                  xcb_gcontext_t gc ,
                  int16_t x ,
                  int16_t y ,
                  uint32_t items_len ,
                  const uint8_t *items );

int
xcb_image_text_8_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_image_text_8_checked (xcb_connection_t *c ,
                          uint8_t string_len ,
                          xcb_drawable_t drawable ,
                          xcb_gcontext_t gc ,
                          int16_t x ,
                          int16_t y ,
                          const char *string );
xcb_void_cookie_t
xcb_image_text_8 (xcb_connection_t *c ,
                  uint8_t string_len ,
                  xcb_drawable_t drawable ,
                  xcb_gcontext_t gc ,
                  int16_t x ,
                  int16_t y ,
                  const char *string );

int
xcb_image_text_16_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_image_text_16_checked (xcb_connection_t *c ,
                           uint8_t string_len ,
                           xcb_drawable_t drawable ,
                           xcb_gcontext_t gc ,
                           int16_t x ,
                           int16_t y ,
                           const xcb_char2b_t *string );
xcb_void_cookie_t
xcb_image_text_16 (xcb_connection_t *c ,
                   uint8_t string_len ,
                   xcb_drawable_t drawable ,
                   xcb_gcontext_t gc ,
                   int16_t x ,
                   int16_t y ,
                   const xcb_char2b_t *string );
xcb_void_cookie_t
xcb_create_colormap_checked (xcb_connection_t *c ,
                             uint8_t alloc ,
                             xcb_colormap_t mid ,
                             xcb_window_t window ,
                             xcb_visualid_t visual );
xcb_void_cookie_t
xcb_create_colormap (xcb_connection_t *c ,
                     uint8_t alloc ,
                     xcb_colormap_t mid ,
                     xcb_window_t window ,
                     xcb_visualid_t visual );
xcb_void_cookie_t
xcb_free_colormap_checked (xcb_connection_t *c ,
                           xcb_colormap_t cmap );
xcb_void_cookie_t
xcb_free_colormap (xcb_connection_t *c ,
                   xcb_colormap_t cmap );
xcb_void_cookie_t
xcb_copy_colormap_and_free_checked (xcb_connection_t *c ,
                                    xcb_colormap_t mid ,
                                    xcb_colormap_t src_cmap );
xcb_void_cookie_t
xcb_copy_colormap_and_free (xcb_connection_t *c ,
                            xcb_colormap_t mid ,
                            xcb_colormap_t src_cmap );
xcb_void_cookie_t
xcb_install_colormap_checked (xcb_connection_t *c ,
                              xcb_colormap_t cmap );
xcb_void_cookie_t
xcb_install_colormap (xcb_connection_t *c ,
                      xcb_colormap_t cmap );
xcb_void_cookie_t
xcb_uninstall_colormap_checked (xcb_connection_t *c ,
                                xcb_colormap_t cmap );
xcb_void_cookie_t
xcb_uninstall_colormap (xcb_connection_t *c ,
                        xcb_colormap_t cmap );

int
xcb_list_installed_colormaps_sizeof (const void *_buffer );
xcb_list_installed_colormaps_cookie_t
xcb_list_installed_colormaps (xcb_connection_t *c ,
                              xcb_window_t window );
xcb_list_installed_colormaps_cookie_t
xcb_list_installed_colormaps_unchecked (xcb_connection_t *c ,
                                        xcb_window_t window );

xcb_colormap_t *
xcb_list_installed_colormaps_cmaps (const xcb_list_installed_colormaps_reply_t *R );

int
xcb_list_installed_colormaps_cmaps_length (const xcb_list_installed_colormaps_reply_t *R );

xcb_generic_iterator_t
xcb_list_installed_colormaps_cmaps_end (const xcb_list_installed_colormaps_reply_t *R );
xcb_list_installed_colormaps_reply_t *
xcb_list_installed_colormaps_reply (xcb_connection_t *c ,
                                    xcb_list_installed_colormaps_cookie_t cookie ,
                                    xcb_generic_error_t **e );
xcb_alloc_color_cookie_t
xcb_alloc_color (xcb_connection_t *c ,
                 xcb_colormap_t cmap ,
                 uint16_t red ,
                 uint16_t green ,
                 uint16_t blue );
xcb_alloc_color_cookie_t
xcb_alloc_color_unchecked (xcb_connection_t *c ,
                           xcb_colormap_t cmap ,
                           uint16_t red ,
                           uint16_t green ,
                           uint16_t blue );
xcb_alloc_color_reply_t *
xcb_alloc_color_reply (xcb_connection_t *c ,
                       xcb_alloc_color_cookie_t cookie ,
                       xcb_generic_error_t **e );

int
xcb_alloc_named_color_sizeof (const void *_buffer );
xcb_alloc_named_color_cookie_t
xcb_alloc_named_color (xcb_connection_t *c ,
                       xcb_colormap_t cmap ,
                       uint16_t name_len ,
                       const char *name );
xcb_alloc_named_color_cookie_t
xcb_alloc_named_color_unchecked (xcb_connection_t *c ,
                                 xcb_colormap_t cmap ,
                                 uint16_t name_len ,
                                 const char *name );
xcb_alloc_named_color_reply_t *
xcb_alloc_named_color_reply (xcb_connection_t *c ,
                             xcb_alloc_named_color_cookie_t cookie ,
                             xcb_generic_error_t **e );

int
xcb_alloc_color_cells_sizeof (const void *_buffer );
xcb_alloc_color_cells_cookie_t
xcb_alloc_color_cells (xcb_connection_t *c ,
                       uint8_t contiguous ,
                       xcb_colormap_t cmap ,
                       uint16_t colors ,
                       uint16_t planes );
xcb_alloc_color_cells_cookie_t
xcb_alloc_color_cells_unchecked (xcb_connection_t *c ,
                                 uint8_t contiguous ,
                                 xcb_colormap_t cmap ,
                                 uint16_t colors ,
                                 uint16_t planes );

uint32_t *
xcb_alloc_color_cells_pixels (const xcb_alloc_color_cells_reply_t *R );

int
xcb_alloc_color_cells_pixels_length (const xcb_alloc_color_cells_reply_t *R );

xcb_generic_iterator_t
xcb_alloc_color_cells_pixels_end (const xcb_alloc_color_cells_reply_t *R );

uint32_t *
xcb_alloc_color_cells_masks (const xcb_alloc_color_cells_reply_t *R );

int
xcb_alloc_color_cells_masks_length (const xcb_alloc_color_cells_reply_t *R );

xcb_generic_iterator_t
xcb_alloc_color_cells_masks_end (const xcb_alloc_color_cells_reply_t *R );
xcb_alloc_color_cells_reply_t *
xcb_alloc_color_cells_reply (xcb_connection_t *c ,
                             xcb_alloc_color_cells_cookie_t cookie ,
                             xcb_generic_error_t **e );

int
xcb_alloc_color_planes_sizeof (const void *_buffer );
xcb_alloc_color_planes_cookie_t
xcb_alloc_color_planes (xcb_connection_t *c ,
                        uint8_t contiguous ,
                        xcb_colormap_t cmap ,
                        uint16_t colors ,
                        uint16_t reds ,
                        uint16_t greens ,
                        uint16_t blues );
xcb_alloc_color_planes_cookie_t
xcb_alloc_color_planes_unchecked (xcb_connection_t *c ,
                                  uint8_t contiguous ,
                                  xcb_colormap_t cmap ,
                                  uint16_t colors ,
                                  uint16_t reds ,
                                  uint16_t greens ,
                                  uint16_t blues );

uint32_t *
xcb_alloc_color_planes_pixels (const xcb_alloc_color_planes_reply_t *R );

int
xcb_alloc_color_planes_pixels_length (const xcb_alloc_color_planes_reply_t *R );

xcb_generic_iterator_t
xcb_alloc_color_planes_pixels_end (const xcb_alloc_color_planes_reply_t *R );
xcb_alloc_color_planes_reply_t *
xcb_alloc_color_planes_reply (xcb_connection_t *c ,
                              xcb_alloc_color_planes_cookie_t cookie ,
                              xcb_generic_error_t **e );

int
xcb_free_colors_sizeof (const void *_buffer ,
                        uint32_t pixels_len );
xcb_void_cookie_t
xcb_free_colors_checked (xcb_connection_t *c ,
                         xcb_colormap_t cmap ,
                         uint32_t plane_mask ,
                         uint32_t pixels_len ,
                         const uint32_t *pixels );
xcb_void_cookie_t
xcb_free_colors (xcb_connection_t *c ,
                 xcb_colormap_t cmap ,
                 uint32_t plane_mask ,
                 uint32_t pixels_len ,
                 const uint32_t *pixels );
void
xcb_coloritem_next (xcb_coloritem_iterator_t *i );
xcb_generic_iterator_t
xcb_coloritem_end (xcb_coloritem_iterator_t i );

int
xcb_store_colors_sizeof (const void *_buffer ,
                         uint32_t items_len );
xcb_void_cookie_t
xcb_store_colors_checked (xcb_connection_t *c ,
                          xcb_colormap_t cmap ,
                          uint32_t items_len ,
                          const xcb_coloritem_t *items );
xcb_void_cookie_t
xcb_store_colors (xcb_connection_t *c ,
                  xcb_colormap_t cmap ,
                  uint32_t items_len ,
                  const xcb_coloritem_t *items );

int
xcb_store_named_color_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_store_named_color_checked (xcb_connection_t *c ,
                               uint8_t flags ,
                               xcb_colormap_t cmap ,
                               uint32_t pixel ,
                               uint16_t name_len ,
                               const char *name );
xcb_void_cookie_t
xcb_store_named_color (xcb_connection_t *c ,
                       uint8_t flags ,
                       xcb_colormap_t cmap ,
                       uint32_t pixel ,
                       uint16_t name_len ,
                       const char *name );
void
xcb_rgb_next (xcb_rgb_iterator_t *i );
xcb_generic_iterator_t
xcb_rgb_end (xcb_rgb_iterator_t i );

int
xcb_query_colors_sizeof (const void *_buffer ,
                         uint32_t pixels_len );
xcb_query_colors_cookie_t
xcb_query_colors (xcb_connection_t *c ,
                  xcb_colormap_t cmap ,
                  uint32_t pixels_len ,
                  const uint32_t *pixels );
xcb_query_colors_cookie_t
xcb_query_colors_unchecked (xcb_connection_t *c ,
                            xcb_colormap_t cmap ,
                            uint32_t pixels_len ,
                            const uint32_t *pixels );

xcb_rgb_t *
xcb_query_colors_colors (const xcb_query_colors_reply_t *R );

int
xcb_query_colors_colors_length (const xcb_query_colors_reply_t *R );

xcb_rgb_iterator_t
xcb_query_colors_colors_iterator (const xcb_query_colors_reply_t *R );
xcb_query_colors_reply_t *
xcb_query_colors_reply (xcb_connection_t *c ,
                        xcb_query_colors_cookie_t cookie ,
                        xcb_generic_error_t **e );

int
xcb_lookup_color_sizeof (const void *_buffer );
xcb_lookup_color_cookie_t
xcb_lookup_color (xcb_connection_t *c ,
                  xcb_colormap_t cmap ,
                  uint16_t name_len ,
                  const char *name );
xcb_lookup_color_cookie_t
xcb_lookup_color_unchecked (xcb_connection_t *c ,
                            xcb_colormap_t cmap ,
                            uint16_t name_len ,
                            const char *name );
xcb_lookup_color_reply_t *
xcb_lookup_color_reply (xcb_connection_t *c ,
                        xcb_lookup_color_cookie_t cookie ,
                        xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_create_cursor_checked (xcb_connection_t *c ,
                           xcb_cursor_t cid ,
                           xcb_pixmap_t source ,
                           xcb_pixmap_t mask ,
                           uint16_t fore_red ,
                           uint16_t fore_green ,
                           uint16_t fore_blue ,
                           uint16_t back_red ,
                           uint16_t back_green ,
                           uint16_t back_blue ,
                           uint16_t x ,
                           uint16_t y );
xcb_void_cookie_t
xcb_create_cursor (xcb_connection_t *c ,
                   xcb_cursor_t cid ,
                   xcb_pixmap_t source ,
                   xcb_pixmap_t mask ,
                   uint16_t fore_red ,
                   uint16_t fore_green ,
                   uint16_t fore_blue ,
                   uint16_t back_red ,
                   uint16_t back_green ,
                   uint16_t back_blue ,
                   uint16_t x ,
                   uint16_t y );
xcb_void_cookie_t
xcb_create_glyph_cursor_checked (xcb_connection_t *c ,
                                 xcb_cursor_t cid ,
                                 xcb_font_t source_font ,
                                 xcb_font_t mask_font ,
                                 uint16_t source_char ,
                                 uint16_t mask_char ,
                                 uint16_t fore_red ,
                                 uint16_t fore_green ,
                                 uint16_t fore_blue ,
                                 uint16_t back_red ,
                                 uint16_t back_green ,
                                 uint16_t back_blue );
xcb_void_cookie_t
xcb_create_glyph_cursor (xcb_connection_t *c ,
                         xcb_cursor_t cid ,
                         xcb_font_t source_font ,
                         xcb_font_t mask_font ,
                         uint16_t source_char ,
                         uint16_t mask_char ,
                         uint16_t fore_red ,
                         uint16_t fore_green ,
                         uint16_t fore_blue ,
                         uint16_t back_red ,
                         uint16_t back_green ,
                         uint16_t back_blue );
xcb_void_cookie_t
xcb_free_cursor_checked (xcb_connection_t *c ,
                         xcb_cursor_t cursor );
xcb_void_cookie_t
xcb_free_cursor (xcb_connection_t *c ,
                 xcb_cursor_t cursor );
xcb_void_cookie_t
xcb_recolor_cursor_checked (xcb_connection_t *c ,
                            xcb_cursor_t cursor ,
                            uint16_t fore_red ,
                            uint16_t fore_green ,
                            uint16_t fore_blue ,
                            uint16_t back_red ,
                            uint16_t back_green ,
                            uint16_t back_blue );
xcb_void_cookie_t
xcb_recolor_cursor (xcb_connection_t *c ,
                    xcb_cursor_t cursor ,
                    uint16_t fore_red ,
                    uint16_t fore_green ,
                    uint16_t fore_blue ,
                    uint16_t back_red ,
                    uint16_t back_green ,
                    uint16_t back_blue );
xcb_query_best_size_cookie_t
xcb_query_best_size (xcb_connection_t *c ,
                     uint8_t _class ,
                     xcb_drawable_t drawable ,
                     uint16_t width ,
                     uint16_t height );
xcb_query_best_size_cookie_t
xcb_query_best_size_unchecked (xcb_connection_t *c ,
                               uint8_t _class ,
                               xcb_drawable_t drawable ,
                               uint16_t width ,
                               uint16_t height );
xcb_query_best_size_reply_t *
xcb_query_best_size_reply (xcb_connection_t *c ,
                           xcb_query_best_size_cookie_t cookie ,
                           xcb_generic_error_t **e );

int
xcb_query_extension_sizeof (const void *_buffer );
xcb_query_extension_cookie_t
xcb_query_extension (xcb_connection_t *c ,
                     uint16_t name_len ,
                     const char *name );
xcb_query_extension_cookie_t
xcb_query_extension_unchecked (xcb_connection_t *c ,
                               uint16_t name_len ,
                               const char *name );
xcb_query_extension_reply_t *
xcb_query_extension_reply (xcb_connection_t *c ,
                           xcb_query_extension_cookie_t cookie ,
                           xcb_generic_error_t **e );

int
xcb_list_extensions_sizeof (const void *_buffer );
xcb_list_extensions_cookie_t
xcb_list_extensions (xcb_connection_t *c );
xcb_list_extensions_cookie_t
xcb_list_extensions_unchecked (xcb_connection_t *c );

int
xcb_list_extensions_names_length (const xcb_list_extensions_reply_t *R );

xcb_str_iterator_t
xcb_list_extensions_names_iterator (const xcb_list_extensions_reply_t *R );
xcb_list_extensions_reply_t *
xcb_list_extensions_reply (xcb_connection_t *c ,
                           xcb_list_extensions_cookie_t cookie ,
                           xcb_generic_error_t **e );

int
xcb_change_keyboard_mapping_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_change_keyboard_mapping_checked (xcb_connection_t *c ,
                                     uint8_t keycode_count ,
                                     xcb_keycode_t first_keycode ,
                                     uint8_t keysyms_per_keycode ,
                                     const xcb_keysym_t *keysyms );
xcb_void_cookie_t
xcb_change_keyboard_mapping (xcb_connection_t *c ,
                             uint8_t keycode_count ,
                             xcb_keycode_t first_keycode ,
                             uint8_t keysyms_per_keycode ,
                             const xcb_keysym_t *keysyms );

int
xcb_get_keyboard_mapping_sizeof (const void *_buffer );
xcb_get_keyboard_mapping_cookie_t
xcb_get_keyboard_mapping (xcb_connection_t *c ,
                          xcb_keycode_t first_keycode ,
                          uint8_t count );
xcb_get_keyboard_mapping_cookie_t
xcb_get_keyboard_mapping_unchecked (xcb_connection_t *c ,
                                    xcb_keycode_t first_keycode ,
                                    uint8_t count );

xcb_keysym_t *
xcb_get_keyboard_mapping_keysyms (const xcb_get_keyboard_mapping_reply_t *R );

int
xcb_get_keyboard_mapping_keysyms_length (const xcb_get_keyboard_mapping_reply_t *R );

xcb_generic_iterator_t
xcb_get_keyboard_mapping_keysyms_end (const xcb_get_keyboard_mapping_reply_t *R );
xcb_get_keyboard_mapping_reply_t *
xcb_get_keyboard_mapping_reply (xcb_connection_t *c ,
                                xcb_get_keyboard_mapping_cookie_t cookie ,
                                xcb_generic_error_t **e );

int
xcb_change_keyboard_control_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_change_keyboard_control_checked (xcb_connection_t *c ,
                                     uint32_t value_mask ,
                                     const uint32_t *value_list );
xcb_void_cookie_t
xcb_change_keyboard_control (xcb_connection_t *c ,
                             uint32_t value_mask ,
                             const uint32_t *value_list );
xcb_get_keyboard_control_cookie_t
xcb_get_keyboard_control (xcb_connection_t *c );
xcb_get_keyboard_control_cookie_t
xcb_get_keyboard_control_unchecked (xcb_connection_t *c );
xcb_get_keyboard_control_reply_t *
xcb_get_keyboard_control_reply (xcb_connection_t *c ,
                                xcb_get_keyboard_control_cookie_t cookie ,
                                xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_bell_checked (xcb_connection_t *c ,
                  int8_t percent );
xcb_void_cookie_t
xcb_bell (xcb_connection_t *c ,
          int8_t percent );
xcb_void_cookie_t
xcb_change_pointer_control_checked (xcb_connection_t *c ,
                                    int16_t acceleration_numerator ,
                                    int16_t acceleration_denominator ,
                                    int16_t threshold ,
                                    uint8_t do_acceleration ,
                                    uint8_t do_threshold );
xcb_void_cookie_t
xcb_change_pointer_control (xcb_connection_t *c ,
                            int16_t acceleration_numerator ,
                            int16_t acceleration_denominator ,
                            int16_t threshold ,
                            uint8_t do_acceleration ,
                            uint8_t do_threshold );
xcb_get_pointer_control_cookie_t
xcb_get_pointer_control (xcb_connection_t *c );
xcb_get_pointer_control_cookie_t
xcb_get_pointer_control_unchecked (xcb_connection_t *c );
xcb_get_pointer_control_reply_t *
xcb_get_pointer_control_reply (xcb_connection_t *c ,
                               xcb_get_pointer_control_cookie_t cookie ,
                               xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_set_screen_saver_checked (xcb_connection_t *c ,
                              int16_t timeout ,
                              int16_t interval ,
                              uint8_t prefer_blanking ,
                              uint8_t allow_exposures );
xcb_void_cookie_t
xcb_set_screen_saver (xcb_connection_t *c ,
                      int16_t timeout ,
                      int16_t interval ,
                      uint8_t prefer_blanking ,
                      uint8_t allow_exposures );
xcb_get_screen_saver_cookie_t
xcb_get_screen_saver (xcb_connection_t *c );
xcb_get_screen_saver_cookie_t
xcb_get_screen_saver_unchecked (xcb_connection_t *c );
xcb_get_screen_saver_reply_t *
xcb_get_screen_saver_reply (xcb_connection_t *c ,
                            xcb_get_screen_saver_cookie_t cookie ,
                            xcb_generic_error_t **e );

int
xcb_change_hosts_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_change_hosts_checked (xcb_connection_t *c ,
                          uint8_t mode ,
                          uint8_t family ,
                          uint16_t address_len ,
                          const uint8_t *address );
xcb_void_cookie_t
xcb_change_hosts (xcb_connection_t *c ,
                  uint8_t mode ,
                  uint8_t family ,
                  uint16_t address_len ,
                  const uint8_t *address );

int
xcb_host_sizeof (const void *_buffer );

uint8_t *
xcb_host_address (const xcb_host_t *R );

int
xcb_host_address_length (const xcb_host_t *R );

xcb_generic_iterator_t
xcb_host_address_end (const xcb_host_t *R );
void
xcb_host_next (xcb_host_iterator_t *i );
xcb_generic_iterator_t
xcb_host_end (xcb_host_iterator_t i );

int
xcb_list_hosts_sizeof (const void *_buffer );
xcb_list_hosts_cookie_t
xcb_list_hosts (xcb_connection_t *c );
xcb_list_hosts_cookie_t
xcb_list_hosts_unchecked (xcb_connection_t *c );

int
xcb_list_hosts_hosts_length (const xcb_list_hosts_reply_t *R );

xcb_host_iterator_t
xcb_list_hosts_hosts_iterator (const xcb_list_hosts_reply_t *R );
xcb_list_hosts_reply_t *
xcb_list_hosts_reply (xcb_connection_t *c ,
                      xcb_list_hosts_cookie_t cookie ,
                      xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_set_access_control_checked (xcb_connection_t *c ,
                                uint8_t mode );
xcb_void_cookie_t
xcb_set_access_control (xcb_connection_t *c ,
                        uint8_t mode );
xcb_void_cookie_t
xcb_set_close_down_mode_checked (xcb_connection_t *c ,
                                 uint8_t mode );
xcb_void_cookie_t
xcb_set_close_down_mode (xcb_connection_t *c ,
                         uint8_t mode );
xcb_void_cookie_t
xcb_kill_client_checked (xcb_connection_t *c ,
                         uint32_t resource );
xcb_void_cookie_t
xcb_kill_client (xcb_connection_t *c ,
                 uint32_t resource );

int
xcb_rotate_properties_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_rotate_properties_checked (xcb_connection_t *c ,
                               xcb_window_t window ,
                               uint16_t atoms_len ,
                               int16_t delta ,
                               const xcb_atom_t *atoms );
xcb_void_cookie_t
xcb_rotate_properties (xcb_connection_t *c ,
                       xcb_window_t window ,
                       uint16_t atoms_len ,
                       int16_t delta ,
                       const xcb_atom_t *atoms );
xcb_void_cookie_t
xcb_force_screen_saver_checked (xcb_connection_t *c ,
                                uint8_t mode );
xcb_void_cookie_t
xcb_force_screen_saver (xcb_connection_t *c ,
                        uint8_t mode );

int
xcb_set_pointer_mapping_sizeof (const void *_buffer );
xcb_set_pointer_mapping_cookie_t
xcb_set_pointer_mapping (xcb_connection_t *c ,
                         uint8_t map_len ,
                         const uint8_t *map );
xcb_set_pointer_mapping_cookie_t
xcb_set_pointer_mapping_unchecked (xcb_connection_t *c ,
                                   uint8_t map_len ,
                                   const uint8_t *map );
xcb_set_pointer_mapping_reply_t *
xcb_set_pointer_mapping_reply (xcb_connection_t *c ,
                               xcb_set_pointer_mapping_cookie_t cookie ,
                               xcb_generic_error_t **e );

int
xcb_get_pointer_mapping_sizeof (const void *_buffer );
xcb_get_pointer_mapping_cookie_t
xcb_get_pointer_mapping (xcb_connection_t *c );
xcb_get_pointer_mapping_cookie_t
xcb_get_pointer_mapping_unchecked (xcb_connection_t *c );

uint8_t *
xcb_get_pointer_mapping_map (const xcb_get_pointer_mapping_reply_t *R );

int
xcb_get_pointer_mapping_map_length (const xcb_get_pointer_mapping_reply_t *R );

xcb_generic_iterator_t
xcb_get_pointer_mapping_map_end (const xcb_get_pointer_mapping_reply_t *R );
xcb_get_pointer_mapping_reply_t *
xcb_get_pointer_mapping_reply (xcb_connection_t *c ,
                               xcb_get_pointer_mapping_cookie_t cookie ,
                               xcb_generic_error_t **e );

int
xcb_set_modifier_mapping_sizeof (const void *_buffer );
xcb_set_modifier_mapping_cookie_t
xcb_set_modifier_mapping (xcb_connection_t *c ,
                          uint8_t keycodes_per_modifier ,
                          const xcb_keycode_t *keycodes );
xcb_set_modifier_mapping_cookie_t
xcb_set_modifier_mapping_unchecked (xcb_connection_t *c ,
                                    uint8_t keycodes_per_modifier ,
                                    const xcb_keycode_t *keycodes );
xcb_set_modifier_mapping_reply_t *
xcb_set_modifier_mapping_reply (xcb_connection_t *c ,
                                xcb_set_modifier_mapping_cookie_t cookie ,
                                xcb_generic_error_t **e );

int
xcb_get_modifier_mapping_sizeof (const void *_buffer );
xcb_get_modifier_mapping_cookie_t
xcb_get_modifier_mapping (xcb_connection_t *c );
xcb_get_modifier_mapping_cookie_t
xcb_get_modifier_mapping_unchecked (xcb_connection_t *c );

xcb_keycode_t *
xcb_get_modifier_mapping_keycodes (const xcb_get_modifier_mapping_reply_t *R );

int
xcb_get_modifier_mapping_keycodes_length (const xcb_get_modifier_mapping_reply_t *R );

xcb_generic_iterator_t
xcb_get_modifier_mapping_keycodes_end (const xcb_get_modifier_mapping_reply_t *R );
xcb_get_modifier_mapping_reply_t *
xcb_get_modifier_mapping_reply (xcb_connection_t *c ,
                                xcb_get_modifier_mapping_cookie_t cookie ,
                                xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_no_operation_checked (xcb_connection_t *c );
xcb_void_cookie_t
xcb_no_operation (xcb_connection_t *c );
typedef struct xcb_auth_info_t {
    int namelen;
    char *name;
    int datalen;
    char *data;
} xcb_auth_info_t;
int xcb_flush(xcb_connection_t *c);
uint32_t xcb_get_maximum_request_length(xcb_connection_t *c);
void xcb_prefetch_maximum_request_length(xcb_connection_t *c);
xcb_generic_event_t *xcb_wait_for_event(xcb_connection_t *c);
xcb_generic_event_t *xcb_poll_for_event(xcb_connection_t *c);
xcb_generic_event_t *xcb_poll_for_queued_event(xcb_connection_t *c);

typedef struct xcb_special_event xcb_special_event_t;




xcb_generic_event_t *xcb_poll_for_special_event(xcb_connection_t *c,
                                                xcb_special_event_t *se);




xcb_generic_event_t *xcb_wait_for_special_event(xcb_connection_t *c,
                                                xcb_special_event_t *se);



typedef struct xcb_extension_t xcb_extension_t;




xcb_special_event_t *xcb_register_for_special_xge(xcb_connection_t *c,
                                                  xcb_extension_t *ext,
                                                  uint32_t eid,
                                                  uint32_t *stamp);




void xcb_unregister_for_special_event(xcb_connection_t *c,
                                      xcb_special_event_t *se);
xcb_generic_error_t *xcb_request_check(xcb_connection_t *c, xcb_void_cookie_t cookie);
void xcb_discard_reply(xcb_connection_t *c, unsigned int sequence);
void xcb_discard_reply64(xcb_connection_t *c, uint64_t sequence);
const struct xcb_query_extension_reply_t *xcb_get_extension_data(xcb_connection_t *c, xcb_extension_t *ext);
void xcb_prefetch_extension_data(xcb_connection_t *c, xcb_extension_t *ext);
const struct xcb_setup_t *xcb_get_setup(xcb_connection_t *c);
int xcb_get_file_descriptor(xcb_connection_t *c);
int xcb_connection_has_error(xcb_connection_t *c);
xcb_connection_t *xcb_connect_to_fd(int fd, xcb_auth_info_t *auth_info);
void xcb_disconnect(xcb_connection_t *c);
int xcb_parse_display(const char *name, char **host, int *display, int *screen);
xcb_connection_t *xcb_connect(const char *displayname, int *screenp);
xcb_connection_t *xcb_connect_to_display_with_auth_info(const char *display, xcb_auth_info_t *auth, int *screen);
uint32_t xcb_generate_id(xcb_connection_t *c);
uint8_t xcb_aux_get_depth (xcb_connection_t *c,
                                          xcb_screen_t *screen);

uint8_t xcb_aux_get_depth_of_visual (xcb_screen_t *screen,
       xcb_visualid_t id);

xcb_screen_t *xcb_aux_get_screen (xcb_connection_t *c,
                                          int screen);

xcb_visualtype_t *xcb_aux_get_visualtype (xcb_connection_t *c,
                                          int screen,
                                          xcb_visualid_t vid);

xcb_visualtype_t *
xcb_aux_find_visual_by_id (xcb_screen_t *screen,
      xcb_visualid_t id);

xcb_visualtype_t *
xcb_aux_find_visual_by_attrs (xcb_screen_t *screen,
         int8_t class_,
         int8_t depth);

void xcb_aux_sync (xcb_connection_t *c);
typedef struct {
    uint32_t back_pixmap;
    uint32_t back_pixel;
    uint32_t border_pixmap;
    uint32_t border_pixel;
    uint32_t bit_gravity;
    uint32_t win_gravity;
    uint32_t backing_store;
    uint32_t backing_planes;
    uint32_t backing_pixel;
    uint32_t override_redirect;
    uint32_t save_under;
    uint32_t event_mask;
    uint32_t dont_propagate;
    uint32_t colormap;
    uint32_t cursor;
} xcb_params_cw_t;

xcb_void_cookie_t
xcb_aux_create_window (xcb_connection_t *c,
                       uint8_t depth,
                       xcb_window_t wid,
                       xcb_window_t parent,
                       int16_t x,
                       int16_t y,
                       uint16_t width,
                       uint16_t height,
                       uint16_t border_width,
                       uint16_t class_,
                       xcb_visualid_t visual,
                       uint32_t mask,
                       const xcb_params_cw_t *params);

xcb_void_cookie_t
xcb_aux_create_window_checked (xcb_connection_t *c,
          uint8_t depth,
          xcb_window_t wid,
          xcb_window_t parent,
          int16_t x,
          int16_t y,
          uint16_t width,
          uint16_t height,
          uint16_t border_width,
          uint16_t class_,
          xcb_visualid_t visual,
          uint32_t mask,
          const xcb_params_cw_t *params);

xcb_void_cookie_t
xcb_aux_change_window_attributes (xcb_connection_t *c,
                                  xcb_window_t window,
                                  uint32_t mask,
                                  const xcb_params_cw_t *params);

xcb_void_cookie_t
xcb_aux_change_window_attributes_checked (xcb_connection_t *c,
                                          xcb_window_t window,
                                          uint32_t mask,
                                          const xcb_params_cw_t *params);

typedef struct {
    int32_t x;
    int32_t y;
    uint32_t width;
    uint32_t height;
    uint32_t border_width;
    uint32_t sibling;
    uint32_t stack_mode;
} xcb_params_configure_window_t;

xcb_void_cookie_t
xcb_aux_configure_window (xcb_connection_t *c,
                          xcb_window_t window,
                          uint16_t mask,
                          const xcb_params_configure_window_t *params);

typedef struct {
    uint32_t function;
    uint32_t plane_mask;
    uint32_t foreground;
    uint32_t background;
    uint32_t line_width;
    uint32_t line_style;
    uint32_t cap_style;
    uint32_t join_style;
    uint32_t fill_style;
    uint32_t fill_rule;
    uint32_t tile;
    uint32_t stipple;
    uint32_t tile_stipple_origin_x;
    uint32_t tile_stipple_origin_y;
    uint32_t font;
    uint32_t subwindow_mode;
    uint32_t graphics_exposures;
    uint32_t clip_originX;
    uint32_t clip_originY;
    uint32_t mask;
    uint32_t dash_offset;
    uint32_t dash_list;
    uint32_t arc_mode;
} xcb_params_gc_t;

xcb_void_cookie_t
xcb_aux_create_gc (xcb_connection_t *c,
                   xcb_gcontext_t cid,
                   xcb_drawable_t drawable,
                   uint32_t mask,
                   const xcb_params_gc_t *params);

xcb_void_cookie_t
xcb_aux_create_gc_checked (xcb_connection_t *c,
      xcb_gcontext_t gid,
      xcb_drawable_t drawable,
      uint32_t mask,
      const xcb_params_gc_t *params);
xcb_void_cookie_t
xcb_aux_change_gc (xcb_connection_t *c,
                   xcb_gcontext_t gc,
                   uint32_t mask,
                   const xcb_params_gc_t *params);

xcb_void_cookie_t
xcb_aux_change_gc_checked (xcb_connection_t *c,
      xcb_gcontext_t gc,
      uint32_t mask,
      const xcb_params_gc_t *params);
typedef struct {
    uint32_t key_click_percent;
    uint32_t bell_percent;
    uint32_t bell_pitch;
    uint32_t bell_duration;
    uint32_t led;
    uint32_t led_mode;
    uint32_t key;
    uint32_t auto_repeat_mode;
} xcb_params_keyboard_t;

xcb_void_cookie_t
xcb_aux_change_keyboard_control (xcb_connection_t *c,
                                 uint32_t mask,
                                 const xcb_params_keyboard_t *params);

int
xcb_aux_parse_color(const char *color_name,
      uint16_t *red, uint16_t *green, uint16_t *blue);

xcb_void_cookie_t
xcb_aux_set_line_attributes_checked (xcb_connection_t *dpy,
         xcb_gcontext_t gc,
         uint16_t linewidth,
         int32_t linestyle,
         int32_t capstyle,
         int32_t joinstyle);

xcb_void_cookie_t
xcb_aux_clear_window(xcb_connection_t * dpy,
       xcb_window_t w);
typedef struct _XCBKeySymbols xcb_key_symbols_t;

xcb_key_symbols_t *xcb_key_symbols_alloc (xcb_connection_t *c);

void xcb_key_symbols_free (xcb_key_symbols_t *syms);

xcb_keysym_t xcb_key_symbols_get_keysym (xcb_key_symbols_t *syms,
       xcb_keycode_t keycode,
       int col);
xcb_keycode_t * xcb_key_symbols_get_keycode(xcb_key_symbols_t *syms,
                                            xcb_keysym_t keysym);

xcb_keysym_t xcb_key_press_lookup_keysym (xcb_key_symbols_t *syms,
       xcb_key_press_event_t *event,
       int col);

xcb_keysym_t xcb_key_release_lookup_keysym (xcb_key_symbols_t *syms,
       xcb_key_release_event_t *event,
       int col);

int xcb_refresh_keyboard_mapping (xcb_key_symbols_t *syms,
       xcb_mapping_notify_event_t *event);





int xcb_is_keypad_key (xcb_keysym_t keysym);

int xcb_is_private_keypad_key (xcb_keysym_t keysym);

int xcb_is_cursor_key (xcb_keysym_t keysym);

int xcb_is_pf_key (xcb_keysym_t keysym);

int xcb_is_function_key (xcb_keysym_t keysym);

int xcb_is_misc_function_key (xcb_keysym_t keysym);

int xcb_is_modifier_key (xcb_keysym_t keysym);
const char * xcb_event_get_label(uint8_t type);







const char * xcb_event_get_error_label(uint8_t type);







const char * xcb_event_get_request_label(uint8_t type);
typedef struct xcb_cursor_context_t xcb_cursor_context_t;
int xcb_cursor_context_new(xcb_connection_t *conn, xcb_screen_t *screen, xcb_cursor_context_t **ctx);
xcb_cursor_t xcb_cursor_load_cursor(xcb_cursor_context_t *ctx, const char *name);







void xcb_cursor_context_free(xcb_cursor_context_t *ctx);
typedef int wchar_t;








union wait
  {
    int w_status;
    struct
      {

 unsigned int __w_termsig:7;
 unsigned int __w_coredump:1;
 unsigned int __w_retcode:8;
 unsigned int:16;







      } __wait_terminated;
    struct
      {

 unsigned int __w_stopval:8;
 unsigned int __w_stopsig:8;
 unsigned int:16;






      } __wait_stopped;
  };
typedef union
  {
    union wait *__uptr;
    int *__iptr;
  } __WAIT_STATUS __attribute__ ((__transparent_union__));


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;







__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;


extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) ;




extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) ;


extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));


extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));






extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));

extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));




extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));







extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;

  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));









extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;










extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));

extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));




extern void cfree (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));










extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));











extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;




extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (2))) ;




extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));





extern void quick_exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));







extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));






extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;

extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;





extern int system (const char *__command) ;

extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) ;






typedef int (*__compar_fn_t) (const void *, const void *);



extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;







extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;



__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;







extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;




__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;

extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));






extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));

extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__));








extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



typedef struct {

  xcb_connection_t *connection;

  xcb_screen_t **screens;
  int nb_screens;

  xcb_atom_t *_NET_WM_CM_Sn;

  xcb_atom_t _NET_SUPPORTED;
  xcb_atom_t _NET_CLIENT_LIST;
  xcb_atom_t _NET_CLIENT_LIST_STACKING;
  xcb_atom_t _NET_NUMBER_OF_DESKTOPS;
  xcb_atom_t _NET_DESKTOP_GEOMETRY;
  xcb_atom_t _NET_DESKTOP_VIEWPORT;
  xcb_atom_t _NET_CURRENT_DESKTOP;
  xcb_atom_t _NET_DESKTOP_NAMES;
  xcb_atom_t _NET_ACTIVE_WINDOW;
  xcb_atom_t _NET_WORKAREA;
  xcb_atom_t _NET_SUPPORTING_WM_CHECK;
  xcb_atom_t _NET_VIRTUAL_ROOTS;
  xcb_atom_t _NET_DESKTOP_LAYOUT;
  xcb_atom_t _NET_SHOWING_DESKTOP;
  xcb_atom_t _NET_CLOSE_WINDOW;
  xcb_atom_t _NET_MOVERESIZE_WINDOW;
  xcb_atom_t _NET_WM_MOVERESIZE;
  xcb_atom_t _NET_RESTACK_WINDOW;
  xcb_atom_t _NET_REQUEST_FRAME_EXTENTS;
  xcb_atom_t _NET_WM_NAME;
  xcb_atom_t _NET_WM_VISIBLE_NAME;
  xcb_atom_t _NET_WM_ICON_NAME;
  xcb_atom_t _NET_WM_VISIBLE_ICON_NAME;
  xcb_atom_t _NET_WM_DESKTOP;
  xcb_atom_t _NET_WM_WINDOW_TYPE;
  xcb_atom_t _NET_WM_STATE;
  xcb_atom_t _NET_WM_ALLOWED_ACTIONS;
  xcb_atom_t _NET_WM_STRUT;
  xcb_atom_t _NET_WM_STRUT_PARTIAL;
  xcb_atom_t _NET_WM_ICON_GEOMETRY;
  xcb_atom_t _NET_WM_ICON;
  xcb_atom_t _NET_WM_PID;
  xcb_atom_t _NET_WM_HANDLED_ICONS;
  xcb_atom_t _NET_WM_USER_TIME;
  xcb_atom_t _NET_WM_USER_TIME_WINDOW;
  xcb_atom_t _NET_FRAME_EXTENTS;
  xcb_atom_t _NET_WM_PING;
  xcb_atom_t _NET_WM_SYNC_REQUEST;
  xcb_atom_t _NET_WM_SYNC_REQUEST_COUNTER;
  xcb_atom_t _NET_WM_FULLSCREEN_MONITORS;
  xcb_atom_t _NET_WM_FULL_PLACEMENT;
  xcb_atom_t UTF8_STRING;
  xcb_atom_t WM_PROTOCOLS;
  xcb_atom_t MANAGER;
  xcb_atom_t _NET_WM_WINDOW_TYPE_DESKTOP;
  xcb_atom_t _NET_WM_WINDOW_TYPE_DOCK;
  xcb_atom_t _NET_WM_WINDOW_TYPE_TOOLBAR;
  xcb_atom_t _NET_WM_WINDOW_TYPE_MENU;
  xcb_atom_t _NET_WM_WINDOW_TYPE_UTILITY;
  xcb_atom_t _NET_WM_WINDOW_TYPE_SPLASH;
  xcb_atom_t _NET_WM_WINDOW_TYPE_DIALOG;
  xcb_atom_t _NET_WM_WINDOW_TYPE_DROPDOWN_MENU;
  xcb_atom_t _NET_WM_WINDOW_TYPE_POPUP_MENU;
  xcb_atom_t _NET_WM_WINDOW_TYPE_TOOLTIP;
  xcb_atom_t _NET_WM_WINDOW_TYPE_NOTIFICATION;
  xcb_atom_t _NET_WM_WINDOW_TYPE_COMBO;
  xcb_atom_t _NET_WM_WINDOW_TYPE_DND;
  xcb_atom_t _NET_WM_WINDOW_TYPE_NORMAL;
  xcb_atom_t _NET_WM_STATE_MODAL;
  xcb_atom_t _NET_WM_STATE_STICKY;
  xcb_atom_t _NET_WM_STATE_MAXIMIZED_VERT;
  xcb_atom_t _NET_WM_STATE_MAXIMIZED_HORZ;
  xcb_atom_t _NET_WM_STATE_SHADED;
  xcb_atom_t _NET_WM_STATE_SKIP_TASKBAR;
  xcb_atom_t _NET_WM_STATE_SKIP_PAGER;
  xcb_atom_t _NET_WM_STATE_HIDDEN;
  xcb_atom_t _NET_WM_STATE_FULLSCREEN;
  xcb_atom_t _NET_WM_STATE_ABOVE;
  xcb_atom_t _NET_WM_STATE_BELOW;
  xcb_atom_t _NET_WM_STATE_DEMANDS_ATTENTION;
  xcb_atom_t _NET_WM_ACTION_MOVE;
  xcb_atom_t _NET_WM_ACTION_RESIZE;
  xcb_atom_t _NET_WM_ACTION_MINIMIZE;
  xcb_atom_t _NET_WM_ACTION_SHADE;
  xcb_atom_t _NET_WM_ACTION_STICK;
  xcb_atom_t _NET_WM_ACTION_MAXIMIZE_HORZ;
  xcb_atom_t _NET_WM_ACTION_MAXIMIZE_VERT;
  xcb_atom_t _NET_WM_ACTION_FULLSCREEN;
  xcb_atom_t _NET_WM_ACTION_CHANGE_DESKTOP;
  xcb_atom_t _NET_WM_ACTION_CLOSE;
  xcb_atom_t _NET_WM_ACTION_ABOVE;
  xcb_atom_t _NET_WM_ACTION_BELOW;
} xcb_ewmh_connection_t;




typedef struct {

  uint32_t atoms_len;

  xcb_atom_t *atoms;

  xcb_get_property_reply_t *_reply;
} xcb_ewmh_get_atoms_reply_t;




typedef struct {

  uint32_t windows_len;

  xcb_window_t *windows;

  xcb_get_property_reply_t *_reply;
} xcb_ewmh_get_windows_reply_t;




typedef struct {

  uint32_t strings_len;

  char *strings;

  xcb_get_property_reply_t *_reply;
} xcb_ewmh_get_utf8_strings_reply_t;




typedef struct {

  uint32_t x;

  uint32_t y;
} xcb_ewmh_coordinates_t;




typedef struct {

  uint32_t desktop_viewport_len;

  xcb_ewmh_coordinates_t *desktop_viewport;

  xcb_get_property_reply_t *_reply;
} xcb_ewmh_get_desktop_viewport_reply_t;




typedef struct {

  uint32_t x;

  uint32_t y;

  uint32_t width;

  uint32_t height;
} xcb_ewmh_geometry_t;




typedef struct {

  uint32_t workarea_len;

  xcb_ewmh_geometry_t *workarea;

  xcb_get_property_reply_t *_reply;
} xcb_ewmh_get_workarea_reply_t;




typedef enum {


  XCB_EWMH_CLIENT_SOURCE_TYPE_NONE = 0,

  XCB_EWMH_CLIENT_SOURCE_TYPE_NORMAL = 1,

  XCB_EWMH_CLIENT_SOURCE_TYPE_OTHER = 2
} xcb_ewmh_client_source_type_t;




typedef enum {

  XCB_EWMH_WM_ORIENTATION_HORZ = 0,

  XCB_EWMH_WM_ORIENTATION_VERT = 1
} xcb_ewmh_desktop_layout_orientation_t;




typedef enum {

  XCB_EWMH_WM_TOPLEFT = 0,

  XCB_EWMH_WM_TOPRIGHT = 1,

  XCB_EWMH_WM_BOTTOMRIGHT = 2,

  XCB_EWMH_WM_BOTTOMLEFT = 3
} xcb_ewmh_desktop_layout_starting_corner_t;






typedef struct {

  uint32_t orientation;

  uint32_t columns;

  uint32_t rows;

  uint32_t starting_corner;
} xcb_ewmh_get_desktop_layout_reply_t;





typedef enum {

  XCB_EWMH_MOVERESIZE_WINDOW_X = (1 << 8),

  XCB_EWMH_MOVERESIZE_WINDOW_Y = (1 << 9),

  XCB_EWMH_MOVERESIZE_WINDOW_WIDTH = (1 << 10),

  XCB_EWMH_MOVERESIZE_WINDOW_HEIGHT = (1 << 11)
} xcb_ewmh_moveresize_window_opt_flags_t;




typedef enum {

  XCB_EWMH_WM_MOVERESIZE_SIZE_TOPLEFT = 0,

  XCB_EWMH_WM_MOVERESIZE_SIZE_TOP = 1,

  XCB_EWMH_WM_MOVERESIZE_SIZE_TOPRIGHT = 2,

  XCB_EWMH_WM_MOVERESIZE_SIZE_RIGHT = 3,

  XCB_EWMH_WM_MOVERESIZE_SIZE_BOTTOMRIGHT = 4,

  XCB_EWMH_WM_MOVERESIZE_SIZE_BOTTOM = 5,

  XCB_EWMH_WM_MOVERESIZE_SIZE_BOTTOMLEFT = 6,

  XCB_EWMH_WM_MOVERESIZE_SIZE_LEFT = 7,

  XCB_EWMH_WM_MOVERESIZE_MOVE = 8,

  XCB_EWMH_WM_MOVERESIZE_SIZE_KEYBOARD = 9,

  XCB_EWMH_WM_MOVERESIZE_MOVE_KEYBOARD = 10,

  XCB_EWMH_WM_MOVERESIZE_CANCEL = 11
} xcb_ewmh_moveresize_direction_t;




typedef enum {

  XCB_EWMH_WM_STATE_REMOVE = 0,

  XCB_EWMH_WM_STATE_ADD = 1,

  XCB_EWMH_WM_STATE_TOGGLE = 2
} xcb_ewmh_wm_state_action_t;




typedef struct {

  uint32_t left;

  uint32_t right;

  uint32_t top;

  uint32_t bottom;

  uint32_t left_start_y;

  uint32_t left_end_y;

  uint32_t right_start_y;

  uint32_t right_end_y;

  uint32_t top_start_x;

  uint32_t top_end_x;

  uint32_t bottom_start_x;

  uint32_t bottom_end_x;
} xcb_ewmh_wm_strut_partial_t;




typedef struct {

  uint32_t width;

  uint32_t height;

  uint32_t *data;

  unsigned int rem;

  unsigned int index;
} xcb_ewmh_wm_icon_iterator_t;




typedef struct {

  unsigned int num_icons;

  xcb_get_property_reply_t *_reply;
} xcb_ewmh_get_wm_icon_reply_t;




typedef struct {

  uint32_t left;

  uint32_t right;

  uint32_t top;

  uint32_t bottom;
} xcb_ewmh_get_extents_reply_t;




typedef struct {


  uint32_t top;


  uint32_t bottom;


  uint32_t left;


  uint32_t right;
} xcb_ewmh_get_wm_fullscreen_monitors_reply_t;
xcb_intern_atom_cookie_t *xcb_ewmh_init_atoms(xcb_connection_t *c,
                                              xcb_ewmh_connection_t *ewmh);
uint8_t xcb_ewmh_init_atoms_replies(xcb_ewmh_connection_t *ewmh,
                                    xcb_intern_atom_cookie_t *ewmh_cookies,
                                    xcb_generic_error_t **e);

static inline void
xcb_ewmh_connection_wipe(xcb_ewmh_connection_t *ewmh)
{
  free(ewmh->screens);
  free(ewmh->_NET_WM_CM_Sn);
}
xcb_void_cookie_t xcb_ewmh_send_client_message(xcb_connection_t *c,
                                               xcb_window_t window,
                                               xcb_window_t dest,
                                               xcb_atom_t atom,
                                               uint32_t data_len,
                                               const uint32_t *data);

uint8_t xcb_ewmh_get_window_from_reply(xcb_window_t *window,
                                       xcb_get_property_reply_t *r);

uint8_t xcb_ewmh_get_window_reply(xcb_ewmh_connection_t *ewmh,
                                  xcb_get_property_cookie_t cookie,
                                  xcb_window_t *window,
                                  xcb_generic_error_t **e);

uint8_t xcb_ewmh_get_cardinal_from_reply(uint32_t *cardinal,
                                         xcb_get_property_reply_t *r);

uint8_t xcb_ewmh_get_cardinal_reply(xcb_ewmh_connection_t *ewmh,
                                    xcb_get_property_cookie_t cookie,
                                    uint32_t *cardinal,
                                    xcb_generic_error_t **e);
uint8_t xcb_ewmh_get_atoms_from_reply(xcb_ewmh_get_atoms_reply_t *atoms,
                                      xcb_get_property_reply_t *r);
uint8_t xcb_ewmh_get_atoms_reply(xcb_ewmh_connection_t *ewmh,
                                 xcb_get_property_cookie_t cookie,
                                 xcb_ewmh_get_atoms_reply_t *atoms,
                                 xcb_generic_error_t **e);
void xcb_ewmh_get_atoms_reply_wipe(xcb_ewmh_get_atoms_reply_t *data);
uint8_t xcb_ewmh_get_windows_from_reply(xcb_ewmh_get_windows_reply_t *atoms,
                                        xcb_get_property_reply_t *r);

uint8_t xcb_ewmh_get_utf8_strings_from_reply(xcb_ewmh_connection_t *ewmh,
                                             xcb_ewmh_get_utf8_strings_reply_t *data,
                                             xcb_get_property_reply_t *r);

uint8_t xcb_ewmh_get_utf8_strings_reply(xcb_ewmh_connection_t *ewmh,
                                        xcb_get_property_cookie_t cookie,
                                        xcb_ewmh_get_utf8_strings_reply_t *data,
                                        xcb_generic_error_t **e);
uint8_t xcb_ewmh_get_windows_reply(xcb_ewmh_connection_t *ewmh,
                                   xcb_get_property_cookie_t cookie,
                                   xcb_ewmh_get_windows_reply_t *atoms,
                                   xcb_generic_error_t **e);
void xcb_ewmh_get_windows_reply_wipe(xcb_ewmh_get_windows_reply_t *data);
void xcb_ewmh_get_utf8_strings_reply_wipe(xcb_ewmh_get_utf8_strings_reply_t *data);
xcb_void_cookie_t xcb_ewmh_set_supported(xcb_ewmh_connection_t *ewmh,
                                         int screen_nbr,
                                         uint32_t list_len,
                                         xcb_atom_t *list);




xcb_void_cookie_t xcb_ewmh_set_supported_checked(xcb_ewmh_connection_t *ewmh,
                                                 int screen_nbr,
                                                 uint32_t list_len,
                                                 xcb_atom_t *list);
xcb_get_property_cookie_t xcb_ewmh_get_supported_unchecked(xcb_ewmh_connection_t *ewmh,
                                                           int screen_nbr);




xcb_get_property_cookie_t xcb_ewmh_get_supported(xcb_ewmh_connection_t *ewmh,
                                                 int screen_nbr);







static inline uint8_t
xcb_ewmh_get_supported_from_reply(xcb_ewmh_get_atoms_reply_t *supported,
                                  xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_atoms_from_reply(supported, r);
}
static inline uint8_t
xcb_ewmh_get_supported_reply(xcb_ewmh_connection_t *ewmh,
                             xcb_get_property_cookie_t cookie,
                             xcb_ewmh_get_atoms_reply_t *supported,
                             xcb_generic_error_t **e)
{
  return xcb_ewmh_get_atoms_reply(ewmh, cookie, supported, e);
}
xcb_void_cookie_t xcb_ewmh_set_client_list(xcb_ewmh_connection_t *ewmh,
                                           int screen_nbr,
                                           uint32_t list_len,
                                           xcb_window_t *list);




xcb_void_cookie_t xcb_ewmh_set_client_list_checked(xcb_ewmh_connection_t *ewmh,
                                                   int screen_nbr,
                                                   uint32_t list_len,
                                                   xcb_window_t *list);
xcb_get_property_cookie_t xcb_ewmh_get_client_list_unchecked(xcb_ewmh_connection_t *ewmh,
                                                             int screen_nbr);
xcb_get_property_cookie_t xcb_ewmh_get_client_list(xcb_ewmh_connection_t *ewmh,
                                                   int screen_nbr);
static inline uint8_t
xcb_ewmh_get_client_list_from_reply(xcb_ewmh_get_windows_reply_t *clients,
                                    xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_windows_from_reply(clients, r);
}
static inline uint8_t
xcb_ewmh_get_client_list_reply(xcb_ewmh_connection_t *ewmh,
                               xcb_get_property_cookie_t cookie,
                               xcb_ewmh_get_windows_reply_t *clients,
                               xcb_generic_error_t **e)
{
  return xcb_ewmh_get_windows_reply(ewmh, cookie, clients, e);
}
xcb_void_cookie_t xcb_ewmh_set_client_list_stacking(xcb_ewmh_connection_t *ewmh,
                                                    int screen_nbr,
                                                    uint32_t list_len,
                                                    xcb_window_t *list);




xcb_void_cookie_t xcb_ewmh_set_client_list_stacking_checked(xcb_ewmh_connection_t *ewmh,
                                                            int screen_nbr,
                                                            uint32_t list_len,
                                                            xcb_window_t *list);
xcb_get_property_cookie_t xcb_ewmh_get_client_list_stacking_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                      int screen_nbr);




xcb_get_property_cookie_t xcb_ewmh_get_client_list_stacking(xcb_ewmh_connection_t *ewmh,
                                                            int screen_nbr);
static inline uint8_t
xcb_ewmh_get_client_list_stacking_from_reply(xcb_ewmh_get_windows_reply_t *clients,
                                             xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_windows_from_reply(clients, r);
}
static inline uint8_t
xcb_ewmh_get_client_list_stacking_reply(xcb_ewmh_connection_t *ewmh,
                                        xcb_get_property_cookie_t cookie,
                                        xcb_ewmh_get_windows_reply_t *clients,
                                        xcb_generic_error_t **e)
{
  return xcb_ewmh_get_windows_reply(ewmh, cookie, clients, e);
}
xcb_void_cookie_t xcb_ewmh_set_number_of_desktops(xcb_ewmh_connection_t *ewmh,
                                                  int screen_nbr,
                                                  uint32_t number_of_desktops);




xcb_void_cookie_t xcb_ewmh_set_number_of_desktops_checked(xcb_ewmh_connection_t *ewmh,
                                                          int screen_nbr,
                                                          uint32_t number_of_desktops);
xcb_get_property_cookie_t xcb_ewmh_get_number_of_desktops_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                    int screen_nbr);




xcb_get_property_cookie_t xcb_ewmh_get_number_of_desktops(xcb_ewmh_connection_t *ewmh,
                                                          int screen_nbr);
static inline uint8_t
xcb_ewmh_get_number_of_desktops_from_reply(uint32_t *number_of_desktops,
                                           xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_cardinal_from_reply(number_of_desktops, r);
}
static inline uint8_t
xcb_ewmh_get_number_of_desktops_reply(xcb_ewmh_connection_t *ewmh,
                                      xcb_get_property_cookie_t cookie,
                                      uint32_t *number_of_desktops,
                                      xcb_generic_error_t **e)
{
  return xcb_ewmh_get_cardinal_reply(ewmh, cookie, number_of_desktops, e);
}

static inline xcb_void_cookie_t
xcb_ewmh_request_change_number_of_desktops(xcb_ewmh_connection_t *ewmh,
                                           int screen_nbr,
                                           uint32_t new_number_of_desktops)
{
  return xcb_ewmh_send_client_message(ewmh->connection, 0,
                                      ewmh->screens[screen_nbr]->root,
                                      ewmh->_NET_NUMBER_OF_DESKTOPS,
                                      sizeof(new_number_of_desktops),
                                      &new_number_of_desktops);
}
xcb_void_cookie_t xcb_ewmh_set_desktop_geometry(xcb_ewmh_connection_t *ewmh,
                                                int screen_nbr,
                                                uint32_t new_width,
                                                uint32_t new_height);




xcb_void_cookie_t xcb_ewmh_set_desktop_geometry_checked(xcb_ewmh_connection_t *ewmh,
                                                        int screen_nbr,
                                                        uint32_t new_width,
                                                        uint32_t new_height);
xcb_get_property_cookie_t xcb_ewmh_get_desktop_geometry_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                  int screen_nbr);




xcb_get_property_cookie_t xcb_ewmh_get_desktop_geometry(xcb_ewmh_connection_t *ewmh,
                                                        int screen_nbr);
xcb_void_cookie_t xcb_ewmh_request_change_desktop_geometry(xcb_ewmh_connection_t *ewmh,
                                                           int screen_nbr,
                                                           uint32_t new_width,
                                                           uint32_t new_height);
uint8_t xcb_ewmh_get_desktop_geometry_from_reply(uint32_t *width,
                                                 uint32_t *height,
                                                 xcb_get_property_reply_t *r);
uint8_t xcb_ewmh_get_desktop_geometry_reply(xcb_ewmh_connection_t *ewmh,
                                            xcb_get_property_cookie_t cookie,
                                            uint32_t *width, uint32_t *height,
                                            xcb_generic_error_t **e);
xcb_void_cookie_t xcb_ewmh_set_desktop_viewport(xcb_ewmh_connection_t *ewmh,
                                                int screen_nbr,
                                                uint32_t list_len,
                                                xcb_ewmh_coordinates_t *list);




xcb_void_cookie_t xcb_ewmh_set_desktop_viewport_checked(xcb_ewmh_connection_t *ewmh,
                                                        int screen_nbr,
                                                        uint32_t list_len,
                                                        xcb_ewmh_coordinates_t *list);
xcb_get_property_cookie_t xcb_ewmh_get_desktop_viewport_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                  int screen_nbr);




xcb_get_property_cookie_t xcb_ewmh_get_desktop_viewport(xcb_ewmh_connection_t *ewmh,
                                                        int screen_nbr);
xcb_void_cookie_t xcb_ewmh_request_change_desktop_viewport(xcb_ewmh_connection_t *ewmh,
                                                           int screen_nbr,
                                                           uint32_t x, uint32_t y);
uint8_t xcb_ewmh_get_desktop_viewport_from_reply(xcb_ewmh_get_desktop_viewport_reply_t *vp,
                                                 xcb_get_property_reply_t *r);
uint8_t xcb_ewmh_get_desktop_viewport_reply(xcb_ewmh_connection_t *ewmh,
                                            xcb_get_property_cookie_t cookie,
                                            xcb_ewmh_get_desktop_viewport_reply_t *vp,
                                            xcb_generic_error_t **e);
void xcb_ewmh_get_desktop_viewport_reply_wipe(xcb_ewmh_get_desktop_viewport_reply_t *r);
xcb_void_cookie_t xcb_ewmh_set_current_desktop(xcb_ewmh_connection_t *ewmh,
                                               int screen_nbr,
                                               uint32_t new_current_desktop);




xcb_void_cookie_t xcb_ewmh_set_current_desktop_checked(xcb_ewmh_connection_t *ewmh,
                                                       int screen_nbr,
                                                       uint32_t new_current_desktop);
xcb_get_property_cookie_t xcb_ewmh_get_current_desktop_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                 int screen_nbr);




xcb_get_property_cookie_t xcb_ewmh_get_current_desktop(xcb_ewmh_connection_t *ewmh,
                                                       int screen_nbr);
xcb_void_cookie_t xcb_ewmh_request_change_current_desktop(xcb_ewmh_connection_t *ewmh,
                                                          int screen_nbr,
                                                          uint32_t new_desktop,
                                                          xcb_timestamp_t timestamp);
static inline uint8_t
xcb_ewmh_get_current_desktop_from_reply(uint32_t *current_desktop,
                                        xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_cardinal_from_reply(current_desktop, r);
}
static inline uint8_t
xcb_ewmh_get_current_desktop_reply(xcb_ewmh_connection_t *ewmh,
                                   xcb_get_property_cookie_t cookie,
                                   uint32_t *current_desktop,
                                   xcb_generic_error_t **e)
{
  return xcb_ewmh_get_cardinal_reply(ewmh, cookie, current_desktop, e);
}
xcb_void_cookie_t xcb_ewmh_set_desktop_names(xcb_ewmh_connection_t *ewmh,
                                             int screen_nbr,
                                             uint32_t strings_len,
                                             const char *strings);




xcb_void_cookie_t xcb_ewmh_set_desktop_names_checked(xcb_ewmh_connection_t *ewmh,
                                                     int screen_nbr,
                                                     uint32_t strings_len,
                                                     const char *strings);
xcb_get_property_cookie_t xcb_ewmh_get_desktop_names_unchecked(xcb_ewmh_connection_t *ewmh,
                                                               int screen_nbr);




xcb_get_property_cookie_t xcb_ewmh_get_desktop_names(xcb_ewmh_connection_t *ewmh,
                                                     int screen_nbr);
static inline uint8_t
xcb_ewmh_get_desktop_names_from_reply(xcb_ewmh_connection_t *ewmh,
                                      xcb_ewmh_get_utf8_strings_reply_t *names,
                                      xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_utf8_strings_from_reply(ewmh, names, r);
}
static inline uint8_t
xcb_ewmh_get_desktop_names_reply(xcb_ewmh_connection_t *ewmh,
                                 xcb_get_property_cookie_t cookie,
                                 xcb_ewmh_get_utf8_strings_reply_t *names,
                                 xcb_generic_error_t **e)
{
  return xcb_ewmh_get_utf8_strings_reply(ewmh, cookie, names, e);
}
xcb_void_cookie_t xcb_ewmh_set_active_window(xcb_ewmh_connection_t *ewmh,
                                             int screen_nbr,
                                             xcb_window_t new_active_window);




xcb_void_cookie_t xcb_ewmh_set_active_window_checked(xcb_ewmh_connection_t *ewmh,
                                                     int screen_nbr,
                                                     xcb_window_t new_active_window);
xcb_void_cookie_t xcb_ewmh_request_change_active_window(xcb_ewmh_connection_t *ewmh,
                                                        int screen_nbr,
                                                        xcb_window_t window_to_activate,
                                                        xcb_ewmh_client_source_type_t source_indication,
                                                        xcb_timestamp_t timestamp,
                                                        xcb_window_t current_active_window);
xcb_get_property_cookie_t xcb_ewmh_get_active_window_unchecked(xcb_ewmh_connection_t *ewmh,
                                                               int screen_nbr);
xcb_get_property_cookie_t xcb_ewmh_get_active_window(xcb_ewmh_connection_t *ewmh,
                                                     int screen_nbr);
static inline uint8_t
xcb_ewmh_get_active_window_from_reply(xcb_window_t *active_window,
                                      xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_window_from_reply(active_window, r);
}
static inline uint8_t
xcb_ewmh_get_active_window_reply(xcb_ewmh_connection_t *ewmh,
                                 xcb_get_property_cookie_t cookie,
                                 xcb_window_t *active_window,
                                 xcb_generic_error_t **e)
{
  return xcb_ewmh_get_window_reply(ewmh, cookie, active_window, e);
}
xcb_void_cookie_t xcb_ewmh_set_workarea(xcb_ewmh_connection_t *ewmh,
                                        int screen_nbr,
                                        uint32_t list_len,
                                        xcb_ewmh_geometry_t *list);




xcb_void_cookie_t xcb_ewmh_set_workarea_checked(xcb_ewmh_connection_t *ewmh,
                                                int screen_nbr,
                                                uint32_t list_len,
                                                xcb_ewmh_geometry_t *list);
xcb_get_property_cookie_t xcb_ewmh_get_workarea_unchecked(xcb_ewmh_connection_t *ewmh,
                                                          int screen_nbr);




xcb_get_property_cookie_t xcb_ewmh_get_workarea(xcb_ewmh_connection_t *ewmh,
                                                int screen_nbr);
uint8_t xcb_ewmh_get_workarea_from_reply(xcb_ewmh_get_workarea_reply_t *wa,
                                         xcb_get_property_reply_t *r);
uint8_t xcb_ewmh_get_workarea_reply(xcb_ewmh_connection_t *ewmh,
                                    xcb_get_property_cookie_t cookie,
                                    xcb_ewmh_get_workarea_reply_t *wa,
                                    xcb_generic_error_t **e);
void xcb_ewmh_get_workarea_reply_wipe(xcb_ewmh_get_workarea_reply_t *r);
xcb_void_cookie_t xcb_ewmh_set_supporting_wm_check(xcb_ewmh_connection_t *ewmh,
                                                   xcb_window_t parent_window,
                                                   xcb_window_t child_window);




xcb_void_cookie_t xcb_ewmh_set_supporting_wm_check_checked(xcb_ewmh_connection_t *ewmh,
                                                           xcb_window_t parent_window,
                                                           xcb_window_t child_window);
xcb_get_property_cookie_t xcb_ewmh_get_supporting_wm_check_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                     xcb_window_t window);




xcb_get_property_cookie_t xcb_ewmh_get_supporting_wm_check(xcb_ewmh_connection_t *ewmh,
                                                           xcb_window_t window);
static inline uint8_t
xcb_ewmh_get_supporting_wm_check_from_reply(xcb_window_t *window,
                                            xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_window_from_reply(window, r);
}
static inline uint8_t
xcb_ewmh_get_supporting_wm_check_reply(xcb_ewmh_connection_t *ewmh,
                                       xcb_get_property_cookie_t cookie,
                                       xcb_window_t *window,
                                       xcb_generic_error_t **e)
{
  return xcb_ewmh_get_window_reply(ewmh, cookie, window, e);
}
xcb_void_cookie_t xcb_ewmh_set_virtual_roots(xcb_ewmh_connection_t *ewmh,
                                             int screen_nbr,
                                             uint32_t list_len,
                                             xcb_window_t *list);




xcb_void_cookie_t xcb_ewmh_set_virtual_roots_checked(xcb_ewmh_connection_t *ewmh,
                                                     int screen_nbr,
                                                     uint32_t list_len,
                                                     xcb_window_t *list);
xcb_get_property_cookie_t xcb_ewmh_get_virtual_roots_unchecked(xcb_ewmh_connection_t *ewmh,
                                                               int screen_nbr);




xcb_get_property_cookie_t xcb_ewmh_get_virtual_roots(xcb_ewmh_connection_t *ewmh,
                                                     int screen_nbr);
static inline uint8_t
xcb_ewmh_get_virtual_roots_from_reply(xcb_ewmh_get_windows_reply_t *virtual_roots,
                                      xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_windows_from_reply(virtual_roots, r);
}
static inline uint8_t
xcb_ewmh_get_virtual_roots_reply(xcb_ewmh_connection_t *ewmh,
                                 xcb_get_property_cookie_t cookie,
                                 xcb_ewmh_get_windows_reply_t *virtual_roots,
                                 xcb_generic_error_t **e)
{
  return xcb_ewmh_get_windows_reply(ewmh, cookie, virtual_roots, e);
}

xcb_void_cookie_t xcb_ewmh_set_desktop_layout(xcb_ewmh_connection_t *ewmh,
                                              int screen_nbr,
                                              xcb_ewmh_desktop_layout_orientation_t orientation,
                                              uint32_t columns, uint32_t rows,
                                              xcb_ewmh_desktop_layout_starting_corner_t starting_corner);

xcb_void_cookie_t xcb_ewmh_set_desktop_layout_checked(xcb_ewmh_connection_t *ewmh,
                                                      int screen_nbr,
                                                      xcb_ewmh_desktop_layout_orientation_t orientation,
                                                      uint32_t columns, uint32_t rows,
                                                      xcb_ewmh_desktop_layout_starting_corner_t starting_corner);
xcb_get_property_cookie_t xcb_ewmh_get_desktop_layout_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                int screen_nbr);




xcb_get_property_cookie_t xcb_ewmh_get_desktop_layout(xcb_ewmh_connection_t *ewmh,
                                                      int screen_nbr);

uint8_t xcb_ewmh_get_desktop_layout_from_reply(xcb_ewmh_get_desktop_layout_reply_t *desktop_layouts,
                                               xcb_get_property_reply_t *r);

uint8_t xcb_ewmh_get_desktop_layout_reply(xcb_ewmh_connection_t *ewmh,
                                          xcb_get_property_cookie_t cookie,
                                          xcb_ewmh_get_desktop_layout_reply_t *desktop_layouts,
                                          xcb_generic_error_t **e);

xcb_void_cookie_t xcb_ewmh_set_showing_desktop(xcb_ewmh_connection_t *ewmh,
                                               int screen_nbr,
                                               uint32_t desktop);

xcb_void_cookie_t xcb_ewmh_set_showing_desktop_checked(xcb_ewmh_connection_t *ewmh,
                                                       int screen_nbr,
                                                       uint32_t desktop);

xcb_get_property_cookie_t xcb_ewmh_get_showing_desktop_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                 int screen_nbr);

xcb_get_property_cookie_t xcb_ewmh_get_showing_desktop(xcb_ewmh_connection_t *ewmh,
                                                       int screen_nbr);

static inline uint8_t
xcb_ewmh_get_showing_desktop_from_reply(uint32_t *desktop,
                                        xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_cardinal_from_reply(desktop, r);
}

static inline uint8_t
xcb_ewmh_get_showing_desktop_reply(xcb_ewmh_connection_t *ewmh,
                                   xcb_get_property_cookie_t cookie,
                                   uint32_t *desktop,
                                   xcb_generic_error_t **e)
{
  return xcb_ewmh_get_cardinal_reply(ewmh, cookie, desktop, e);
}

static inline xcb_void_cookie_t
xcb_ewmh_request_change_showing_desktop(xcb_ewmh_connection_t *ewmh,
                                        int screen_nbr,
                                        uint32_t enter)
{
  return xcb_ewmh_send_client_message(ewmh->connection, 0,
                                      ewmh->screens[screen_nbr]->root,
                                      ewmh->_NET_SHOWING_DESKTOP,
                                      sizeof(enter), &enter);
}

xcb_void_cookie_t xcb_ewmh_request_close_window(xcb_ewmh_connection_t *ewmh,
                                                int screen_nbr,
                                                xcb_window_t window_to_close,
                                                xcb_timestamp_t timestamp,
                                                xcb_ewmh_client_source_type_t source_indication);

xcb_void_cookie_t xcb_ewmh_request_moveresize_window(xcb_ewmh_connection_t *ewmh,
                                                     int screen_nbr,
                                                     xcb_window_t moveresize_window,
                                                     xcb_gravity_t gravity,
                                                     xcb_ewmh_client_source_type_t source_indication,
                                                     xcb_ewmh_moveresize_window_opt_flags_t flags,
                                                     uint32_t x, uint32_t y,
                                                     uint32_t width, uint32_t height);

xcb_void_cookie_t xcb_ewmh_request_wm_moveresize(xcb_ewmh_connection_t *ewmh,
                                                 int screen_nbr,
                                                 xcb_window_t moveresize_window,
                                                 uint32_t x_root, uint32_t y_root,
                                                 xcb_ewmh_moveresize_direction_t direction,
                                                 xcb_button_index_t button,
                                                 xcb_ewmh_client_source_type_t source_indication);

xcb_void_cookie_t xcb_ewmh_request_restack_window(xcb_ewmh_connection_t *ewmh,
                                                  int screen_nbr,
                                                  xcb_window_t window_to_restack,
                                                  xcb_window_t sibling_window,
                                                  xcb_stack_mode_t detail);

static inline xcb_void_cookie_t
xcb_ewmh_request_frame_extents(xcb_ewmh_connection_t *ewmh,
                               int screen_nbr,
                               xcb_window_t client_window)
{
  return xcb_ewmh_send_client_message(ewmh->connection, client_window,
                                      ewmh->screens[screen_nbr]->root,
                                      ewmh->_NET_REQUEST_FRAME_EXTENTS, 0, ((void *)0));
}

xcb_void_cookie_t xcb_ewmh_set_wm_name(xcb_ewmh_connection_t *ewmh,
                                       xcb_window_t window,
                                       uint32_t strings_len,
                                       const char *strings);

xcb_void_cookie_t xcb_ewmh_set_wm_name_checked(xcb_ewmh_connection_t *ewmh,
                                               xcb_window_t window,
                                               uint32_t strings_len,
                                               const char *strings);

xcb_get_property_cookie_t xcb_ewmh_get_wm_name_unchecked(xcb_ewmh_connection_t *ewmh,
                                                         xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_name(xcb_ewmh_connection_t *ewmh,
                                               xcb_window_t window);

static inline uint8_t
xcb_ewmh_get_wm_name_from_reply(xcb_ewmh_connection_t *ewmh,
                                xcb_ewmh_get_utf8_strings_reply_t *data,
                                xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_utf8_strings_from_reply(ewmh, data, r);
}

static inline uint8_t
xcb_ewmh_get_wm_name_reply(xcb_ewmh_connection_t *ewmh,
                           xcb_get_property_cookie_t cookie,
                           xcb_ewmh_get_utf8_strings_reply_t *data,
                           xcb_generic_error_t **e)
{
  return xcb_ewmh_get_utf8_strings_reply(ewmh, cookie, data, e);
}

xcb_void_cookie_t xcb_ewmh_set_wm_visible_name(xcb_ewmh_connection_t *ewmh,
                                               xcb_window_t window,
                                               uint32_t strings_len,
                                               const char *strings);

xcb_void_cookie_t xcb_ewmh_set_wm_visible_name_checked(xcb_ewmh_connection_t *ewmh,
                                                       xcb_window_t window,
                                                       uint32_t strings_len,
                                                       const char *strings);

xcb_get_property_cookie_t xcb_ewmh_get_wm_visible_name_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                 xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_visible_name(xcb_ewmh_connection_t *ewmh,
                                                       xcb_window_t window);

static inline uint8_t
xcb_ewmh_get_wm_visible_name_from_reply(xcb_ewmh_connection_t *ewmh,
                                        xcb_ewmh_get_utf8_strings_reply_t *data,
                                        xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_utf8_strings_from_reply(ewmh, data, r);
}

static inline uint8_t
xcb_ewmh_get_wm_visible_name_reply(xcb_ewmh_connection_t *ewmh,
                                   xcb_get_property_cookie_t cookie,
                                   xcb_ewmh_get_utf8_strings_reply_t *data,
                                   xcb_generic_error_t **e)
{
  return xcb_ewmh_get_utf8_strings_reply(ewmh, cookie, data, e);
}

xcb_void_cookie_t xcb_ewmh_set_wm_icon_name(xcb_ewmh_connection_t *ewmh,
                                            xcb_window_t window,
                                            uint32_t strings_len,
                                            const char *strings);

xcb_void_cookie_t xcb_ewmh_set_wm_icon_name_checked(xcb_ewmh_connection_t *ewmh,
                                                    xcb_window_t window,
                                                    uint32_t strings_len,
                                                    const char *strings);

xcb_get_property_cookie_t xcb_ewmh_get_wm_icon_name_unchecked(xcb_ewmh_connection_t *ewmh,
                                                              xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_icon_name(xcb_ewmh_connection_t *ewmh,
                                                    xcb_window_t window);

static inline uint8_t
xcb_ewmh_get_wm_icon_name_from_reply(xcb_ewmh_connection_t *ewmh,
                                     xcb_ewmh_get_utf8_strings_reply_t *data,
                                     xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_utf8_strings_from_reply(ewmh, data, r);
}

static inline uint8_t
xcb_ewmh_get_wm_icon_name_reply(xcb_ewmh_connection_t *ewmh,
                                xcb_get_property_cookie_t cookie,
                                xcb_ewmh_get_utf8_strings_reply_t *data,
                                xcb_generic_error_t **e)
{
  return xcb_ewmh_get_utf8_strings_reply(ewmh, cookie, data, e);
}

xcb_void_cookie_t xcb_ewmh_set_wm_visible_icon_name(xcb_ewmh_connection_t *ewmh,
                                                    xcb_window_t window,
                                                    uint32_t strings_len,
                                                    const char *strings);

xcb_void_cookie_t xcb_ewmh_set_wm_visible_icon_name_checked(xcb_ewmh_connection_t *ewmh,
                                                            xcb_window_t window,
                                                            uint32_t strings_len,
                                                            const char *strings);

xcb_get_property_cookie_t xcb_ewmh_get_wm_visible_icon_name_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                      xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_visible_icon_name(xcb_ewmh_connection_t *ewmh,
                                                            xcb_window_t window);

static inline uint8_t
xcb_ewmh_get_wm_visible_icon_name_from_reply(xcb_ewmh_connection_t *ewmh,
                                             xcb_ewmh_get_utf8_strings_reply_t *data,
                                             xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_utf8_strings_from_reply(ewmh, data, r);
}

static inline uint8_t
xcb_ewmh_get_wm_visible_icon_name_reply(xcb_ewmh_connection_t *ewmh,
                                        xcb_get_property_cookie_t cookie,
                                        xcb_ewmh_get_utf8_strings_reply_t *data,
                                        xcb_generic_error_t **e)
{
  return xcb_ewmh_get_utf8_strings_reply(ewmh, cookie, data, e);
}

xcb_void_cookie_t xcb_ewmh_set_wm_desktop(xcb_ewmh_connection_t *ewmh,
                                          xcb_window_t window,
                                          uint32_t desktop);

xcb_void_cookie_t xcb_ewmh_set_wm_desktop_checked(xcb_ewmh_connection_t *ewmh,
                                                  xcb_window_t window,
                                                  uint32_t desktop);


xcb_get_property_cookie_t xcb_ewmh_get_wm_desktop_unchecked(xcb_ewmh_connection_t *ewmh,
                                                            xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_desktop(xcb_ewmh_connection_t *ewmh,
                                                  xcb_window_t window);

static inline uint8_t
xcb_ewmh_get_wm_desktop_from_reply(uint32_t *desktop,
                                   xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_cardinal_from_reply(desktop, r);
}

static inline uint8_t
xcb_ewmh_get_wm_desktop_reply(xcb_ewmh_connection_t *ewmh,
                              xcb_get_property_cookie_t cookie,
                              uint32_t *desktop,
                              xcb_generic_error_t **e)
{
  return xcb_ewmh_get_cardinal_reply(ewmh, cookie, desktop, e);
}

xcb_void_cookie_t xcb_ewmh_request_change_wm_desktop(xcb_ewmh_connection_t *ewmh,
                                                     int screen_nbr,
                                                     xcb_window_t client_window,
                                                     uint32_t new_desktop,
                                                     xcb_ewmh_client_source_type_t source_indication);

xcb_void_cookie_t xcb_ewmh_set_wm_window_type(xcb_ewmh_connection_t *ewmh,
                                              xcb_window_t window,
                                              uint32_t list_len,
                                              xcb_atom_t *list);

xcb_void_cookie_t xcb_ewmh_set_wm_window_type_checked(xcb_ewmh_connection_t *ewmh,
                                                      xcb_window_t window,
                                                      uint32_t list_len,
                                                      xcb_atom_t *list);

xcb_get_property_cookie_t xcb_ewmh_get_wm_window_type_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_window_type(xcb_ewmh_connection_t *ewmh,
                                                      xcb_window_t window);

uint8_t xcb_ewmh_get_wm_window_type_from_reply(xcb_ewmh_get_atoms_reply_t *wtypes,
                                               xcb_get_property_reply_t *r);

uint8_t xcb_ewmh_get_wm_window_type_reply(xcb_ewmh_connection_t *ewmh,
                                          xcb_get_property_cookie_t cookie,
                                          xcb_ewmh_get_atoms_reply_t *name,
                                          xcb_generic_error_t **e);

xcb_void_cookie_t xcb_ewmh_set_wm_state(xcb_ewmh_connection_t *ewmh,
                                        xcb_window_t window,
                                        uint32_t list_len,
                                        xcb_atom_t *list);

xcb_void_cookie_t xcb_ewmh_set_wm_state_checked(xcb_ewmh_connection_t *ewmh,
                                                xcb_window_t window,
                                                uint32_t list_len,
                                                xcb_atom_t *list);

xcb_get_property_cookie_t xcb_ewmh_get_wm_state_unchecked(xcb_ewmh_connection_t *ewmh,
                                                          xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_state(xcb_ewmh_connection_t *ewmh,
                                                xcb_window_t window);

uint8_t xcb_ewmh_get_wm_state_from_reply(xcb_ewmh_get_atoms_reply_t *wtypes,
                                         xcb_get_property_reply_t *r);

uint8_t xcb_ewmh_get_wm_state_reply(xcb_ewmh_connection_t *ewmh,
                                    xcb_get_property_cookie_t cookie,
                                    xcb_ewmh_get_atoms_reply_t *name,
                                    xcb_generic_error_t **e);

xcb_void_cookie_t xcb_ewmh_request_change_wm_state(xcb_ewmh_connection_t *ewmh,
                                                   int screen_nbr,
                                                   xcb_window_t client_window,
                                                   xcb_ewmh_wm_state_action_t action,
                                                   xcb_atom_t first_property,
                                                   xcb_atom_t second_property,
                                                   xcb_ewmh_client_source_type_t source_indication);

xcb_void_cookie_t xcb_ewmh_set_wm_allowed_actions(xcb_ewmh_connection_t *ewmh,
                                                  xcb_window_t window,
                                                  uint32_t list_len,
                                                  xcb_atom_t *list);

xcb_void_cookie_t xcb_ewmh_set_wm_allowed_actions_checked(xcb_ewmh_connection_t *ewmh,
                                                          xcb_window_t window,
                                                          uint32_t list_len,
                                                          xcb_atom_t *list);

xcb_get_property_cookie_t xcb_ewmh_get_wm_allowed_actions_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                    xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_allowed_actions(xcb_ewmh_connection_t *ewmh,
                                                          xcb_window_t window);

uint8_t xcb_ewmh_get_wm_allowed_actions_from_reply(xcb_ewmh_get_atoms_reply_t *wtypes,
                                                   xcb_get_property_reply_t *r);

uint8_t xcb_ewmh_get_wm_allowed_actions_reply(xcb_ewmh_connection_t *ewmh,
                                              xcb_get_property_cookie_t cookie,
                                              xcb_ewmh_get_atoms_reply_t *name,
                                              xcb_generic_error_t **e);

xcb_void_cookie_t xcb_ewmh_set_wm_strut(xcb_ewmh_connection_t *ewmh,
                                        xcb_window_t window,
                                        uint32_t left, uint32_t right,
                                        uint32_t top, uint32_t bottom);

xcb_void_cookie_t xcb_ewmh_set_wm_strut_checked(xcb_ewmh_connection_t *ewmh,
                                                xcb_window_t window,
                                                uint32_t left, uint32_t right,
                                                uint32_t top, uint32_t bottom);

xcb_get_property_cookie_t xcb_ewmh_get_wm_strut_unchecked(xcb_ewmh_connection_t *ewmh,
                                                          xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_strut(xcb_ewmh_connection_t *ewmh,
                                                xcb_window_t window);

uint8_t xcb_ewmh_get_wm_strut_from_reply(xcb_ewmh_get_extents_reply_t *struts,
                                         xcb_get_property_reply_t *r);

uint8_t xcb_ewmh_get_wm_strut_reply(xcb_ewmh_connection_t *ewmh,
                                    xcb_get_property_cookie_t cookie,
                                    xcb_ewmh_get_extents_reply_t *struts,
                                    xcb_generic_error_t **e);

xcb_void_cookie_t xcb_ewmh_set_wm_strut_partial(xcb_ewmh_connection_t *ewmh,
                                                xcb_window_t window,
                                                xcb_ewmh_wm_strut_partial_t wm_strut);

xcb_void_cookie_t xcb_ewmh_set_wm_strut_partial_checked(xcb_ewmh_connection_t *ewmh,
                                                        xcb_window_t window,
                                                        xcb_ewmh_wm_strut_partial_t wm_strut);

xcb_get_property_cookie_t xcb_ewmh_get_wm_strut_partial_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                  xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_strut_partial(xcb_ewmh_connection_t *ewmh,
                                                        xcb_window_t window);

uint8_t xcb_ewmh_get_wm_strut_partial_from_reply(xcb_ewmh_wm_strut_partial_t *struts,
                                                 xcb_get_property_reply_t *r);

uint8_t xcb_ewmh_get_wm_strut_partial_reply(xcb_ewmh_connection_t *ewmh,
                                            xcb_get_property_cookie_t cookie,
                                            xcb_ewmh_wm_strut_partial_t *struts,
                                            xcb_generic_error_t **e);

xcb_void_cookie_t xcb_ewmh_set_wm_icon_geometry(xcb_ewmh_connection_t *ewmh,
                                                xcb_window_t window,
                                                uint32_t left, uint32_t right,
                                                uint32_t top, uint32_t bottom);

xcb_void_cookie_t xcb_ewmh_set_wm_icon_geometry_checked(xcb_ewmh_connection_t *ewmh,
                                                        xcb_window_t window,
                                                        uint32_t left, uint32_t right,
                                                        uint32_t top, uint32_t bottom);

xcb_get_property_cookie_t xcb_ewmh_get_wm_icon_geometry_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                  xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_icon_geometry(xcb_ewmh_connection_t *ewmh,
                                                        xcb_window_t window);

uint8_t xcb_ewmh_get_wm_icon_geometry_from_reply(xcb_ewmh_geometry_t *icons,
                                                 xcb_get_property_reply_t *r);

uint8_t xcb_ewmh_get_wm_icon_geometry_reply(xcb_ewmh_connection_t *ewmh,
                                            xcb_get_property_cookie_t cookie,
                                            xcb_ewmh_geometry_t *icons,
                                            xcb_generic_error_t **e);
static inline xcb_void_cookie_t
xcb_ewmh_set_wm_icon_checked(xcb_ewmh_connection_t *ewmh,
                             uint8_t mode,
                             xcb_window_t window,
                             uint32_t data_len, uint32_t *data)
{
  return xcb_change_property_checked(ewmh->connection, mode,
                                     window, ewmh->_NET_WM_ICON,
                                     XCB_ATOM_CARDINAL, 32, data_len, data);
}




static inline xcb_void_cookie_t
xcb_ewmh_set_wm_icon(xcb_ewmh_connection_t *ewmh,
                     uint8_t mode,
                     xcb_window_t window,
                     uint32_t data_len, uint32_t *data)
{
  return xcb_change_property(ewmh->connection, mode, window,
                             ewmh->_NET_WM_ICON, XCB_ATOM_CARDINAL, 32,
                             data_len, data);
}

xcb_void_cookie_t xcb_ewmh_append_wm_icon_checked(xcb_ewmh_connection_t *ewmh,
                                                  xcb_window_t window,
                                                  uint32_t width, uint32_t height,
                                                  uint32_t img_len, uint32_t *img);

xcb_void_cookie_t xcb_ewmh_append_wm_icon(xcb_ewmh_connection_t *ewmh,
                                          xcb_window_t window,
                                          uint32_t width, uint32_t height,
                                          uint32_t img_len, uint32_t *img);

xcb_get_property_cookie_t xcb_ewmh_get_wm_icon_unchecked(xcb_ewmh_connection_t *ewmh,
                                                         xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_icon(xcb_ewmh_connection_t *ewmh,
                                               xcb_window_t window);

uint8_t xcb_ewmh_get_wm_icon_from_reply(xcb_ewmh_get_wm_icon_reply_t *wm_icon,
                                        xcb_get_property_reply_t *r);

uint8_t xcb_ewmh_get_wm_icon_reply(xcb_ewmh_connection_t *ewmh,
                                   xcb_get_property_cookie_t cookie,
                                   xcb_ewmh_get_wm_icon_reply_t *wm_icon,
                                   xcb_generic_error_t **e);

xcb_ewmh_wm_icon_iterator_t xcb_ewmh_get_wm_icon_iterator(const xcb_ewmh_get_wm_icon_reply_t *wm_icon);

unsigned int xcb_ewmh_get_wm_icon_length(const xcb_ewmh_get_wm_icon_reply_t *wm_icon);

void xcb_ewmh_get_wm_icon_next(xcb_ewmh_wm_icon_iterator_t *iterator);

void xcb_ewmh_get_wm_icon_reply_wipe(xcb_ewmh_get_wm_icon_reply_t *wm_icon);

xcb_void_cookie_t xcb_ewmh_set_wm_pid(xcb_ewmh_connection_t *ewmh,
                                      xcb_window_t window,
                                      uint32_t pid);

xcb_void_cookie_t xcb_ewmh_set_wm_pid_checked(xcb_ewmh_connection_t *ewmh,
                                              xcb_window_t window,
                                              uint32_t pid);

xcb_get_property_cookie_t xcb_ewmh_get_wm_pid_unchecked(xcb_ewmh_connection_t *ewmh,
                                                        xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_pid(xcb_ewmh_connection_t *ewmh,
                                              xcb_window_t window);

static inline uint8_t
xcb_ewmh_get_wm_pid_from_reply(uint32_t *pid,
                               xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_cardinal_from_reply(pid, r);
}

static inline uint8_t
xcb_ewmh_get_wm_pid_reply(xcb_ewmh_connection_t *ewmh,
                          xcb_get_property_cookie_t cookie,
                          uint32_t *pid,
                          xcb_generic_error_t **e)
{
  return xcb_ewmh_get_cardinal_reply(ewmh, cookie, pid, e);
}

xcb_void_cookie_t xcb_ewmh_set_wm_handled_icons(xcb_ewmh_connection_t *ewmh,
                                                xcb_window_t window,
                                                uint32_t handled_icons);

xcb_void_cookie_t xcb_ewmh_set_wm_handled_icons_checked(xcb_ewmh_connection_t *ewmh,
                                                        xcb_window_t window,
                                                        uint32_t handled_icons);

xcb_get_property_cookie_t xcb_ewmh_get_wm_handled_icons_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                  xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_handled_icons(xcb_ewmh_connection_t *ewmh,
                                                        xcb_window_t window);

static inline uint8_t
xcb_ewmh_get_wm_handled_icons_from_reply(uint32_t *handled_icons,
                                         xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_cardinal_from_reply(handled_icons, r);
}

static inline uint8_t
xcb_ewmh_get_wm_handled_icons_reply(xcb_ewmh_connection_t *ewmh,
                                    xcb_get_property_cookie_t cookie,
                                    uint32_t *handled_icons,
                                    xcb_generic_error_t **e)
{
  return xcb_ewmh_get_cardinal_reply(ewmh, cookie, handled_icons, e);
}

xcb_void_cookie_t xcb_ewmh_set_wm_user_time(xcb_ewmh_connection_t *ewmh,
                                            xcb_window_t window,
                                            uint32_t xtime);

xcb_void_cookie_t xcb_ewmh_set_wm_user_time_checked(xcb_ewmh_connection_t *ewmh,
                                                    xcb_window_t window,
                                                    uint32_t pid);

xcb_get_property_cookie_t xcb_ewmh_get_wm_user_time_unchecked(xcb_ewmh_connection_t *ewmh,
                                                              xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_user_time(xcb_ewmh_connection_t *ewmh,
                                                    xcb_window_t window);

static inline uint8_t
xcb_ewmh_get_wm_user_time_from_reply(uint32_t *xtime,
                                     xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_cardinal_from_reply(xtime, r);
}

static inline uint8_t
xcb_ewmh_get_wm_user_time_reply(xcb_ewmh_connection_t *ewmh,
                                xcb_get_property_cookie_t cookie,
                                uint32_t *xtime,
                                xcb_generic_error_t **e)
{
  return xcb_ewmh_get_cardinal_reply(ewmh, cookie, xtime, e);
}

xcb_void_cookie_t xcb_ewmh_set_wm_user_time_window(xcb_ewmh_connection_t *ewmh,
                                                   xcb_window_t window,
                                                   uint32_t xtime);

xcb_void_cookie_t xcb_ewmh_set_wm_user_time_window_checked(xcb_ewmh_connection_t *ewmh,
                                                           xcb_window_t window,
                                                           uint32_t pid);

xcb_get_property_cookie_t xcb_ewmh_get_wm_user_time_window_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                     xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_user_time_window(xcb_ewmh_connection_t *ewmh,
                                                           xcb_window_t window);

static inline uint8_t
xcb_ewmh_get_wm_user_time_window_from_reply(uint32_t *xtime,
                                            xcb_get_property_reply_t *r)
{
  return xcb_ewmh_get_cardinal_from_reply(xtime, r);
}

static inline uint8_t
xcb_ewmh_get_wm_user_time_window_reply(xcb_ewmh_connection_t *ewmh,
                                       xcb_get_property_cookie_t cookie,
                                       uint32_t *xtime,
                                       xcb_generic_error_t **e)
{
  return xcb_ewmh_get_cardinal_reply(ewmh, cookie, xtime, e);
}

xcb_void_cookie_t xcb_ewmh_set_frame_extents(xcb_ewmh_connection_t *ewmh,
                                             xcb_window_t window,
                                             uint32_t left, uint32_t right,
                                             uint32_t top, uint32_t bottom);

xcb_void_cookie_t xcb_ewmh_set_frame_extents_checked(xcb_ewmh_connection_t *ewmh,
                                                     xcb_window_t window,
                                                     uint32_t left, uint32_t right,
                                                     uint32_t top, uint32_t bottom);

xcb_get_property_cookie_t xcb_ewmh_get_frame_extents_unchecked(xcb_ewmh_connection_t *ewmh,
                                                               xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_frame_extents(xcb_ewmh_connection_t *ewmh,
                                                     xcb_window_t window);

uint8_t xcb_ewmh_get_frame_extents_from_reply(xcb_ewmh_get_extents_reply_t *frame_extents,
                                              xcb_get_property_reply_t *r);

uint8_t xcb_ewmh_get_frame_extents_reply(xcb_ewmh_connection_t *ewmh,
                                         xcb_get_property_cookie_t cookie,
                                         xcb_ewmh_get_extents_reply_t *frame_extents,
                                         xcb_generic_error_t **e);

xcb_void_cookie_t xcb_ewmh_send_wm_ping(xcb_ewmh_connection_t *ewmh,
                                        xcb_window_t window,
                                        xcb_timestamp_t timestamp);

xcb_void_cookie_t xcb_ewmh_set_wm_sync_request_counter(xcb_ewmh_connection_t *ewmh,
                                                       xcb_window_t window,
                                                       xcb_atom_t wm_sync_request_counter_atom,
                                                       uint32_t low, uint32_t high);

xcb_void_cookie_t xcb_ewmh_set_wm_sync_request_counter_checked(xcb_ewmh_connection_t *ewmh,
                                                               xcb_window_t window,
                                                               xcb_atom_t wm_sync_request_counter_atom,
                                                               uint32_t low, uint32_t high);

xcb_get_property_cookie_t xcb_ewmh_get_wm_sync_request_counter_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                         xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_sync_request_counter(xcb_ewmh_connection_t *ewmh,
                                                               xcb_window_t window);

uint8_t xcb_ewmh_get_wm_sync_request_counter_from_reply(uint64_t *counter,
                                                        xcb_get_property_reply_t *r);

uint8_t xcb_ewmh_get_wm_sync_request_counter_reply(xcb_ewmh_connection_t *ewmh,
                                                   xcb_get_property_cookie_t cookie,
                                                   uint64_t *counter,
                                                   xcb_generic_error_t **e);

xcb_void_cookie_t xcb_ewmh_send_wm_sync_request(xcb_ewmh_connection_t *ewmh,
                                                xcb_window_t window,
                                                xcb_atom_t wm_protocols_atom,
                                                xcb_atom_t wm_sync_request_atom,
                                                xcb_timestamp_t timestamp,
                                                uint64_t counter);

xcb_void_cookie_t xcb_ewmh_set_wm_fullscreen_monitors(xcb_ewmh_connection_t *ewmh,
                                                      xcb_window_t window,
                                                      uint32_t top, uint32_t bottom,
                                                      uint32_t left, uint32_t right);

xcb_void_cookie_t xcb_ewmh_set_wm_fullscreen_monitors_checked(xcb_ewmh_connection_t *ewmh,
                                                              xcb_window_t window,
                                                              uint32_t top, uint32_t bottom,
                                                              uint32_t left, uint32_t right);

xcb_get_property_cookie_t xcb_ewmh_get_wm_fullscreen_monitors_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                        xcb_window_t window);

xcb_get_property_cookie_t xcb_ewmh_get_wm_fullscreen_monitors(xcb_ewmh_connection_t *ewmh,
                                                              xcb_window_t window);

uint8_t xcb_ewmh_get_wm_fullscreen_monitors_from_reply(xcb_ewmh_get_wm_fullscreen_monitors_reply_t *monitors,
                                                       xcb_get_property_reply_t *r);

uint8_t xcb_ewmh_get_wm_fullscreen_monitors_reply(xcb_ewmh_connection_t *ewmh,
                                                  xcb_get_property_cookie_t cookie,
                                                  xcb_ewmh_get_wm_fullscreen_monitors_reply_t *monitors,
                                                  xcb_generic_error_t **e);


xcb_void_cookie_t xcb_ewmh_request_change_wm_fullscreen_monitors(xcb_ewmh_connection_t *ewmh,
                                                                 int screen_nbr,
                                                                 xcb_window_t window,
                                                                 uint32_t top, uint32_t bottom,
                                                                 uint32_t left, uint32_t right,
                                                                 xcb_ewmh_client_source_type_t source_indication);
xcb_void_cookie_t xcb_ewmh_set_wm_cm_owner(xcb_ewmh_connection_t *ewmh,
                                           int screen_nbr,
                                           xcb_window_t owner,
                                           xcb_timestamp_t timestamp,
                                           uint32_t selection_data1,
                                           uint32_t selection_data2);




xcb_void_cookie_t xcb_ewmh_set_wm_cm_owner_checked(xcb_ewmh_connection_t *ewmh,
                                                   int screen_nbr,
                                                   xcb_window_t owner,
                                                   xcb_timestamp_t timestamp,
                                                   uint32_t selection_data1,
                                                   uint32_t selection_data2);
xcb_get_selection_owner_cookie_t xcb_ewmh_get_wm_cm_owner_unchecked(xcb_ewmh_connection_t *ewmh,
                                                                    int screen_nbr);




xcb_get_selection_owner_cookie_t xcb_ewmh_get_wm_cm_owner(xcb_ewmh_connection_t *ewmh,
                                                          int screen_nbr);

uint8_t xcb_ewmh_get_wm_cm_owner_from_reply(xcb_window_t *owner,
                                            xcb_get_selection_owner_reply_t *r);
uint8_t xcb_ewmh_get_wm_cm_owner_reply(xcb_ewmh_connection_t *ewmh,
                                       xcb_get_selection_owner_cookie_t cookie,
                                       xcb_window_t *owner,
                                       xcb_generic_error_t **e);
typedef struct {


xcb_get_property_reply_t *_reply;

xcb_atom_t encoding;

uint32_t name_len;

char *name;

uint8_t format;
} xcb_icccm_get_text_property_reply_t;
xcb_get_property_cookie_t xcb_icccm_get_text_property(xcb_connection_t *c,
                                                        xcb_window_t window,
                                                        xcb_atom_t property);




xcb_get_property_cookie_t xcb_icccm_get_text_property_unchecked(xcb_connection_t *c,
                                                                  xcb_window_t window,
                                                                  xcb_atom_t property);
uint8_t xcb_icccm_get_text_property_reply(xcb_connection_t *c,
                                            xcb_get_property_cookie_t cookie,
                                            xcb_icccm_get_text_property_reply_t *prop,
                                            xcb_generic_error_t **e);






void xcb_icccm_get_text_property_reply_wipe(xcb_icccm_get_text_property_reply_t *prop);
xcb_void_cookie_t xcb_icccm_set_wm_name_checked(xcb_connection_t *c,
                                                  xcb_window_t window,
                                                  xcb_atom_t encoding,
                                                  uint8_t format,
                                                  uint32_t name_len,
                                                  const char *name);




xcb_void_cookie_t xcb_icccm_set_wm_name(xcb_connection_t *c, xcb_window_t window,
                                          xcb_atom_t encoding, uint8_t format,
                                          uint32_t name_len, const char *name);







xcb_get_property_cookie_t xcb_icccm_get_wm_name(xcb_connection_t *c,
                                                  xcb_window_t window);




xcb_get_property_cookie_t xcb_icccm_get_wm_name_unchecked(xcb_connection_t *c,
                                                            xcb_window_t window);
uint8_t xcb_icccm_get_wm_name_reply(xcb_connection_t *c,
                                      xcb_get_property_cookie_t cookie,
                                      xcb_icccm_get_text_property_reply_t *prop,
                                      xcb_generic_error_t **e);
xcb_void_cookie_t xcb_icccm_set_wm_icon_name_checked(xcb_connection_t *c,
                                                       xcb_window_t window,
                                                       xcb_atom_t encoding,
                                                       uint8_t format,
                                                       uint32_t name_len,
                                                       const char *name);




xcb_void_cookie_t xcb_icccm_set_wm_icon_name(xcb_connection_t *c,
                                               xcb_window_t window,
                                               xcb_atom_t encoding,
                                               uint8_t format,
                                               uint32_t name_len,
                                               const char *name);







xcb_get_property_cookie_t xcb_icccm_get_wm_icon_name(xcb_connection_t *c,
                                                       xcb_window_t window);




xcb_get_property_cookie_t xcb_icccm_get_wm_icon_name_unchecked(xcb_connection_t *c,
                                                                 xcb_window_t window);
uint8_t xcb_icccm_get_wm_icon_name_reply(xcb_connection_t *c,
                                           xcb_get_property_cookie_t cookie,
                                           xcb_icccm_get_text_property_reply_t *prop,
                                           xcb_generic_error_t **e);
xcb_void_cookie_t xcb_icccm_set_wm_colormap_windows_checked(xcb_connection_t *c,
                                                              xcb_window_t window,
                                                              xcb_atom_t wm_colormap_windows_atom,
                                                              uint32_t list_len,
                                                              const xcb_window_t *list);




xcb_void_cookie_t xcb_icccm_set_wm_colormap_windows(xcb_connection_t *c,
                                                      xcb_window_t window,
                                                      xcb_atom_t wm_colormap_windows_atom,
                                                      uint32_t list_len,
                                                      const xcb_window_t *list);




typedef struct {

uint32_t windows_len;

xcb_window_t *windows;


xcb_get_property_reply_t *_reply;
} xcb_icccm_get_wm_colormap_windows_reply_t;







xcb_get_property_cookie_t xcb_icccm_get_wm_colormap_windows(xcb_connection_t *c,
                                                              xcb_window_t window,
                                                              xcb_atom_t wm_colormap_windows_atom);




xcb_get_property_cookie_t xcb_icccm_get_wm_colormap_windows_unchecked(xcb_connection_t *c,
                                                                        xcb_window_t window,
                                                                        xcb_atom_t wm_colormap_windows_atom);
uint8_t xcb_icccm_get_wm_colormap_windows_from_reply(xcb_get_property_reply_t *reply,
                                                       xcb_icccm_get_wm_colormap_windows_reply_t *colormap_windows);
uint8_t xcb_icccm_get_wm_colormap_windows_reply(xcb_connection_t *c,
                                                  xcb_get_property_cookie_t cookie,
                                                  xcb_icccm_get_wm_colormap_windows_reply_t *windows,
                                                  xcb_generic_error_t **e);






void xcb_icccm_get_wm_colormap_windows_reply_wipe(xcb_icccm_get_wm_colormap_windows_reply_t *windows);
xcb_void_cookie_t xcb_icccm_set_wm_client_machine_checked(xcb_connection_t *c,
                                                            xcb_window_t window,
                                                            xcb_atom_t encoding,
                                                            uint8_t format,
                                                            uint32_t name_len,
                                                            const char *name);




xcb_void_cookie_t xcb_icccm_set_wm_client_machine(xcb_connection_t *c,
                                                    xcb_window_t window,
                                                    xcb_atom_t encoding,
                                                    uint8_t format,
                                                    uint32_t name_len,
                                                    const char *name);







xcb_get_property_cookie_t xcb_icccm_get_wm_client_machine(xcb_connection_t *c,
                                                            xcb_window_t window);




xcb_get_property_cookie_t xcb_icccm_get_wm_client_machine_unchecked(xcb_connection_t *c,
                                                                      xcb_window_t window);
uint8_t xcb_icccm_get_wm_client_machine_reply(xcb_connection_t *c,
                                                xcb_get_property_cookie_t cookie,
                                                xcb_icccm_get_text_property_reply_t *prop,
                                                xcb_generic_error_t **e);
xcb_void_cookie_t xcb_icccm_set_wm_class_checked(xcb_connection_t *c,
                                                   xcb_window_t window,
                                                   uint32_t class_len,
                                                   const char *class_name);




xcb_void_cookie_t xcb_icccm_set_wm_class(xcb_connection_t *c,
                                           xcb_window_t window,
                                           uint32_t class_len,
                                           const char *class_name);

typedef struct {

char *instance_name;

char *class_name;


xcb_get_property_reply_t *_reply;
} xcb_icccm_get_wm_class_reply_t;







xcb_get_property_cookie_t xcb_icccm_get_wm_class(xcb_connection_t *c,
                                                   xcb_window_t window);




xcb_get_property_cookie_t xcb_icccm_get_wm_class_unchecked(xcb_connection_t *c,
                                                             xcb_window_t window);
uint8_t
xcb_icccm_get_wm_class_from_reply(xcb_icccm_get_wm_class_reply_t *prop,
                                    xcb_get_property_reply_t *reply);
uint8_t xcb_icccm_get_wm_class_reply(xcb_connection_t *c,
                                       xcb_get_property_cookie_t cookie,
                                       xcb_icccm_get_wm_class_reply_t *prop,
                                       xcb_generic_error_t **e);






void xcb_icccm_get_wm_class_reply_wipe(xcb_icccm_get_wm_class_reply_t *prop);
xcb_void_cookie_t xcb_icccm_set_wm_transient_for_checked(xcb_connection_t *c,
                                                           xcb_window_t window,
                                                           xcb_window_t transient_for_window);




xcb_void_cookie_t xcb_icccm_set_wm_transient_for(xcb_connection_t *c,
                                                   xcb_window_t window,
                                                   xcb_window_t transient_for_window);







xcb_get_property_cookie_t xcb_icccm_get_wm_transient_for(xcb_connection_t *c,
                                                           xcb_window_t window);




xcb_get_property_cookie_t xcb_icccm_get_wm_transient_for_unchecked(xcb_connection_t *c,
                                                                     xcb_window_t window);







uint8_t
xcb_icccm_get_wm_transient_for_from_reply(xcb_window_t *prop,
                                            xcb_get_property_reply_t *reply);
uint8_t xcb_icccm_get_wm_transient_for_reply(xcb_connection_t *c,
                                               xcb_get_property_cookie_t cookie,
                                               xcb_window_t *prop,
                                               xcb_generic_error_t **e);



typedef enum {
XCB_ICCCM_SIZE_HINT_US_POSITION = 1 << 0,
  XCB_ICCCM_SIZE_HINT_US_SIZE = 1 << 1,
  XCB_ICCCM_SIZE_HINT_P_POSITION = 1 << 2,
  XCB_ICCCM_SIZE_HINT_P_SIZE = 1 << 3,
  XCB_ICCCM_SIZE_HINT_P_MIN_SIZE = 1 << 4,
  XCB_ICCCM_SIZE_HINT_P_MAX_SIZE = 1 << 5,
  XCB_ICCCM_SIZE_HINT_P_RESIZE_INC = 1 << 6,
  XCB_ICCCM_SIZE_HINT_P_ASPECT = 1 << 7,
  XCB_ICCCM_SIZE_HINT_BASE_SIZE = 1 << 8,
  XCB_ICCCM_SIZE_HINT_P_WIN_GRAVITY = 1 << 9
  } xcb_icccm_size_hints_flags_t;




typedef struct {

uint32_t flags;

int32_t x, y;

int32_t width, height;

int32_t min_width, min_height;

int32_t max_width, max_height;

int32_t width_inc, height_inc;

int32_t min_aspect_num, min_aspect_den;

int32_t max_aspect_num, max_aspect_den;

int32_t base_width, base_height;

uint32_t win_gravity;
} xcb_size_hints_t;
void xcb_icccm_size_hints_set_position(xcb_size_hints_t *hints, int user_specified,
                                         int32_t x, int32_t y);
void xcb_icccm_size_hints_set_size(xcb_size_hints_t *hints, int user_specified,
                                     int32_t width, int32_t height);







void xcb_icccm_size_hints_set_min_size(xcb_size_hints_t *hints, int32_t min_width,
                                         int32_t min_height);







void xcb_icccm_size_hints_set_max_size(xcb_size_hints_t *hints, int32_t max_width,
                                         int32_t max_height);







void xcb_icccm_size_hints_set_resize_inc(xcb_size_hints_t *hints, int32_t width_inc,
                                           int32_t height_inc);
void xcb_icccm_size_hints_set_aspect(xcb_size_hints_t *hints, int32_t min_aspect_num,
                                       int32_t min_aspect_den, int32_t max_aspect_num,
                                     int32_t max_aspect_den);







void xcb_icccm_size_hints_set_base_size(xcb_size_hints_t *hints, int32_t base_width,
                                          int32_t base_height);






void xcb_icccm_size_hints_set_win_gravity(xcb_size_hints_t *hints,
                                            xcb_gravity_t win_gravity);
xcb_void_cookie_t xcb_icccm_set_wm_size_hints_checked(xcb_connection_t *c,
                                                        xcb_window_t window,
                                                      xcb_atom_t property,
                                                      xcb_size_hints_t *hints);




xcb_void_cookie_t xcb_icccm_set_wm_size_hints(xcb_connection_t *c,
                                                xcb_window_t window,
                                              xcb_atom_t property,
                                              xcb_size_hints_t *hints);
xcb_get_property_cookie_t xcb_icccm_get_wm_size_hints(xcb_connection_t *c,
                                                        xcb_window_t window,
                                                      xcb_atom_t property);




xcb_get_property_cookie_t xcb_icccm_get_wm_size_hints_unchecked(xcb_connection_t *c,
                                                                  xcb_window_t window,
                                                                xcb_atom_t property);
uint8_t xcb_icccm_get_wm_size_hints_reply(xcb_connection_t *c,
                                            xcb_get_property_cookie_t cookie,
                                          xcb_size_hints_t *hints,
                                          xcb_generic_error_t **e);
xcb_void_cookie_t xcb_icccm_set_wm_normal_hints_checked(xcb_connection_t *c,
                                                          xcb_window_t window,
                                                        xcb_size_hints_t *hints);




xcb_void_cookie_t xcb_icccm_set_wm_normal_hints(xcb_connection_t *c,
                                                  xcb_window_t window,
                                                xcb_size_hints_t *hints);







xcb_get_property_cookie_t xcb_icccm_get_wm_normal_hints(xcb_connection_t *c,
                                                          xcb_window_t window);




xcb_get_property_cookie_t xcb_icccm_get_wm_normal_hints_unchecked(xcb_connection_t *c,
                                                                    xcb_window_t window);







uint8_t
xcb_icccm_get_wm_size_hints_from_reply(xcb_size_hints_t *hints,
                                         xcb_get_property_reply_t *reply);
uint8_t xcb_icccm_get_wm_normal_hints_reply(xcb_connection_t *c,
                                              xcb_get_property_cookie_t cookie,
                                            xcb_size_hints_t *hints,
                                            xcb_generic_error_t **e);






typedef struct {

int32_t flags;


  uint32_t input;

  int32_t initial_state;

  xcb_pixmap_t icon_pixmap;

  xcb_window_t icon_window;

  int32_t icon_x, icon_y;

  xcb_pixmap_t icon_mask;

  xcb_window_t window_group;
} xcb_icccm_wm_hints_t;







typedef enum {
  XCB_ICCCM_WM_STATE_WITHDRAWN = 0,
  XCB_ICCCM_WM_STATE_NORMAL = 1,
  XCB_ICCCM_WM_STATE_ICONIC = 3
} xcb_icccm_wm_state_t;

typedef enum {
  XCB_ICCCM_WM_HINT_INPUT = (1 << 0),
  XCB_ICCCM_WM_HINT_STATE = (1 << 1),
  XCB_ICCCM_WM_HINT_ICON_PIXMAP = (1 << 2),
  XCB_ICCCM_WM_HINT_ICON_WINDOW = (1 << 3),
  XCB_ICCCM_WM_HINT_ICON_POSITION = (1 << 4),
  XCB_ICCCM_WM_HINT_ICON_MASK = (1 << 5),
  XCB_ICCCM_WM_HINT_WINDOW_GROUP = (1 << 6),
  XCB_ICCCM_WM_HINT_X_URGENCY = (1 << 8)
} xcb_icccm_wm_t;
uint32_t xcb_icccm_wm_hints_get_urgency(xcb_icccm_wm_hints_t *hints);






void xcb_icccm_wm_hints_set_input(xcb_icccm_wm_hints_t *hints, uint8_t input);





void xcb_icccm_wm_hints_set_iconic(xcb_icccm_wm_hints_t *hints);





void xcb_icccm_wm_hints_set_normal(xcb_icccm_wm_hints_t *hints);





void xcb_icccm_wm_hints_set_withdrawn(xcb_icccm_wm_hints_t *hints);





void xcb_icccm_wm_hints_set_none(xcb_icccm_wm_hints_t *hints);






void xcb_icccm_wm_hints_set_icon_pixmap(xcb_icccm_wm_hints_t *hints,
                                        xcb_pixmap_t icon_pixmap);






void xcb_icccm_wm_hints_set_icon_mask(xcb_icccm_wm_hints_t *hints, xcb_pixmap_t icon_mask);






void xcb_icccm_wm_hints_set_icon_window(xcb_icccm_wm_hints_t *hints,
                                        xcb_window_t icon_window);






void xcb_icccm_wm_hints_set_window_group(xcb_icccm_wm_hints_t *hints,
                                         xcb_window_t window_group);





void xcb_icccm_wm_hints_set_urgency(xcb_icccm_wm_hints_t *hints);







xcb_void_cookie_t xcb_icccm_set_wm_hints_checked(xcb_connection_t *c,
                                                 xcb_window_t window,
                                                 xcb_icccm_wm_hints_t *hints);




xcb_void_cookie_t xcb_icccm_set_wm_hints(xcb_connection_t *c,
                                         xcb_window_t window,
                                         xcb_icccm_wm_hints_t *hints);







xcb_get_property_cookie_t xcb_icccm_get_wm_hints(xcb_connection_t *c,
                                                 xcb_window_t window);




xcb_get_property_cookie_t xcb_icccm_get_wm_hints_unchecked(xcb_connection_t *c,
                                                           xcb_window_t window);







uint8_t
xcb_icccm_get_wm_hints_from_reply(xcb_icccm_wm_hints_t *hints,
                                  xcb_get_property_reply_t *reply);
uint8_t xcb_icccm_get_wm_hints_reply(xcb_connection_t *c,
                                     xcb_get_property_cookie_t cookie,
                                     xcb_icccm_wm_hints_t *hints,
                                     xcb_generic_error_t **e);
xcb_void_cookie_t xcb_icccm_set_wm_protocols_checked(xcb_connection_t *c,
                                                     xcb_window_t window,
                                                     xcb_atom_t wm_protocols,
                                                     uint32_t list_len,
                                                     xcb_atom_t *list);




xcb_void_cookie_t xcb_icccm_set_wm_protocols(xcb_connection_t *c,
                                             xcb_window_t window,
                                             xcb_atom_t wm_protocols,
                                             uint32_t list_len,
                                             xcb_atom_t *list);




typedef struct {

  uint32_t atoms_len;

  xcb_atom_t *atoms;


  xcb_get_property_reply_t *_reply;
} xcb_icccm_get_wm_protocols_reply_t;







xcb_get_property_cookie_t xcb_icccm_get_wm_protocols(xcb_connection_t *c,
                                                     xcb_window_t window,
                                                     xcb_atom_t wm_protocol_atom);




xcb_get_property_cookie_t xcb_icccm_get_wm_protocols_unchecked(xcb_connection_t *c,
                                                               xcb_window_t window,
                                                               xcb_atom_t wm_protocol_atom);
uint8_t xcb_icccm_get_wm_protocols_from_reply(xcb_get_property_reply_t *reply,
                                              xcb_icccm_get_wm_protocols_reply_t *protocols);
uint8_t xcb_icccm_get_wm_protocols_reply(xcb_connection_t *c,
                                         xcb_get_property_cookie_t cookie,
                                         xcb_icccm_get_wm_protocols_reply_t *protocols,
                                         xcb_generic_error_t **e);






void xcb_icccm_get_wm_protocols_reply_wipe(xcb_icccm_get_wm_protocols_reply_t *protocols);
extern xcb_extension_t xcb_render_id;

typedef enum xcb_render_pict_type_t {
    XCB_RENDER_PICT_TYPE_INDEXED = 0,
    XCB_RENDER_PICT_TYPE_DIRECT = 1
} xcb_render_pict_type_t;

typedef enum xcb_render_picture_enum_t {
    XCB_RENDER_PICTURE_NONE = 0
} xcb_render_picture_enum_t;

typedef enum xcb_render_pict_op_t {
    XCB_RENDER_PICT_OP_CLEAR = 0,
    XCB_RENDER_PICT_OP_SRC = 1,
    XCB_RENDER_PICT_OP_DST = 2,
    XCB_RENDER_PICT_OP_OVER = 3,
    XCB_RENDER_PICT_OP_OVER_REVERSE = 4,
    XCB_RENDER_PICT_OP_IN = 5,
    XCB_RENDER_PICT_OP_IN_REVERSE = 6,
    XCB_RENDER_PICT_OP_OUT = 7,
    XCB_RENDER_PICT_OP_OUT_REVERSE = 8,
    XCB_RENDER_PICT_OP_ATOP = 9,
    XCB_RENDER_PICT_OP_ATOP_REVERSE = 10,
    XCB_RENDER_PICT_OP_XOR = 11,
    XCB_RENDER_PICT_OP_ADD = 12,
    XCB_RENDER_PICT_OP_SATURATE = 13,
    XCB_RENDER_PICT_OP_DISJOINT_CLEAR = 16,
    XCB_RENDER_PICT_OP_DISJOINT_SRC = 17,
    XCB_RENDER_PICT_OP_DISJOINT_DST = 18,
    XCB_RENDER_PICT_OP_DISJOINT_OVER = 19,
    XCB_RENDER_PICT_OP_DISJOINT_OVER_REVERSE = 20,
    XCB_RENDER_PICT_OP_DISJOINT_IN = 21,
    XCB_RENDER_PICT_OP_DISJOINT_IN_REVERSE = 22,
    XCB_RENDER_PICT_OP_DISJOINT_OUT = 23,
    XCB_RENDER_PICT_OP_DISJOINT_OUT_REVERSE = 24,
    XCB_RENDER_PICT_OP_DISJOINT_ATOP = 25,
    XCB_RENDER_PICT_OP_DISJOINT_ATOP_REVERSE = 26,
    XCB_RENDER_PICT_OP_DISJOINT_XOR = 27,
    XCB_RENDER_PICT_OP_CONJOINT_CLEAR = 32,
    XCB_RENDER_PICT_OP_CONJOINT_SRC = 33,
    XCB_RENDER_PICT_OP_CONJOINT_DST = 34,
    XCB_RENDER_PICT_OP_CONJOINT_OVER = 35,
    XCB_RENDER_PICT_OP_CONJOINT_OVER_REVERSE = 36,
    XCB_RENDER_PICT_OP_CONJOINT_IN = 37,
    XCB_RENDER_PICT_OP_CONJOINT_IN_REVERSE = 38,
    XCB_RENDER_PICT_OP_CONJOINT_OUT = 39,
    XCB_RENDER_PICT_OP_CONJOINT_OUT_REVERSE = 40,
    XCB_RENDER_PICT_OP_CONJOINT_ATOP = 41,
    XCB_RENDER_PICT_OP_CONJOINT_ATOP_REVERSE = 42,
    XCB_RENDER_PICT_OP_CONJOINT_XOR = 43,
    XCB_RENDER_PICT_OP_MULTIPLY = 48,
    XCB_RENDER_PICT_OP_SCREEN = 49,
    XCB_RENDER_PICT_OP_OVERLAY = 50,
    XCB_RENDER_PICT_OP_DARKEN = 51,
    XCB_RENDER_PICT_OP_LIGHTEN = 52,
    XCB_RENDER_PICT_OP_COLOR_DODGE = 53,
    XCB_RENDER_PICT_OP_COLOR_BURN = 54,
    XCB_RENDER_PICT_OP_HARD_LIGHT = 55,
    XCB_RENDER_PICT_OP_SOFT_LIGHT = 56,
    XCB_RENDER_PICT_OP_DIFFERENCE = 57,
    XCB_RENDER_PICT_OP_EXCLUSION = 58,
    XCB_RENDER_PICT_OP_HSL_HUE = 59,
    XCB_RENDER_PICT_OP_HSL_SATURATION = 60,
    XCB_RENDER_PICT_OP_HSL_COLOR = 61,
    XCB_RENDER_PICT_OP_HSL_LUMINOSITY = 62
} xcb_render_pict_op_t;

typedef enum xcb_render_poly_edge_t {
    XCB_RENDER_POLY_EDGE_SHARP = 0,
    XCB_RENDER_POLY_EDGE_SMOOTH = 1
} xcb_render_poly_edge_t;

typedef enum xcb_render_poly_mode_t {
    XCB_RENDER_POLY_MODE_PRECISE = 0,
    XCB_RENDER_POLY_MODE_IMPRECISE = 1
} xcb_render_poly_mode_t;

typedef enum xcb_render_cp_t {
    XCB_RENDER_CP_REPEAT = 1,
    XCB_RENDER_CP_ALPHA_MAP = 2,
    XCB_RENDER_CP_ALPHA_X_ORIGIN = 4,
    XCB_RENDER_CP_ALPHA_Y_ORIGIN = 8,
    XCB_RENDER_CP_CLIP_X_ORIGIN = 16,
    XCB_RENDER_CP_CLIP_Y_ORIGIN = 32,
    XCB_RENDER_CP_CLIP_MASK = 64,
    XCB_RENDER_CP_GRAPHICS_EXPOSURE = 128,
    XCB_RENDER_CP_SUBWINDOW_MODE = 256,
    XCB_RENDER_CP_POLY_EDGE = 512,
    XCB_RENDER_CP_POLY_MODE = 1024,
    XCB_RENDER_CP_DITHER = 2048,
    XCB_RENDER_CP_COMPONENT_ALPHA = 4096
} xcb_render_cp_t;

typedef enum xcb_render_sub_pixel_t {
    XCB_RENDER_SUB_PIXEL_UNKNOWN = 0,
    XCB_RENDER_SUB_PIXEL_HORIZONTAL_RGB = 1,
    XCB_RENDER_SUB_PIXEL_HORIZONTAL_BGR = 2,
    XCB_RENDER_SUB_PIXEL_VERTICAL_RGB = 3,
    XCB_RENDER_SUB_PIXEL_VERTICAL_BGR = 4,
    XCB_RENDER_SUB_PIXEL_NONE = 5
} xcb_render_sub_pixel_t;

typedef enum xcb_render_repeat_t {
    XCB_RENDER_REPEAT_NONE = 0,
    XCB_RENDER_REPEAT_NORMAL = 1,
    XCB_RENDER_REPEAT_PAD = 2,
    XCB_RENDER_REPEAT_REFLECT = 3
} xcb_render_repeat_t;

typedef uint32_t xcb_render_glyph_t;




typedef struct xcb_render_glyph_iterator_t {
    xcb_render_glyph_t *data;
    int rem;
    int index;
} xcb_render_glyph_iterator_t;

typedef uint32_t xcb_render_glyphset_t;




typedef struct xcb_render_glyphset_iterator_t {
    xcb_render_glyphset_t *data;
    int rem;
    int index;
} xcb_render_glyphset_iterator_t;

typedef uint32_t xcb_render_picture_t;




typedef struct xcb_render_picture_iterator_t {
    xcb_render_picture_t *data;
    int rem;
    int index;
} xcb_render_picture_iterator_t;

typedef uint32_t xcb_render_pictformat_t;




typedef struct xcb_render_pictformat_iterator_t {
    xcb_render_pictformat_t *data;
    int rem;
    int index;
} xcb_render_pictformat_iterator_t;

typedef int32_t xcb_render_fixed_t;




typedef struct xcb_render_fixed_iterator_t {
    xcb_render_fixed_t *data;
    int rem;
    int index;
} xcb_render_fixed_iterator_t;







typedef struct xcb_render_pict_format_error_t {
    uint8_t response_type;
    uint8_t error_code;
    uint16_t sequence;
} xcb_render_pict_format_error_t;







typedef struct xcb_render_picture_error_t {
    uint8_t response_type;
    uint8_t error_code;
    uint16_t sequence;
} xcb_render_picture_error_t;







typedef struct xcb_render_pict_op_error_t {
    uint8_t response_type;
    uint8_t error_code;
    uint16_t sequence;
} xcb_render_pict_op_error_t;







typedef struct xcb_render_glyph_set_error_t {
    uint8_t response_type;
    uint8_t error_code;
    uint16_t sequence;
} xcb_render_glyph_set_error_t;







typedef struct xcb_render_glyph_error_t {
    uint8_t response_type;
    uint8_t error_code;
    uint16_t sequence;
} xcb_render_glyph_error_t;




typedef struct xcb_render_directformat_t {
    uint16_t red_shift;
    uint16_t red_mask;
    uint16_t green_shift;
    uint16_t green_mask;
    uint16_t blue_shift;
    uint16_t blue_mask;
    uint16_t alpha_shift;
    uint16_t alpha_mask;
} xcb_render_directformat_t;




typedef struct xcb_render_directformat_iterator_t {
    xcb_render_directformat_t *data;
    int rem;
    int index;
} xcb_render_directformat_iterator_t;




typedef struct xcb_render_pictforminfo_t {
    xcb_render_pictformat_t id;
    uint8_t type;
    uint8_t depth;
    uint8_t pad0[2];
    xcb_render_directformat_t direct;
    xcb_colormap_t colormap;
} xcb_render_pictforminfo_t;




typedef struct xcb_render_pictforminfo_iterator_t {
    xcb_render_pictforminfo_t *data;
    int rem;
    int index;
} xcb_render_pictforminfo_iterator_t;




typedef struct xcb_render_pictvisual_t {
    xcb_visualid_t visual;
    xcb_render_pictformat_t format;
} xcb_render_pictvisual_t;




typedef struct xcb_render_pictvisual_iterator_t {
    xcb_render_pictvisual_t *data;
    int rem;
    int index;
} xcb_render_pictvisual_iterator_t;




typedef struct xcb_render_pictdepth_t {
    uint8_t depth;
    uint8_t pad0;
    uint16_t num_visuals;
    uint8_t pad1[4];
} xcb_render_pictdepth_t;




typedef struct xcb_render_pictdepth_iterator_t {
    xcb_render_pictdepth_t *data;
    int rem;
    int index;
} xcb_render_pictdepth_iterator_t;




typedef struct xcb_render_pictscreen_t {
    uint32_t num_depths;
    xcb_render_pictformat_t fallback;
} xcb_render_pictscreen_t;




typedef struct xcb_render_pictscreen_iterator_t {
    xcb_render_pictscreen_t *data;
    int rem;
    int index;
} xcb_render_pictscreen_iterator_t;




typedef struct xcb_render_indexvalue_t {
    uint32_t pixel;
    uint16_t red;
    uint16_t green;
    uint16_t blue;
    uint16_t alpha;
} xcb_render_indexvalue_t;




typedef struct xcb_render_indexvalue_iterator_t {
    xcb_render_indexvalue_t *data;
    int rem;
    int index;
} xcb_render_indexvalue_iterator_t;




typedef struct xcb_render_color_t {
    uint16_t red;
    uint16_t green;
    uint16_t blue;
    uint16_t alpha;
} xcb_render_color_t;




typedef struct xcb_render_color_iterator_t {
    xcb_render_color_t *data;
    int rem;
    int index;
} xcb_render_color_iterator_t;




typedef struct xcb_render_pointfix_t {
    xcb_render_fixed_t x;
    xcb_render_fixed_t y;
} xcb_render_pointfix_t;




typedef struct xcb_render_pointfix_iterator_t {
    xcb_render_pointfix_t *data;
    int rem;
    int index;
} xcb_render_pointfix_iterator_t;




typedef struct xcb_render_linefix_t {
    xcb_render_pointfix_t p1;
    xcb_render_pointfix_t p2;
} xcb_render_linefix_t;




typedef struct xcb_render_linefix_iterator_t {
    xcb_render_linefix_t *data;
    int rem;
    int index;
} xcb_render_linefix_iterator_t;




typedef struct xcb_render_triangle_t {
    xcb_render_pointfix_t p1;
    xcb_render_pointfix_t p2;
    xcb_render_pointfix_t p3;
} xcb_render_triangle_t;




typedef struct xcb_render_triangle_iterator_t {
    xcb_render_triangle_t *data;
    int rem;
    int index;
} xcb_render_triangle_iterator_t;




typedef struct xcb_render_trapezoid_t {
    xcb_render_fixed_t top;
    xcb_render_fixed_t bottom;
    xcb_render_linefix_t left;
    xcb_render_linefix_t right;
} xcb_render_trapezoid_t;




typedef struct xcb_render_trapezoid_iterator_t {
    xcb_render_trapezoid_t *data;
    int rem;
    int index;
} xcb_render_trapezoid_iterator_t;




typedef struct xcb_render_glyphinfo_t {
    uint16_t width;
    uint16_t height;
    int16_t x;
    int16_t y;
    int16_t x_off;
    int16_t y_off;
} xcb_render_glyphinfo_t;




typedef struct xcb_render_glyphinfo_iterator_t {
    xcb_render_glyphinfo_t *data;
    int rem;
    int index;
} xcb_render_glyphinfo_iterator_t;




typedef struct xcb_render_query_version_cookie_t {
    unsigned int sequence;
} xcb_render_query_version_cookie_t;







typedef struct xcb_render_query_version_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    uint32_t client_major_version;
    uint32_t client_minor_version;
} xcb_render_query_version_request_t;




typedef struct xcb_render_query_version_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint32_t major_version;
    uint32_t minor_version;
    uint8_t pad1[16];
} xcb_render_query_version_reply_t;




typedef struct xcb_render_query_pict_formats_cookie_t {
    unsigned int sequence;
} xcb_render_query_pict_formats_cookie_t;







typedef struct xcb_render_query_pict_formats_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
} xcb_render_query_pict_formats_request_t;




typedef struct xcb_render_query_pict_formats_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint32_t num_formats;
    uint32_t num_screens;
    uint32_t num_depths;
    uint32_t num_visuals;
    uint32_t num_subpixel;
    uint8_t pad1[4];
} xcb_render_query_pict_formats_reply_t;




typedef struct xcb_render_query_pict_index_values_cookie_t {
    unsigned int sequence;
} xcb_render_query_pict_index_values_cookie_t;







typedef struct xcb_render_query_pict_index_values_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_pictformat_t format;
} xcb_render_query_pict_index_values_request_t;




typedef struct xcb_render_query_pict_index_values_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint32_t num_values;
    uint8_t pad1[20];
} xcb_render_query_pict_index_values_reply_t;







typedef struct xcb_render_create_picture_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_picture_t pid;
    xcb_drawable_t drawable;
    xcb_render_pictformat_t format;
    uint32_t value_mask;
} xcb_render_create_picture_request_t;







typedef struct xcb_render_change_picture_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_picture_t picture;
    uint32_t value_mask;
} xcb_render_change_picture_request_t;







typedef struct xcb_render_set_picture_clip_rectangles_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_picture_t picture;
    int16_t clip_x_origin;
    int16_t clip_y_origin;
} xcb_render_set_picture_clip_rectangles_request_t;







typedef struct xcb_render_free_picture_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_picture_t picture;
} xcb_render_free_picture_request_t;







typedef struct xcb_render_composite_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    uint8_t op;
    uint8_t pad0[3];
    xcb_render_picture_t src;
    xcb_render_picture_t mask;
    xcb_render_picture_t dst;
    int16_t src_x;
    int16_t src_y;
    int16_t mask_x;
    int16_t mask_y;
    int16_t dst_x;
    int16_t dst_y;
    uint16_t width;
    uint16_t height;
} xcb_render_composite_request_t;







typedef struct xcb_render_trapezoids_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    uint8_t op;
    uint8_t pad0[3];
    xcb_render_picture_t src;
    xcb_render_picture_t dst;
    xcb_render_pictformat_t mask_format;
    int16_t src_x;
    int16_t src_y;
} xcb_render_trapezoids_request_t;







typedef struct xcb_render_triangles_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    uint8_t op;
    uint8_t pad0[3];
    xcb_render_picture_t src;
    xcb_render_picture_t dst;
    xcb_render_pictformat_t mask_format;
    int16_t src_x;
    int16_t src_y;
} xcb_render_triangles_request_t;







typedef struct xcb_render_tri_strip_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    uint8_t op;
    uint8_t pad0[3];
    xcb_render_picture_t src;
    xcb_render_picture_t dst;
    xcb_render_pictformat_t mask_format;
    int16_t src_x;
    int16_t src_y;
} xcb_render_tri_strip_request_t;







typedef struct xcb_render_tri_fan_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    uint8_t op;
    uint8_t pad0[3];
    xcb_render_picture_t src;
    xcb_render_picture_t dst;
    xcb_render_pictformat_t mask_format;
    int16_t src_x;
    int16_t src_y;
} xcb_render_tri_fan_request_t;







typedef struct xcb_render_create_glyph_set_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_glyphset_t gsid;
    xcb_render_pictformat_t format;
} xcb_render_create_glyph_set_request_t;







typedef struct xcb_render_reference_glyph_set_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_glyphset_t gsid;
    xcb_render_glyphset_t existing;
} xcb_render_reference_glyph_set_request_t;







typedef struct xcb_render_free_glyph_set_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_glyphset_t glyphset;
} xcb_render_free_glyph_set_request_t;







typedef struct xcb_render_add_glyphs_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_glyphset_t glyphset;
    uint32_t glyphs_len;
} xcb_render_add_glyphs_request_t;







typedef struct xcb_render_free_glyphs_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_glyphset_t glyphset;
} xcb_render_free_glyphs_request_t;







typedef struct xcb_render_composite_glyphs_8_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    uint8_t op;
    uint8_t pad0[3];
    xcb_render_picture_t src;
    xcb_render_picture_t dst;
    xcb_render_pictformat_t mask_format;
    xcb_render_glyphset_t glyphset;
    int16_t src_x;
    int16_t src_y;
} xcb_render_composite_glyphs_8_request_t;







typedef struct xcb_render_composite_glyphs_16_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    uint8_t op;
    uint8_t pad0[3];
    xcb_render_picture_t src;
    xcb_render_picture_t dst;
    xcb_render_pictformat_t mask_format;
    xcb_render_glyphset_t glyphset;
    int16_t src_x;
    int16_t src_y;
} xcb_render_composite_glyphs_16_request_t;







typedef struct xcb_render_composite_glyphs_32_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    uint8_t op;
    uint8_t pad0[3];
    xcb_render_picture_t src;
    xcb_render_picture_t dst;
    xcb_render_pictformat_t mask_format;
    xcb_render_glyphset_t glyphset;
    int16_t src_x;
    int16_t src_y;
} xcb_render_composite_glyphs_32_request_t;







typedef struct xcb_render_fill_rectangles_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    uint8_t op;
    uint8_t pad0[3];
    xcb_render_picture_t dst;
    xcb_render_color_t color;
} xcb_render_fill_rectangles_request_t;







typedef struct xcb_render_create_cursor_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_cursor_t cid;
    xcb_render_picture_t source;
    uint16_t x;
    uint16_t y;
} xcb_render_create_cursor_request_t;




typedef struct xcb_render_transform_t {
    xcb_render_fixed_t matrix11;
    xcb_render_fixed_t matrix12;
    xcb_render_fixed_t matrix13;
    xcb_render_fixed_t matrix21;
    xcb_render_fixed_t matrix22;
    xcb_render_fixed_t matrix23;
    xcb_render_fixed_t matrix31;
    xcb_render_fixed_t matrix32;
    xcb_render_fixed_t matrix33;
} xcb_render_transform_t;




typedef struct xcb_render_transform_iterator_t {
    xcb_render_transform_t *data;
    int rem;
    int index;
} xcb_render_transform_iterator_t;







typedef struct xcb_render_set_picture_transform_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_picture_t picture;
    xcb_render_transform_t transform;
} xcb_render_set_picture_transform_request_t;




typedef struct xcb_render_query_filters_cookie_t {
    unsigned int sequence;
} xcb_render_query_filters_cookie_t;







typedef struct xcb_render_query_filters_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_drawable_t drawable;
} xcb_render_query_filters_request_t;




typedef struct xcb_render_query_filters_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint32_t num_aliases;
    uint32_t num_filters;
    uint8_t pad1[16];
} xcb_render_query_filters_reply_t;







typedef struct xcb_render_set_picture_filter_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_picture_t picture;
    uint16_t filter_len;
    uint8_t pad0[2];
} xcb_render_set_picture_filter_request_t;




typedef struct xcb_render_animcursorelt_t {
    xcb_cursor_t cursor;
    uint32_t delay;
} xcb_render_animcursorelt_t;




typedef struct xcb_render_animcursorelt_iterator_t {
    xcb_render_animcursorelt_t *data;
    int rem;
    int index;
} xcb_render_animcursorelt_iterator_t;







typedef struct xcb_render_create_anim_cursor_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_cursor_t cid;
} xcb_render_create_anim_cursor_request_t;




typedef struct xcb_render_spanfix_t {
    xcb_render_fixed_t l;
    xcb_render_fixed_t r;
    xcb_render_fixed_t y;
} xcb_render_spanfix_t;




typedef struct xcb_render_spanfix_iterator_t {
    xcb_render_spanfix_t *data;
    int rem;
    int index;
} xcb_render_spanfix_iterator_t;




typedef struct xcb_render_trap_t {
    xcb_render_spanfix_t top;
    xcb_render_spanfix_t bot;
} xcb_render_trap_t;




typedef struct xcb_render_trap_iterator_t {
    xcb_render_trap_t *data;
    int rem;
    int index;
} xcb_render_trap_iterator_t;







typedef struct xcb_render_add_traps_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_picture_t picture;
    int16_t x_off;
    int16_t y_off;
} xcb_render_add_traps_request_t;







typedef struct xcb_render_create_solid_fill_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_picture_t picture;
    xcb_render_color_t color;
} xcb_render_create_solid_fill_request_t;







typedef struct xcb_render_create_linear_gradient_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_picture_t picture;
    xcb_render_pointfix_t p1;
    xcb_render_pointfix_t p2;
    uint32_t num_stops;
} xcb_render_create_linear_gradient_request_t;







typedef struct xcb_render_create_radial_gradient_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_picture_t picture;
    xcb_render_pointfix_t inner;
    xcb_render_pointfix_t outer;
    xcb_render_fixed_t inner_radius;
    xcb_render_fixed_t outer_radius;
    uint32_t num_stops;
} xcb_render_create_radial_gradient_request_t;







typedef struct xcb_render_create_conical_gradient_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_render_picture_t picture;
    xcb_render_pointfix_t center;
    xcb_render_fixed_t angle;
    uint32_t num_stops;
} xcb_render_create_conical_gradient_request_t;
void
xcb_render_glyph_next (xcb_render_glyph_iterator_t *i );
xcb_generic_iterator_t
xcb_render_glyph_end (xcb_render_glyph_iterator_t i );
void
xcb_render_glyphset_next (xcb_render_glyphset_iterator_t *i );
xcb_generic_iterator_t
xcb_render_glyphset_end (xcb_render_glyphset_iterator_t i );
void
xcb_render_picture_next (xcb_render_picture_iterator_t *i );
xcb_generic_iterator_t
xcb_render_picture_end (xcb_render_picture_iterator_t i );
void
xcb_render_pictformat_next (xcb_render_pictformat_iterator_t *i );
xcb_generic_iterator_t
xcb_render_pictformat_end (xcb_render_pictformat_iterator_t i );
void
xcb_render_fixed_next (xcb_render_fixed_iterator_t *i );
xcb_generic_iterator_t
xcb_render_fixed_end (xcb_render_fixed_iterator_t i );
void
xcb_render_directformat_next (xcb_render_directformat_iterator_t *i );
xcb_generic_iterator_t
xcb_render_directformat_end (xcb_render_directformat_iterator_t i );
void
xcb_render_pictforminfo_next (xcb_render_pictforminfo_iterator_t *i );
xcb_generic_iterator_t
xcb_render_pictforminfo_end (xcb_render_pictforminfo_iterator_t i );
void
xcb_render_pictvisual_next (xcb_render_pictvisual_iterator_t *i );
xcb_generic_iterator_t
xcb_render_pictvisual_end (xcb_render_pictvisual_iterator_t i );

int
xcb_render_pictdepth_sizeof (const void *_buffer );

xcb_render_pictvisual_t *
xcb_render_pictdepth_visuals (const xcb_render_pictdepth_t *R );

int
xcb_render_pictdepth_visuals_length (const xcb_render_pictdepth_t *R );

xcb_render_pictvisual_iterator_t
xcb_render_pictdepth_visuals_iterator (const xcb_render_pictdepth_t *R );
void
xcb_render_pictdepth_next (xcb_render_pictdepth_iterator_t *i );
xcb_generic_iterator_t
xcb_render_pictdepth_end (xcb_render_pictdepth_iterator_t i );

int
xcb_render_pictscreen_sizeof (const void *_buffer );

int
xcb_render_pictscreen_depths_length (const xcb_render_pictscreen_t *R );

xcb_render_pictdepth_iterator_t
xcb_render_pictscreen_depths_iterator (const xcb_render_pictscreen_t *R );
void
xcb_render_pictscreen_next (xcb_render_pictscreen_iterator_t *i );
xcb_generic_iterator_t
xcb_render_pictscreen_end (xcb_render_pictscreen_iterator_t i );
void
xcb_render_indexvalue_next (xcb_render_indexvalue_iterator_t *i );
xcb_generic_iterator_t
xcb_render_indexvalue_end (xcb_render_indexvalue_iterator_t i );
void
xcb_render_color_next (xcb_render_color_iterator_t *i );
xcb_generic_iterator_t
xcb_render_color_end (xcb_render_color_iterator_t i );
void
xcb_render_pointfix_next (xcb_render_pointfix_iterator_t *i );
xcb_generic_iterator_t
xcb_render_pointfix_end (xcb_render_pointfix_iterator_t i );
void
xcb_render_linefix_next (xcb_render_linefix_iterator_t *i );
xcb_generic_iterator_t
xcb_render_linefix_end (xcb_render_linefix_iterator_t i );
void
xcb_render_triangle_next (xcb_render_triangle_iterator_t *i );
xcb_generic_iterator_t
xcb_render_triangle_end (xcb_render_triangle_iterator_t i );
void
xcb_render_trapezoid_next (xcb_render_trapezoid_iterator_t *i );
xcb_generic_iterator_t
xcb_render_trapezoid_end (xcb_render_trapezoid_iterator_t i );
void
xcb_render_glyphinfo_next (xcb_render_glyphinfo_iterator_t *i );
xcb_generic_iterator_t
xcb_render_glyphinfo_end (xcb_render_glyphinfo_iterator_t i );
xcb_render_query_version_cookie_t
xcb_render_query_version (xcb_connection_t *c ,
                          uint32_t client_major_version ,
                          uint32_t client_minor_version );
xcb_render_query_version_cookie_t
xcb_render_query_version_unchecked (xcb_connection_t *c ,
                                    uint32_t client_major_version ,
                                    uint32_t client_minor_version );
xcb_render_query_version_reply_t *
xcb_render_query_version_reply (xcb_connection_t *c ,
                                xcb_render_query_version_cookie_t cookie ,
                                xcb_generic_error_t **e );

int
xcb_render_query_pict_formats_sizeof (const void *_buffer );
xcb_render_query_pict_formats_cookie_t
xcb_render_query_pict_formats (xcb_connection_t *c );
xcb_render_query_pict_formats_cookie_t
xcb_render_query_pict_formats_unchecked (xcb_connection_t *c );

xcb_render_pictforminfo_t *
xcb_render_query_pict_formats_formats (const xcb_render_query_pict_formats_reply_t *R );

int
xcb_render_query_pict_formats_formats_length (const xcb_render_query_pict_formats_reply_t *R );

xcb_render_pictforminfo_iterator_t
xcb_render_query_pict_formats_formats_iterator (const xcb_render_query_pict_formats_reply_t *R );

int
xcb_render_query_pict_formats_screens_length (const xcb_render_query_pict_formats_reply_t *R );

xcb_render_pictscreen_iterator_t
xcb_render_query_pict_formats_screens_iterator (const xcb_render_query_pict_formats_reply_t *R );

uint32_t *
xcb_render_query_pict_formats_subpixels (const xcb_render_query_pict_formats_reply_t *R );

int
xcb_render_query_pict_formats_subpixels_length (const xcb_render_query_pict_formats_reply_t *R );

xcb_generic_iterator_t
xcb_render_query_pict_formats_subpixels_end (const xcb_render_query_pict_formats_reply_t *R );
xcb_render_query_pict_formats_reply_t *
xcb_render_query_pict_formats_reply (xcb_connection_t *c ,
                                     xcb_render_query_pict_formats_cookie_t cookie ,
                                     xcb_generic_error_t **e );

int
xcb_render_query_pict_index_values_sizeof (const void *_buffer );
xcb_render_query_pict_index_values_cookie_t
xcb_render_query_pict_index_values (xcb_connection_t *c ,
                                    xcb_render_pictformat_t format );
xcb_render_query_pict_index_values_cookie_t
xcb_render_query_pict_index_values_unchecked (xcb_connection_t *c ,
                                              xcb_render_pictformat_t format );

xcb_render_indexvalue_t *
xcb_render_query_pict_index_values_values (const xcb_render_query_pict_index_values_reply_t *R );

int
xcb_render_query_pict_index_values_values_length (const xcb_render_query_pict_index_values_reply_t *R );

xcb_render_indexvalue_iterator_t
xcb_render_query_pict_index_values_values_iterator (const xcb_render_query_pict_index_values_reply_t *R );
xcb_render_query_pict_index_values_reply_t *
xcb_render_query_pict_index_values_reply (xcb_connection_t *c ,
                                          xcb_render_query_pict_index_values_cookie_t cookie ,
                                          xcb_generic_error_t **e );

int
xcb_render_create_picture_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_render_create_picture_checked (xcb_connection_t *c ,
                                   xcb_render_picture_t pid ,
                                   xcb_drawable_t drawable ,
                                   xcb_render_pictformat_t format ,
                                   uint32_t value_mask ,
                                   const uint32_t *value_list );
xcb_void_cookie_t
xcb_render_create_picture (xcb_connection_t *c ,
                           xcb_render_picture_t pid ,
                           xcb_drawable_t drawable ,
                           xcb_render_pictformat_t format ,
                           uint32_t value_mask ,
                           const uint32_t *value_list );

int
xcb_render_change_picture_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_render_change_picture_checked (xcb_connection_t *c ,
                                   xcb_render_picture_t picture ,
                                   uint32_t value_mask ,
                                   const uint32_t *value_list );
xcb_void_cookie_t
xcb_render_change_picture (xcb_connection_t *c ,
                           xcb_render_picture_t picture ,
                           uint32_t value_mask ,
                           const uint32_t *value_list );

int
xcb_render_set_picture_clip_rectangles_sizeof (const void *_buffer ,
                                               uint32_t rectangles_len );
xcb_void_cookie_t
xcb_render_set_picture_clip_rectangles_checked (xcb_connection_t *c ,
                                                xcb_render_picture_t picture ,
                                                int16_t clip_x_origin ,
                                                int16_t clip_y_origin ,
                                                uint32_t rectangles_len ,
                                                const xcb_rectangle_t *rectangles );
xcb_void_cookie_t
xcb_render_set_picture_clip_rectangles (xcb_connection_t *c ,
                                        xcb_render_picture_t picture ,
                                        int16_t clip_x_origin ,
                                        int16_t clip_y_origin ,
                                        uint32_t rectangles_len ,
                                        const xcb_rectangle_t *rectangles );
xcb_void_cookie_t
xcb_render_free_picture_checked (xcb_connection_t *c ,
                                 xcb_render_picture_t picture );
xcb_void_cookie_t
xcb_render_free_picture (xcb_connection_t *c ,
                         xcb_render_picture_t picture );
xcb_void_cookie_t
xcb_render_composite_checked (xcb_connection_t *c ,
                              uint8_t op ,
                              xcb_render_picture_t src ,
                              xcb_render_picture_t mask ,
                              xcb_render_picture_t dst ,
                              int16_t src_x ,
                              int16_t src_y ,
                              int16_t mask_x ,
                              int16_t mask_y ,
                              int16_t dst_x ,
                              int16_t dst_y ,
                              uint16_t width ,
                              uint16_t height );
xcb_void_cookie_t
xcb_render_composite (xcb_connection_t *c ,
                      uint8_t op ,
                      xcb_render_picture_t src ,
                      xcb_render_picture_t mask ,
                      xcb_render_picture_t dst ,
                      int16_t src_x ,
                      int16_t src_y ,
                      int16_t mask_x ,
                      int16_t mask_y ,
                      int16_t dst_x ,
                      int16_t dst_y ,
                      uint16_t width ,
                      uint16_t height );

int
xcb_render_trapezoids_sizeof (const void *_buffer ,
                              uint32_t traps_len );
xcb_void_cookie_t
xcb_render_trapezoids_checked (xcb_connection_t *c ,
                               uint8_t op ,
                               xcb_render_picture_t src ,
                               xcb_render_picture_t dst ,
                               xcb_render_pictformat_t mask_format ,
                               int16_t src_x ,
                               int16_t src_y ,
                               uint32_t traps_len ,
                               const xcb_render_trapezoid_t *traps );
xcb_void_cookie_t
xcb_render_trapezoids (xcb_connection_t *c ,
                       uint8_t op ,
                       xcb_render_picture_t src ,
                       xcb_render_picture_t dst ,
                       xcb_render_pictformat_t mask_format ,
                       int16_t src_x ,
                       int16_t src_y ,
                       uint32_t traps_len ,
                       const xcb_render_trapezoid_t *traps );

int
xcb_render_triangles_sizeof (const void *_buffer ,
                             uint32_t triangles_len );
xcb_void_cookie_t
xcb_render_triangles_checked (xcb_connection_t *c ,
                              uint8_t op ,
                              xcb_render_picture_t src ,
                              xcb_render_picture_t dst ,
                              xcb_render_pictformat_t mask_format ,
                              int16_t src_x ,
                              int16_t src_y ,
                              uint32_t triangles_len ,
                              const xcb_render_triangle_t *triangles );
xcb_void_cookie_t
xcb_render_triangles (xcb_connection_t *c ,
                      uint8_t op ,
                      xcb_render_picture_t src ,
                      xcb_render_picture_t dst ,
                      xcb_render_pictformat_t mask_format ,
                      int16_t src_x ,
                      int16_t src_y ,
                      uint32_t triangles_len ,
                      const xcb_render_triangle_t *triangles );

int
xcb_render_tri_strip_sizeof (const void *_buffer ,
                             uint32_t points_len );
xcb_void_cookie_t
xcb_render_tri_strip_checked (xcb_connection_t *c ,
                              uint8_t op ,
                              xcb_render_picture_t src ,
                              xcb_render_picture_t dst ,
                              xcb_render_pictformat_t mask_format ,
                              int16_t src_x ,
                              int16_t src_y ,
                              uint32_t points_len ,
                              const xcb_render_pointfix_t *points );
xcb_void_cookie_t
xcb_render_tri_strip (xcb_connection_t *c ,
                      uint8_t op ,
                      xcb_render_picture_t src ,
                      xcb_render_picture_t dst ,
                      xcb_render_pictformat_t mask_format ,
                      int16_t src_x ,
                      int16_t src_y ,
                      uint32_t points_len ,
                      const xcb_render_pointfix_t *points );

int
xcb_render_tri_fan_sizeof (const void *_buffer ,
                           uint32_t points_len );
xcb_void_cookie_t
xcb_render_tri_fan_checked (xcb_connection_t *c ,
                            uint8_t op ,
                            xcb_render_picture_t src ,
                            xcb_render_picture_t dst ,
                            xcb_render_pictformat_t mask_format ,
                            int16_t src_x ,
                            int16_t src_y ,
                            uint32_t points_len ,
                            const xcb_render_pointfix_t *points );
xcb_void_cookie_t
xcb_render_tri_fan (xcb_connection_t *c ,
                    uint8_t op ,
                    xcb_render_picture_t src ,
                    xcb_render_picture_t dst ,
                    xcb_render_pictformat_t mask_format ,
                    int16_t src_x ,
                    int16_t src_y ,
                    uint32_t points_len ,
                    const xcb_render_pointfix_t *points );
xcb_void_cookie_t
xcb_render_create_glyph_set_checked (xcb_connection_t *c ,
                                     xcb_render_glyphset_t gsid ,
                                     xcb_render_pictformat_t format );
xcb_void_cookie_t
xcb_render_create_glyph_set (xcb_connection_t *c ,
                             xcb_render_glyphset_t gsid ,
                             xcb_render_pictformat_t format );
xcb_void_cookie_t
xcb_render_reference_glyph_set_checked (xcb_connection_t *c ,
                                        xcb_render_glyphset_t gsid ,
                                        xcb_render_glyphset_t existing );
xcb_void_cookie_t
xcb_render_reference_glyph_set (xcb_connection_t *c ,
                                xcb_render_glyphset_t gsid ,
                                xcb_render_glyphset_t existing );
xcb_void_cookie_t
xcb_render_free_glyph_set_checked (xcb_connection_t *c ,
                                   xcb_render_glyphset_t glyphset );
xcb_void_cookie_t
xcb_render_free_glyph_set (xcb_connection_t *c ,
                           xcb_render_glyphset_t glyphset );

int
xcb_render_add_glyphs_sizeof (const void *_buffer ,
                              uint32_t data_len );
xcb_void_cookie_t
xcb_render_add_glyphs_checked (xcb_connection_t *c ,
                               xcb_render_glyphset_t glyphset ,
                               uint32_t glyphs_len ,
                               const uint32_t *glyphids ,
                               const xcb_render_glyphinfo_t *glyphs ,
                               uint32_t data_len ,
                               const uint8_t *data );
xcb_void_cookie_t
xcb_render_add_glyphs (xcb_connection_t *c ,
                       xcb_render_glyphset_t glyphset ,
                       uint32_t glyphs_len ,
                       const uint32_t *glyphids ,
                       const xcb_render_glyphinfo_t *glyphs ,
                       uint32_t data_len ,
                       const uint8_t *data );

int
xcb_render_free_glyphs_sizeof (const void *_buffer ,
                               uint32_t glyphs_len );
xcb_void_cookie_t
xcb_render_free_glyphs_checked (xcb_connection_t *c ,
                                xcb_render_glyphset_t glyphset ,
                                uint32_t glyphs_len ,
                                const xcb_render_glyph_t *glyphs );
xcb_void_cookie_t
xcb_render_free_glyphs (xcb_connection_t *c ,
                        xcb_render_glyphset_t glyphset ,
                        uint32_t glyphs_len ,
                        const xcb_render_glyph_t *glyphs );

int
xcb_render_composite_glyphs_8_sizeof (const void *_buffer ,
                                      uint32_t glyphcmds_len );
xcb_void_cookie_t
xcb_render_composite_glyphs_8_checked (xcb_connection_t *c ,
                                       uint8_t op ,
                                       xcb_render_picture_t src ,
                                       xcb_render_picture_t dst ,
                                       xcb_render_pictformat_t mask_format ,
                                       xcb_render_glyphset_t glyphset ,
                                       int16_t src_x ,
                                       int16_t src_y ,
                                       uint32_t glyphcmds_len ,
                                       const uint8_t *glyphcmds );
xcb_void_cookie_t
xcb_render_composite_glyphs_8 (xcb_connection_t *c ,
                               uint8_t op ,
                               xcb_render_picture_t src ,
                               xcb_render_picture_t dst ,
                               xcb_render_pictformat_t mask_format ,
                               xcb_render_glyphset_t glyphset ,
                               int16_t src_x ,
                               int16_t src_y ,
                               uint32_t glyphcmds_len ,
                               const uint8_t *glyphcmds );

int
xcb_render_composite_glyphs_16_sizeof (const void *_buffer ,
                                       uint32_t glyphcmds_len );
xcb_void_cookie_t
xcb_render_composite_glyphs_16_checked (xcb_connection_t *c ,
                                        uint8_t op ,
                                        xcb_render_picture_t src ,
                                        xcb_render_picture_t dst ,
                                        xcb_render_pictformat_t mask_format ,
                                        xcb_render_glyphset_t glyphset ,
                                        int16_t src_x ,
                                        int16_t src_y ,
                                        uint32_t glyphcmds_len ,
                                        const uint8_t *glyphcmds );
xcb_void_cookie_t
xcb_render_composite_glyphs_16 (xcb_connection_t *c ,
                                uint8_t op ,
                                xcb_render_picture_t src ,
                                xcb_render_picture_t dst ,
                                xcb_render_pictformat_t mask_format ,
                                xcb_render_glyphset_t glyphset ,
                                int16_t src_x ,
                                int16_t src_y ,
                                uint32_t glyphcmds_len ,
                                const uint8_t *glyphcmds );

int
xcb_render_composite_glyphs_32_sizeof (const void *_buffer ,
                                       uint32_t glyphcmds_len );
xcb_void_cookie_t
xcb_render_composite_glyphs_32_checked (xcb_connection_t *c ,
                                        uint8_t op ,
                                        xcb_render_picture_t src ,
                                        xcb_render_picture_t dst ,
                                        xcb_render_pictformat_t mask_format ,
                                        xcb_render_glyphset_t glyphset ,
                                        int16_t src_x ,
                                        int16_t src_y ,
                                        uint32_t glyphcmds_len ,
                                        const uint8_t *glyphcmds );
xcb_void_cookie_t
xcb_render_composite_glyphs_32 (xcb_connection_t *c ,
                                uint8_t op ,
                                xcb_render_picture_t src ,
                                xcb_render_picture_t dst ,
                                xcb_render_pictformat_t mask_format ,
                                xcb_render_glyphset_t glyphset ,
                                int16_t src_x ,
                                int16_t src_y ,
                                uint32_t glyphcmds_len ,
                                const uint8_t *glyphcmds );

int
xcb_render_fill_rectangles_sizeof (const void *_buffer ,
                                   uint32_t rects_len );
xcb_void_cookie_t
xcb_render_fill_rectangles_checked (xcb_connection_t *c ,
                                    uint8_t op ,
                                    xcb_render_picture_t dst ,
                                    xcb_render_color_t color ,
                                    uint32_t rects_len ,
                                    const xcb_rectangle_t *rects );
xcb_void_cookie_t
xcb_render_fill_rectangles (xcb_connection_t *c ,
                            uint8_t op ,
                            xcb_render_picture_t dst ,
                            xcb_render_color_t color ,
                            uint32_t rects_len ,
                            const xcb_rectangle_t *rects );
xcb_void_cookie_t
xcb_render_create_cursor_checked (xcb_connection_t *c ,
                                  xcb_cursor_t cid ,
                                  xcb_render_picture_t source ,
                                  uint16_t x ,
                                  uint16_t y );
xcb_void_cookie_t
xcb_render_create_cursor (xcb_connection_t *c ,
                          xcb_cursor_t cid ,
                          xcb_render_picture_t source ,
                          uint16_t x ,
                          uint16_t y );
void
xcb_render_transform_next (xcb_render_transform_iterator_t *i );
xcb_generic_iterator_t
xcb_render_transform_end (xcb_render_transform_iterator_t i );
xcb_void_cookie_t
xcb_render_set_picture_transform_checked (xcb_connection_t *c ,
                                          xcb_render_picture_t picture ,
                                          xcb_render_transform_t transform );
xcb_void_cookie_t
xcb_render_set_picture_transform (xcb_connection_t *c ,
                                  xcb_render_picture_t picture ,
                                  xcb_render_transform_t transform );

int
xcb_render_query_filters_sizeof (const void *_buffer );
xcb_render_query_filters_cookie_t
xcb_render_query_filters (xcb_connection_t *c ,
                          xcb_drawable_t drawable );
xcb_render_query_filters_cookie_t
xcb_render_query_filters_unchecked (xcb_connection_t *c ,
                                    xcb_drawable_t drawable );

uint16_t *
xcb_render_query_filters_aliases (const xcb_render_query_filters_reply_t *R );

int
xcb_render_query_filters_aliases_length (const xcb_render_query_filters_reply_t *R );

xcb_generic_iterator_t
xcb_render_query_filters_aliases_end (const xcb_render_query_filters_reply_t *R );

int
xcb_render_query_filters_filters_length (const xcb_render_query_filters_reply_t *R );

xcb_str_iterator_t
xcb_render_query_filters_filters_iterator (const xcb_render_query_filters_reply_t *R );
xcb_render_query_filters_reply_t *
xcb_render_query_filters_reply (xcb_connection_t *c ,
                                xcb_render_query_filters_cookie_t cookie ,
                                xcb_generic_error_t **e );

int
xcb_render_set_picture_filter_sizeof (const void *_buffer ,
                                      uint32_t values_len );
xcb_void_cookie_t
xcb_render_set_picture_filter_checked (xcb_connection_t *c ,
                                       xcb_render_picture_t picture ,
                                       uint16_t filter_len ,
                                       const char *filter ,
                                       uint32_t values_len ,
                                       const xcb_render_fixed_t *values );
xcb_void_cookie_t
xcb_render_set_picture_filter (xcb_connection_t *c ,
                               xcb_render_picture_t picture ,
                               uint16_t filter_len ,
                               const char *filter ,
                               uint32_t values_len ,
                               const xcb_render_fixed_t *values );
void
xcb_render_animcursorelt_next (xcb_render_animcursorelt_iterator_t *i );
xcb_generic_iterator_t
xcb_render_animcursorelt_end (xcb_render_animcursorelt_iterator_t i );

int
xcb_render_create_anim_cursor_sizeof (const void *_buffer ,
                                      uint32_t cursors_len );
xcb_void_cookie_t
xcb_render_create_anim_cursor_checked (xcb_connection_t *c ,
                                       xcb_cursor_t cid ,
                                       uint32_t cursors_len ,
                                       const xcb_render_animcursorelt_t *cursors );
xcb_void_cookie_t
xcb_render_create_anim_cursor (xcb_connection_t *c ,
                               xcb_cursor_t cid ,
                               uint32_t cursors_len ,
                               const xcb_render_animcursorelt_t *cursors );
void
xcb_render_spanfix_next (xcb_render_spanfix_iterator_t *i );
xcb_generic_iterator_t
xcb_render_spanfix_end (xcb_render_spanfix_iterator_t i );
void
xcb_render_trap_next (xcb_render_trap_iterator_t *i );
xcb_generic_iterator_t
xcb_render_trap_end (xcb_render_trap_iterator_t i );

int
xcb_render_add_traps_sizeof (const void *_buffer ,
                             uint32_t traps_len );
xcb_void_cookie_t
xcb_render_add_traps_checked (xcb_connection_t *c ,
                              xcb_render_picture_t picture ,
                              int16_t x_off ,
                              int16_t y_off ,
                              uint32_t traps_len ,
                              const xcb_render_trap_t *traps );
xcb_void_cookie_t
xcb_render_add_traps (xcb_connection_t *c ,
                      xcb_render_picture_t picture ,
                      int16_t x_off ,
                      int16_t y_off ,
                      uint32_t traps_len ,
                      const xcb_render_trap_t *traps );
xcb_void_cookie_t
xcb_render_create_solid_fill_checked (xcb_connection_t *c ,
                                      xcb_render_picture_t picture ,
                                      xcb_render_color_t color );
xcb_void_cookie_t
xcb_render_create_solid_fill (xcb_connection_t *c ,
                              xcb_render_picture_t picture ,
                              xcb_render_color_t color );

int
xcb_render_create_linear_gradient_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_render_create_linear_gradient_checked (xcb_connection_t *c ,
                                           xcb_render_picture_t picture ,
                                           xcb_render_pointfix_t p1 ,
                                           xcb_render_pointfix_t p2 ,
                                           uint32_t num_stops ,
                                           const xcb_render_fixed_t *stops ,
                                           const xcb_render_color_t *colors );
xcb_void_cookie_t
xcb_render_create_linear_gradient (xcb_connection_t *c ,
                                   xcb_render_picture_t picture ,
                                   xcb_render_pointfix_t p1 ,
                                   xcb_render_pointfix_t p2 ,
                                   uint32_t num_stops ,
                                   const xcb_render_fixed_t *stops ,
                                   const xcb_render_color_t *colors );

int
xcb_render_create_radial_gradient_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_render_create_radial_gradient_checked (xcb_connection_t *c ,
                                           xcb_render_picture_t picture ,
                                           xcb_render_pointfix_t inner ,
                                           xcb_render_pointfix_t outer ,
                                           xcb_render_fixed_t inner_radius ,
                                           xcb_render_fixed_t outer_radius ,
                                           uint32_t num_stops ,
                                           const xcb_render_fixed_t *stops ,
                                           const xcb_render_color_t *colors );
xcb_void_cookie_t
xcb_render_create_radial_gradient (xcb_connection_t *c ,
                                   xcb_render_picture_t picture ,
                                   xcb_render_pointfix_t inner ,
                                   xcb_render_pointfix_t outer ,
                                   xcb_render_fixed_t inner_radius ,
                                   xcb_render_fixed_t outer_radius ,
                                   uint32_t num_stops ,
                                   const xcb_render_fixed_t *stops ,
                                   const xcb_render_color_t *colors );

int
xcb_render_create_conical_gradient_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_render_create_conical_gradient_checked (xcb_connection_t *c ,
                                            xcb_render_picture_t picture ,
                                            xcb_render_pointfix_t center ,
                                            xcb_render_fixed_t angle ,
                                            uint32_t num_stops ,
                                            const xcb_render_fixed_t *stops ,
                                            const xcb_render_color_t *colors );
xcb_void_cookie_t
xcb_render_create_conical_gradient (xcb_connection_t *c ,
                                    xcb_render_picture_t picture ,
                                    xcb_render_pointfix_t center ,
                                    xcb_render_fixed_t angle ,
                                    uint32_t num_stops ,
                                    const xcb_render_fixed_t *stops ,
                                    const xcb_render_color_t *colors );
extern xcb_extension_t xcb_randr_id;

typedef uint32_t xcb_randr_mode_t;




typedef struct xcb_randr_mode_iterator_t {
    xcb_randr_mode_t *data;
    int rem;
    int index;
} xcb_randr_mode_iterator_t;

typedef uint32_t xcb_randr_crtc_t;




typedef struct xcb_randr_crtc_iterator_t {
    xcb_randr_crtc_t *data;
    int rem;
    int index;
} xcb_randr_crtc_iterator_t;

typedef uint32_t xcb_randr_output_t;




typedef struct xcb_randr_output_iterator_t {
    xcb_randr_output_t *data;
    int rem;
    int index;
} xcb_randr_output_iterator_t;

typedef uint32_t xcb_randr_provider_t;




typedef struct xcb_randr_provider_iterator_t {
    xcb_randr_provider_t *data;
    int rem;
    int index;
} xcb_randr_provider_iterator_t;







typedef struct xcb_randr_bad_output_error_t {
    uint8_t response_type;
    uint8_t error_code;
    uint16_t sequence;
} xcb_randr_bad_output_error_t;







typedef struct xcb_randr_bad_crtc_error_t {
    uint8_t response_type;
    uint8_t error_code;
    uint16_t sequence;
} xcb_randr_bad_crtc_error_t;







typedef struct xcb_randr_bad_mode_error_t {
    uint8_t response_type;
    uint8_t error_code;
    uint16_t sequence;
} xcb_randr_bad_mode_error_t;







typedef struct xcb_randr_bad_provider_error_t {
    uint8_t response_type;
    uint8_t error_code;
    uint16_t sequence;
} xcb_randr_bad_provider_error_t;

typedef enum xcb_randr_rotation_t {
    XCB_RANDR_ROTATION_ROTATE_0 = 1,
    XCB_RANDR_ROTATION_ROTATE_90 = 2,
    XCB_RANDR_ROTATION_ROTATE_180 = 4,
    XCB_RANDR_ROTATION_ROTATE_270 = 8,
    XCB_RANDR_ROTATION_REFLECT_X = 16,
    XCB_RANDR_ROTATION_REFLECT_Y = 32
} xcb_randr_rotation_t;




typedef struct xcb_randr_screen_size_t {
    uint16_t width;
    uint16_t height;
    uint16_t mwidth;
    uint16_t mheight;
} xcb_randr_screen_size_t;




typedef struct xcb_randr_screen_size_iterator_t {
    xcb_randr_screen_size_t *data;
    int rem;
    int index;
} xcb_randr_screen_size_iterator_t;




typedef struct xcb_randr_refresh_rates_t {
    uint16_t nRates;
} xcb_randr_refresh_rates_t;




typedef struct xcb_randr_refresh_rates_iterator_t {
    xcb_randr_refresh_rates_t *data;
    int rem;
    int index;
} xcb_randr_refresh_rates_iterator_t;




typedef struct xcb_randr_query_version_cookie_t {
    unsigned int sequence;
} xcb_randr_query_version_cookie_t;







typedef struct xcb_randr_query_version_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    uint32_t major_version;
    uint32_t minor_version;
} xcb_randr_query_version_request_t;




typedef struct xcb_randr_query_version_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint32_t major_version;
    uint32_t minor_version;
    uint8_t pad1[16];
} xcb_randr_query_version_reply_t;

typedef enum xcb_randr_set_config_t {
    XCB_RANDR_SET_CONFIG_SUCCESS = 0,
    XCB_RANDR_SET_CONFIG_INVALID_CONFIG_TIME = 1,
    XCB_RANDR_SET_CONFIG_INVALID_TIME = 2,
    XCB_RANDR_SET_CONFIG_FAILED = 3
} xcb_randr_set_config_t;




typedef struct xcb_randr_set_screen_config_cookie_t {
    unsigned int sequence;
} xcb_randr_set_screen_config_cookie_t;







typedef struct xcb_randr_set_screen_config_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_window_t window;
    xcb_timestamp_t timestamp;
    xcb_timestamp_t config_timestamp;
    uint16_t sizeID;
    uint16_t rotation;
    uint16_t rate;
    uint8_t pad0[2];
} xcb_randr_set_screen_config_request_t;




typedef struct xcb_randr_set_screen_config_reply_t {
    uint8_t response_type;
    uint8_t status;
    uint16_t sequence;
    uint32_t length;
    xcb_timestamp_t new_timestamp;
    xcb_timestamp_t config_timestamp;
    xcb_window_t root;
    uint16_t subpixel_order;
    uint8_t pad0[10];
} xcb_randr_set_screen_config_reply_t;

typedef enum xcb_randr_notify_mask_t {
    XCB_RANDR_NOTIFY_MASK_SCREEN_CHANGE = 1,
    XCB_RANDR_NOTIFY_MASK_CRTC_CHANGE = 2,
    XCB_RANDR_NOTIFY_MASK_OUTPUT_CHANGE = 4,
    XCB_RANDR_NOTIFY_MASK_OUTPUT_PROPERTY = 8,
    XCB_RANDR_NOTIFY_MASK_PROVIDER_CHANGE = 16,
    XCB_RANDR_NOTIFY_MASK_PROVIDER_PROPERTY = 32,
    XCB_RANDR_NOTIFY_MASK_RESOURCE_CHANGE = 64
} xcb_randr_notify_mask_t;







typedef struct xcb_randr_select_input_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_window_t window;
    uint16_t enable;
    uint8_t pad0[2];
} xcb_randr_select_input_request_t;




typedef struct xcb_randr_get_screen_info_cookie_t {
    unsigned int sequence;
} xcb_randr_get_screen_info_cookie_t;







typedef struct xcb_randr_get_screen_info_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_window_t window;
} xcb_randr_get_screen_info_request_t;




typedef struct xcb_randr_get_screen_info_reply_t {
    uint8_t response_type;
    uint8_t rotations;
    uint16_t sequence;
    uint32_t length;
    xcb_window_t root;
    xcb_timestamp_t timestamp;
    xcb_timestamp_t config_timestamp;
    uint16_t nSizes;
    uint16_t sizeID;
    uint16_t rotation;
    uint16_t rate;
    uint16_t nInfo;
    uint8_t pad0[2];
} xcb_randr_get_screen_info_reply_t;




typedef struct xcb_randr_get_screen_size_range_cookie_t {
    unsigned int sequence;
} xcb_randr_get_screen_size_range_cookie_t;







typedef struct xcb_randr_get_screen_size_range_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_window_t window;
} xcb_randr_get_screen_size_range_request_t;




typedef struct xcb_randr_get_screen_size_range_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t min_width;
    uint16_t min_height;
    uint16_t max_width;
    uint16_t max_height;
    uint8_t pad1[16];
} xcb_randr_get_screen_size_range_reply_t;







typedef struct xcb_randr_set_screen_size_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_window_t window;
    uint16_t width;
    uint16_t height;
    uint32_t mm_width;
    uint32_t mm_height;
} xcb_randr_set_screen_size_request_t;

typedef enum xcb_randr_mode_flag_t {
    XCB_RANDR_MODE_FLAG_HSYNC_POSITIVE = 1,
    XCB_RANDR_MODE_FLAG_HSYNC_NEGATIVE = 2,
    XCB_RANDR_MODE_FLAG_VSYNC_POSITIVE = 4,
    XCB_RANDR_MODE_FLAG_VSYNC_NEGATIVE = 8,
    XCB_RANDR_MODE_FLAG_INTERLACE = 16,
    XCB_RANDR_MODE_FLAG_DOUBLE_SCAN = 32,
    XCB_RANDR_MODE_FLAG_CSYNC = 64,
    XCB_RANDR_MODE_FLAG_CSYNC_POSITIVE = 128,
    XCB_RANDR_MODE_FLAG_CSYNC_NEGATIVE = 256,
    XCB_RANDR_MODE_FLAG_HSKEW_PRESENT = 512,
    XCB_RANDR_MODE_FLAG_BCAST = 1024,
    XCB_RANDR_MODE_FLAG_PIXEL_MULTIPLEX = 2048,
    XCB_RANDR_MODE_FLAG_DOUBLE_CLOCK = 4096,
    XCB_RANDR_MODE_FLAG_HALVE_CLOCK = 8192
} xcb_randr_mode_flag_t;




typedef struct xcb_randr_mode_info_t {
    uint32_t id;
    uint16_t width;
    uint16_t height;
    uint32_t dot_clock;
    uint16_t hsync_start;
    uint16_t hsync_end;
    uint16_t htotal;
    uint16_t hskew;
    uint16_t vsync_start;
    uint16_t vsync_end;
    uint16_t vtotal;
    uint16_t name_len;
    uint32_t mode_flags;
} xcb_randr_mode_info_t;




typedef struct xcb_randr_mode_info_iterator_t {
    xcb_randr_mode_info_t *data;
    int rem;
    int index;
} xcb_randr_mode_info_iterator_t;




typedef struct xcb_randr_get_screen_resources_cookie_t {
    unsigned int sequence;
} xcb_randr_get_screen_resources_cookie_t;







typedef struct xcb_randr_get_screen_resources_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_window_t window;
} xcb_randr_get_screen_resources_request_t;




typedef struct xcb_randr_get_screen_resources_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    xcb_timestamp_t timestamp;
    xcb_timestamp_t config_timestamp;
    uint16_t num_crtcs;
    uint16_t num_outputs;
    uint16_t num_modes;
    uint16_t names_len;
    uint8_t pad1[8];
} xcb_randr_get_screen_resources_reply_t;

typedef enum xcb_randr_connection_t {
    XCB_RANDR_CONNECTION_CONNECTED = 0,
    XCB_RANDR_CONNECTION_DISCONNECTED = 1,
    XCB_RANDR_CONNECTION_UNKNOWN = 2
} xcb_randr_connection_t;




typedef struct xcb_randr_get_output_info_cookie_t {
    unsigned int sequence;
} xcb_randr_get_output_info_cookie_t;







typedef struct xcb_randr_get_output_info_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_output_t output;
    xcb_timestamp_t config_timestamp;
} xcb_randr_get_output_info_request_t;




typedef struct xcb_randr_get_output_info_reply_t {
    uint8_t response_type;
    uint8_t status;
    uint16_t sequence;
    uint32_t length;
    xcb_timestamp_t timestamp;
    xcb_randr_crtc_t crtc;
    uint32_t mm_width;
    uint32_t mm_height;
    uint8_t connection;
    uint8_t subpixel_order;
    uint16_t num_crtcs;
    uint16_t num_modes;
    uint16_t num_preferred;
    uint16_t num_clones;
    uint16_t name_len;
} xcb_randr_get_output_info_reply_t;




typedef struct xcb_randr_list_output_properties_cookie_t {
    unsigned int sequence;
} xcb_randr_list_output_properties_cookie_t;







typedef struct xcb_randr_list_output_properties_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_output_t output;
} xcb_randr_list_output_properties_request_t;




typedef struct xcb_randr_list_output_properties_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t num_atoms;
    uint8_t pad1[22];
} xcb_randr_list_output_properties_reply_t;




typedef struct xcb_randr_query_output_property_cookie_t {
    unsigned int sequence;
} xcb_randr_query_output_property_cookie_t;







typedef struct xcb_randr_query_output_property_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_output_t output;
    xcb_atom_t property;
} xcb_randr_query_output_property_request_t;




typedef struct xcb_randr_query_output_property_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint8_t pending;
    uint8_t range;
    uint8_t immutable;
    uint8_t pad1[21];
} xcb_randr_query_output_property_reply_t;







typedef struct xcb_randr_configure_output_property_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_output_t output;
    xcb_atom_t property;
    uint8_t pending;
    uint8_t range;
    uint8_t pad0[2];
} xcb_randr_configure_output_property_request_t;







typedef struct xcb_randr_change_output_property_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_output_t output;
    xcb_atom_t property;
    xcb_atom_t type;
    uint8_t format;
    uint8_t mode;
    uint8_t pad0[2];
    uint32_t num_units;
} xcb_randr_change_output_property_request_t;







typedef struct xcb_randr_delete_output_property_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_output_t output;
    xcb_atom_t property;
} xcb_randr_delete_output_property_request_t;




typedef struct xcb_randr_get_output_property_cookie_t {
    unsigned int sequence;
} xcb_randr_get_output_property_cookie_t;







typedef struct xcb_randr_get_output_property_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_output_t output;
    xcb_atom_t property;
    xcb_atom_t type;
    uint32_t long_offset;
    uint32_t long_length;
    uint8_t _delete;
    uint8_t pending;
    uint8_t pad0[2];
} xcb_randr_get_output_property_request_t;




typedef struct xcb_randr_get_output_property_reply_t {
    uint8_t response_type;
    uint8_t format;
    uint16_t sequence;
    uint32_t length;
    xcb_atom_t type;
    uint32_t bytes_after;
    uint32_t num_items;
    uint8_t pad0[12];
} xcb_randr_get_output_property_reply_t;




typedef struct xcb_randr_create_mode_cookie_t {
    unsigned int sequence;
} xcb_randr_create_mode_cookie_t;







typedef struct xcb_randr_create_mode_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_window_t window;
    xcb_randr_mode_info_t mode_info;
} xcb_randr_create_mode_request_t;




typedef struct xcb_randr_create_mode_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    xcb_randr_mode_t mode;
    uint8_t pad1[20];
} xcb_randr_create_mode_reply_t;







typedef struct xcb_randr_destroy_mode_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_mode_t mode;
} xcb_randr_destroy_mode_request_t;







typedef struct xcb_randr_add_output_mode_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_output_t output;
    xcb_randr_mode_t mode;
} xcb_randr_add_output_mode_request_t;







typedef struct xcb_randr_delete_output_mode_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_output_t output;
    xcb_randr_mode_t mode;
} xcb_randr_delete_output_mode_request_t;




typedef struct xcb_randr_get_crtc_info_cookie_t {
    unsigned int sequence;
} xcb_randr_get_crtc_info_cookie_t;







typedef struct xcb_randr_get_crtc_info_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_crtc_t crtc;
    xcb_timestamp_t config_timestamp;
} xcb_randr_get_crtc_info_request_t;




typedef struct xcb_randr_get_crtc_info_reply_t {
    uint8_t response_type;
    uint8_t status;
    uint16_t sequence;
    uint32_t length;
    xcb_timestamp_t timestamp;
    int16_t x;
    int16_t y;
    uint16_t width;
    uint16_t height;
    xcb_randr_mode_t mode;
    uint16_t rotation;
    uint16_t rotations;
    uint16_t num_outputs;
    uint16_t num_possible_outputs;
} xcb_randr_get_crtc_info_reply_t;




typedef struct xcb_randr_set_crtc_config_cookie_t {
    unsigned int sequence;
} xcb_randr_set_crtc_config_cookie_t;







typedef struct xcb_randr_set_crtc_config_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_crtc_t crtc;
    xcb_timestamp_t timestamp;
    xcb_timestamp_t config_timestamp;
    int16_t x;
    int16_t y;
    xcb_randr_mode_t mode;
    uint16_t rotation;
    uint8_t pad0[2];
} xcb_randr_set_crtc_config_request_t;




typedef struct xcb_randr_set_crtc_config_reply_t {
    uint8_t response_type;
    uint8_t status;
    uint16_t sequence;
    uint32_t length;
    xcb_timestamp_t timestamp;
    uint8_t pad0[20];
} xcb_randr_set_crtc_config_reply_t;




typedef struct xcb_randr_get_crtc_gamma_size_cookie_t {
    unsigned int sequence;
} xcb_randr_get_crtc_gamma_size_cookie_t;







typedef struct xcb_randr_get_crtc_gamma_size_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_crtc_t crtc;
} xcb_randr_get_crtc_gamma_size_request_t;




typedef struct xcb_randr_get_crtc_gamma_size_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t size;
    uint8_t pad1[22];
} xcb_randr_get_crtc_gamma_size_reply_t;




typedef struct xcb_randr_get_crtc_gamma_cookie_t {
    unsigned int sequence;
} xcb_randr_get_crtc_gamma_cookie_t;







typedef struct xcb_randr_get_crtc_gamma_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_crtc_t crtc;
} xcb_randr_get_crtc_gamma_request_t;




typedef struct xcb_randr_get_crtc_gamma_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t size;
    uint8_t pad1[22];
} xcb_randr_get_crtc_gamma_reply_t;







typedef struct xcb_randr_set_crtc_gamma_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_crtc_t crtc;
    uint16_t size;
    uint8_t pad0[2];
} xcb_randr_set_crtc_gamma_request_t;




typedef struct xcb_randr_get_screen_resources_current_cookie_t {
    unsigned int sequence;
} xcb_randr_get_screen_resources_current_cookie_t;







typedef struct xcb_randr_get_screen_resources_current_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_window_t window;
} xcb_randr_get_screen_resources_current_request_t;




typedef struct xcb_randr_get_screen_resources_current_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    xcb_timestamp_t timestamp;
    xcb_timestamp_t config_timestamp;
    uint16_t num_crtcs;
    uint16_t num_outputs;
    uint16_t num_modes;
    uint16_t names_len;
    uint8_t pad1[8];
} xcb_randr_get_screen_resources_current_reply_t;

typedef enum xcb_randr_transform_t {
    XCB_RANDR_TRANSFORM_UNIT = 1,
    XCB_RANDR_TRANSFORM_SCALE_UP = 2,
    XCB_RANDR_TRANSFORM_SCALE_DOWN = 4,
    XCB_RANDR_TRANSFORM_PROJECTIVE = 8
} xcb_randr_transform_t;







typedef struct xcb_randr_set_crtc_transform_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_crtc_t crtc;
    xcb_render_transform_t transform;
    uint16_t filter_len;
    uint8_t pad0[2];
} xcb_randr_set_crtc_transform_request_t;




typedef struct xcb_randr_get_crtc_transform_cookie_t {
    unsigned int sequence;
} xcb_randr_get_crtc_transform_cookie_t;







typedef struct xcb_randr_get_crtc_transform_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_crtc_t crtc;
} xcb_randr_get_crtc_transform_request_t;




typedef struct xcb_randr_get_crtc_transform_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    xcb_render_transform_t pending_transform;
    uint8_t has_transforms;
    uint8_t pad1[3];
    xcb_render_transform_t current_transform;
    uint8_t pad2[4];
    uint16_t pending_len;
    uint16_t pending_nparams;
    uint16_t current_len;
    uint16_t current_nparams;
} xcb_randr_get_crtc_transform_reply_t;




typedef struct xcb_randr_get_panning_cookie_t {
    unsigned int sequence;
} xcb_randr_get_panning_cookie_t;







typedef struct xcb_randr_get_panning_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_crtc_t crtc;
} xcb_randr_get_panning_request_t;




typedef struct xcb_randr_get_panning_reply_t {
    uint8_t response_type;
    uint8_t status;
    uint16_t sequence;
    uint32_t length;
    xcb_timestamp_t timestamp;
    uint16_t left;
    uint16_t top;
    uint16_t width;
    uint16_t height;
    uint16_t track_left;
    uint16_t track_top;
    uint16_t track_width;
    uint16_t track_height;
    int16_t border_left;
    int16_t border_top;
    int16_t border_right;
    int16_t border_bottom;
} xcb_randr_get_panning_reply_t;




typedef struct xcb_randr_set_panning_cookie_t {
    unsigned int sequence;
} xcb_randr_set_panning_cookie_t;







typedef struct xcb_randr_set_panning_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_crtc_t crtc;
    xcb_timestamp_t timestamp;
    uint16_t left;
    uint16_t top;
    uint16_t width;
    uint16_t height;
    uint16_t track_left;
    uint16_t track_top;
    uint16_t track_width;
    uint16_t track_height;
    int16_t border_left;
    int16_t border_top;
    int16_t border_right;
    int16_t border_bottom;
} xcb_randr_set_panning_request_t;




typedef struct xcb_randr_set_panning_reply_t {
    uint8_t response_type;
    uint8_t status;
    uint16_t sequence;
    uint32_t length;
    xcb_timestamp_t timestamp;
} xcb_randr_set_panning_reply_t;







typedef struct xcb_randr_set_output_primary_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_window_t window;
    xcb_randr_output_t output;
} xcb_randr_set_output_primary_request_t;




typedef struct xcb_randr_get_output_primary_cookie_t {
    unsigned int sequence;
} xcb_randr_get_output_primary_cookie_t;







typedef struct xcb_randr_get_output_primary_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_window_t window;
} xcb_randr_get_output_primary_request_t;




typedef struct xcb_randr_get_output_primary_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    xcb_randr_output_t output;
} xcb_randr_get_output_primary_reply_t;




typedef struct xcb_randr_get_providers_cookie_t {
    unsigned int sequence;
} xcb_randr_get_providers_cookie_t;







typedef struct xcb_randr_get_providers_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_window_t window;
} xcb_randr_get_providers_request_t;




typedef struct xcb_randr_get_providers_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    xcb_timestamp_t timestamp;
    uint16_t num_providers;
    uint8_t pad1[18];
} xcb_randr_get_providers_reply_t;

typedef enum xcb_randr_provider_capability_t {
    XCB_RANDR_PROVIDER_CAPABILITY_SOURCE_OUTPUT = 1,
    XCB_RANDR_PROVIDER_CAPABILITY_SINK_OUTPUT = 2,
    XCB_RANDR_PROVIDER_CAPABILITY_SOURCE_OFFLOAD = 4,
    XCB_RANDR_PROVIDER_CAPABILITY_SINK_OFFLOAD = 8
} xcb_randr_provider_capability_t;




typedef struct xcb_randr_get_provider_info_cookie_t {
    unsigned int sequence;
} xcb_randr_get_provider_info_cookie_t;







typedef struct xcb_randr_get_provider_info_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_provider_t provider;
    xcb_timestamp_t config_timestamp;
} xcb_randr_get_provider_info_request_t;




typedef struct xcb_randr_get_provider_info_reply_t {
    uint8_t response_type;
    uint8_t status;
    uint16_t sequence;
    uint32_t length;
    xcb_timestamp_t timestamp;
    uint32_t capabilities;
    uint16_t num_crtcs;
    uint16_t num_outputs;
    uint16_t num_associated_providers;
    uint16_t name_len;
    uint8_t pad0[8];
} xcb_randr_get_provider_info_reply_t;







typedef struct xcb_randr_set_provider_offload_sink_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_provider_t provider;
    xcb_randr_provider_t sink_provider;
    xcb_timestamp_t config_timestamp;
} xcb_randr_set_provider_offload_sink_request_t;







typedef struct xcb_randr_set_provider_output_source_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_provider_t provider;
    xcb_randr_provider_t source_provider;
    xcb_timestamp_t config_timestamp;
} xcb_randr_set_provider_output_source_request_t;




typedef struct xcb_randr_list_provider_properties_cookie_t {
    unsigned int sequence;
} xcb_randr_list_provider_properties_cookie_t;







typedef struct xcb_randr_list_provider_properties_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_provider_t provider;
} xcb_randr_list_provider_properties_request_t;




typedef struct xcb_randr_list_provider_properties_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t num_atoms;
    uint8_t pad1[22];
} xcb_randr_list_provider_properties_reply_t;




typedef struct xcb_randr_query_provider_property_cookie_t {
    unsigned int sequence;
} xcb_randr_query_provider_property_cookie_t;







typedef struct xcb_randr_query_provider_property_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_provider_t provider;
    xcb_atom_t property;
} xcb_randr_query_provider_property_request_t;




typedef struct xcb_randr_query_provider_property_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint8_t pending;
    uint8_t range;
    uint8_t immutable;
    uint8_t pad1[21];
} xcb_randr_query_provider_property_reply_t;







typedef struct xcb_randr_configure_provider_property_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_provider_t provider;
    xcb_atom_t property;
    uint8_t pending;
    uint8_t range;
    uint8_t pad0[2];
} xcb_randr_configure_provider_property_request_t;







typedef struct xcb_randr_change_provider_property_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_provider_t provider;
    xcb_atom_t property;
    xcb_atom_t type;
    uint8_t format;
    uint8_t mode;
    uint8_t pad0[2];
    uint32_t num_items;
} xcb_randr_change_provider_property_request_t;







typedef struct xcb_randr_delete_provider_property_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_provider_t provider;
    xcb_atom_t property;
} xcb_randr_delete_provider_property_request_t;




typedef struct xcb_randr_get_provider_property_cookie_t {
    unsigned int sequence;
} xcb_randr_get_provider_property_cookie_t;







typedef struct xcb_randr_get_provider_property_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_randr_provider_t provider;
    xcb_atom_t property;
    xcb_atom_t type;
    uint32_t long_offset;
    uint32_t long_length;
    uint8_t _delete;
    uint8_t pending;
    uint8_t pad0[2];
} xcb_randr_get_provider_property_request_t;




typedef struct xcb_randr_get_provider_property_reply_t {
    uint8_t response_type;
    uint8_t format;
    uint16_t sequence;
    uint32_t length;
    xcb_atom_t type;
    uint32_t bytes_after;
    uint32_t num_items;
    uint8_t pad0[12];
} xcb_randr_get_provider_property_reply_t;







typedef struct xcb_randr_screen_change_notify_event_t {
    uint8_t response_type;
    uint8_t rotation;
    uint16_t sequence;
    xcb_timestamp_t timestamp;
    xcb_timestamp_t config_timestamp;
    xcb_window_t root;
    xcb_window_t request_window;
    uint16_t sizeID;
    uint16_t subpixel_order;
    uint16_t width;
    uint16_t height;
    uint16_t mwidth;
    uint16_t mheight;
} xcb_randr_screen_change_notify_event_t;

typedef enum xcb_randr_notify_t {
    XCB_RANDR_NOTIFY_CRTC_CHANGE = 0,
    XCB_RANDR_NOTIFY_OUTPUT_CHANGE = 1,
    XCB_RANDR_NOTIFY_OUTPUT_PROPERTY = 2,
    XCB_RANDR_NOTIFY_PROVIDER_CHANGE = 3,
    XCB_RANDR_NOTIFY_PROVIDER_PROPERTY = 4,
    XCB_RANDR_NOTIFY_RESOURCE_CHANGE = 5
} xcb_randr_notify_t;




typedef struct xcb_randr_crtc_change_t {
    xcb_timestamp_t timestamp;
    xcb_window_t window;
    xcb_randr_crtc_t crtc;
    xcb_randr_mode_t mode;
    uint16_t rotation;
    uint8_t pad0[2];
    int16_t x;
    int16_t y;
    uint16_t width;
    uint16_t height;
} xcb_randr_crtc_change_t;




typedef struct xcb_randr_crtc_change_iterator_t {
    xcb_randr_crtc_change_t *data;
    int rem;
    int index;
} xcb_randr_crtc_change_iterator_t;




typedef struct xcb_randr_output_change_t {
    xcb_timestamp_t timestamp;
    xcb_timestamp_t config_timestamp;
    xcb_window_t window;
    xcb_randr_output_t output;
    xcb_randr_crtc_t crtc;
    xcb_randr_mode_t mode;
    uint16_t rotation;
    uint8_t connection;
    uint8_t subpixel_order;
} xcb_randr_output_change_t;




typedef struct xcb_randr_output_change_iterator_t {
    xcb_randr_output_change_t *data;
    int rem;
    int index;
} xcb_randr_output_change_iterator_t;




typedef struct xcb_randr_output_property_t {
    xcb_window_t window;
    xcb_randr_output_t output;
    xcb_atom_t atom;
    xcb_timestamp_t timestamp;
    uint8_t status;
    uint8_t pad0[11];
} xcb_randr_output_property_t;




typedef struct xcb_randr_output_property_iterator_t {
    xcb_randr_output_property_t *data;
    int rem;
    int index;
} xcb_randr_output_property_iterator_t;




typedef struct xcb_randr_provider_change_t {
    xcb_timestamp_t timestamp;
    xcb_window_t window;
    xcb_randr_provider_t provider;
    uint8_t pad0[16];
} xcb_randr_provider_change_t;




typedef struct xcb_randr_provider_change_iterator_t {
    xcb_randr_provider_change_t *data;
    int rem;
    int index;
} xcb_randr_provider_change_iterator_t;




typedef struct xcb_randr_provider_property_t {
    xcb_window_t window;
    xcb_randr_provider_t provider;
    xcb_atom_t atom;
    xcb_timestamp_t timestamp;
    uint8_t state;
    uint8_t pad0[11];
} xcb_randr_provider_property_t;




typedef struct xcb_randr_provider_property_iterator_t {
    xcb_randr_provider_property_t *data;
    int rem;
    int index;
} xcb_randr_provider_property_iterator_t;




typedef struct xcb_randr_resource_change_t {
    xcb_timestamp_t timestamp;
    xcb_window_t window;
    uint8_t pad0[20];
} xcb_randr_resource_change_t;




typedef struct xcb_randr_resource_change_iterator_t {
    xcb_randr_resource_change_t *data;
    int rem;
    int index;
} xcb_randr_resource_change_iterator_t;




typedef union xcb_randr_notify_data_t {
    xcb_randr_crtc_change_t cc;
    xcb_randr_output_change_t oc;
    xcb_randr_output_property_t op;
    xcb_randr_provider_change_t pc;
    xcb_randr_provider_property_t pp;
    xcb_randr_resource_change_t rc;
} xcb_randr_notify_data_t;




typedef struct xcb_randr_notify_data_iterator_t {
    xcb_randr_notify_data_t *data;
    int rem;
    int index;
} xcb_randr_notify_data_iterator_t;







typedef struct xcb_randr_notify_event_t {
    uint8_t response_type;
    uint8_t subCode;
    uint16_t sequence;
    xcb_randr_notify_data_t u;
} xcb_randr_notify_event_t;
void
xcb_randr_mode_next (xcb_randr_mode_iterator_t *i );
xcb_generic_iterator_t
xcb_randr_mode_end (xcb_randr_mode_iterator_t i );
void
xcb_randr_crtc_next (xcb_randr_crtc_iterator_t *i );
xcb_generic_iterator_t
xcb_randr_crtc_end (xcb_randr_crtc_iterator_t i );
void
xcb_randr_output_next (xcb_randr_output_iterator_t *i );
xcb_generic_iterator_t
xcb_randr_output_end (xcb_randr_output_iterator_t i );
void
xcb_randr_provider_next (xcb_randr_provider_iterator_t *i );
xcb_generic_iterator_t
xcb_randr_provider_end (xcb_randr_provider_iterator_t i );
void
xcb_randr_screen_size_next (xcb_randr_screen_size_iterator_t *i );
xcb_generic_iterator_t
xcb_randr_screen_size_end (xcb_randr_screen_size_iterator_t i );

int
xcb_randr_refresh_rates_sizeof (const void *_buffer );

uint16_t *
xcb_randr_refresh_rates_rates (const xcb_randr_refresh_rates_t *R );

int
xcb_randr_refresh_rates_rates_length (const xcb_randr_refresh_rates_t *R );

xcb_generic_iterator_t
xcb_randr_refresh_rates_rates_end (const xcb_randr_refresh_rates_t *R );
void
xcb_randr_refresh_rates_next (xcb_randr_refresh_rates_iterator_t *i );
xcb_generic_iterator_t
xcb_randr_refresh_rates_end (xcb_randr_refresh_rates_iterator_t i );
xcb_randr_query_version_cookie_t
xcb_randr_query_version (xcb_connection_t *c ,
                         uint32_t major_version ,
                         uint32_t minor_version );
xcb_randr_query_version_cookie_t
xcb_randr_query_version_unchecked (xcb_connection_t *c ,
                                   uint32_t major_version ,
                                   uint32_t minor_version );
xcb_randr_query_version_reply_t *
xcb_randr_query_version_reply (xcb_connection_t *c ,
                               xcb_randr_query_version_cookie_t cookie ,
                               xcb_generic_error_t **e );
xcb_randr_set_screen_config_cookie_t
xcb_randr_set_screen_config (xcb_connection_t *c ,
                             xcb_window_t window ,
                             xcb_timestamp_t timestamp ,
                             xcb_timestamp_t config_timestamp ,
                             uint16_t sizeID ,
                             uint16_t rotation ,
                             uint16_t rate );
xcb_randr_set_screen_config_cookie_t
xcb_randr_set_screen_config_unchecked (xcb_connection_t *c ,
                                       xcb_window_t window ,
                                       xcb_timestamp_t timestamp ,
                                       xcb_timestamp_t config_timestamp ,
                                       uint16_t sizeID ,
                                       uint16_t rotation ,
                                       uint16_t rate );
xcb_randr_set_screen_config_reply_t *
xcb_randr_set_screen_config_reply (xcb_connection_t *c ,
                                   xcb_randr_set_screen_config_cookie_t cookie ,
                                   xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_randr_select_input_checked (xcb_connection_t *c ,
                                xcb_window_t window ,
                                uint16_t enable );
xcb_void_cookie_t
xcb_randr_select_input (xcb_connection_t *c ,
                        xcb_window_t window ,
                        uint16_t enable );

int
xcb_randr_get_screen_info_sizeof (const void *_buffer );
xcb_randr_get_screen_info_cookie_t
xcb_randr_get_screen_info (xcb_connection_t *c ,
                           xcb_window_t window );
xcb_randr_get_screen_info_cookie_t
xcb_randr_get_screen_info_unchecked (xcb_connection_t *c ,
                                     xcb_window_t window );

xcb_randr_screen_size_t *
xcb_randr_get_screen_info_sizes (const xcb_randr_get_screen_info_reply_t *R );

int
xcb_randr_get_screen_info_sizes_length (const xcb_randr_get_screen_info_reply_t *R );

xcb_randr_screen_size_iterator_t
xcb_randr_get_screen_info_sizes_iterator (const xcb_randr_get_screen_info_reply_t *R );

int
xcb_randr_get_screen_info_rates_length (const xcb_randr_get_screen_info_reply_t *R );

xcb_randr_refresh_rates_iterator_t
xcb_randr_get_screen_info_rates_iterator (const xcb_randr_get_screen_info_reply_t *R );
xcb_randr_get_screen_info_reply_t *
xcb_randr_get_screen_info_reply (xcb_connection_t *c ,
                                 xcb_randr_get_screen_info_cookie_t cookie ,
                                 xcb_generic_error_t **e );
xcb_randr_get_screen_size_range_cookie_t
xcb_randr_get_screen_size_range (xcb_connection_t *c ,
                                 xcb_window_t window );
xcb_randr_get_screen_size_range_cookie_t
xcb_randr_get_screen_size_range_unchecked (xcb_connection_t *c ,
                                           xcb_window_t window );
xcb_randr_get_screen_size_range_reply_t *
xcb_randr_get_screen_size_range_reply (xcb_connection_t *c ,
                                       xcb_randr_get_screen_size_range_cookie_t cookie ,
                                       xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_randr_set_screen_size_checked (xcb_connection_t *c ,
                                   xcb_window_t window ,
                                   uint16_t width ,
                                   uint16_t height ,
                                   uint32_t mm_width ,
                                   uint32_t mm_height );
xcb_void_cookie_t
xcb_randr_set_screen_size (xcb_connection_t *c ,
                           xcb_window_t window ,
                           uint16_t width ,
                           uint16_t height ,
                           uint32_t mm_width ,
                           uint32_t mm_height );
void
xcb_randr_mode_info_next (xcb_randr_mode_info_iterator_t *i );
xcb_generic_iterator_t
xcb_randr_mode_info_end (xcb_randr_mode_info_iterator_t i );

int
xcb_randr_get_screen_resources_sizeof (const void *_buffer );
xcb_randr_get_screen_resources_cookie_t
xcb_randr_get_screen_resources (xcb_connection_t *c ,
                                xcb_window_t window );
xcb_randr_get_screen_resources_cookie_t
xcb_randr_get_screen_resources_unchecked (xcb_connection_t *c ,
                                          xcb_window_t window );

xcb_randr_crtc_t *
xcb_randr_get_screen_resources_crtcs (const xcb_randr_get_screen_resources_reply_t *R );

int
xcb_randr_get_screen_resources_crtcs_length (const xcb_randr_get_screen_resources_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_screen_resources_crtcs_end (const xcb_randr_get_screen_resources_reply_t *R );

xcb_randr_output_t *
xcb_randr_get_screen_resources_outputs (const xcb_randr_get_screen_resources_reply_t *R );

int
xcb_randr_get_screen_resources_outputs_length (const xcb_randr_get_screen_resources_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_screen_resources_outputs_end (const xcb_randr_get_screen_resources_reply_t *R );

xcb_randr_mode_info_t *
xcb_randr_get_screen_resources_modes (const xcb_randr_get_screen_resources_reply_t *R );

int
xcb_randr_get_screen_resources_modes_length (const xcb_randr_get_screen_resources_reply_t *R );

xcb_randr_mode_info_iterator_t
xcb_randr_get_screen_resources_modes_iterator (const xcb_randr_get_screen_resources_reply_t *R );

uint8_t *
xcb_randr_get_screen_resources_names (const xcb_randr_get_screen_resources_reply_t *R );

int
xcb_randr_get_screen_resources_names_length (const xcb_randr_get_screen_resources_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_screen_resources_names_end (const xcb_randr_get_screen_resources_reply_t *R );
xcb_randr_get_screen_resources_reply_t *
xcb_randr_get_screen_resources_reply (xcb_connection_t *c ,
                                      xcb_randr_get_screen_resources_cookie_t cookie ,
                                      xcb_generic_error_t **e );

int
xcb_randr_get_output_info_sizeof (const void *_buffer );
xcb_randr_get_output_info_cookie_t
xcb_randr_get_output_info (xcb_connection_t *c ,
                           xcb_randr_output_t output ,
                           xcb_timestamp_t config_timestamp );
xcb_randr_get_output_info_cookie_t
xcb_randr_get_output_info_unchecked (xcb_connection_t *c ,
                                     xcb_randr_output_t output ,
                                     xcb_timestamp_t config_timestamp );

xcb_randr_crtc_t *
xcb_randr_get_output_info_crtcs (const xcb_randr_get_output_info_reply_t *R );

int
xcb_randr_get_output_info_crtcs_length (const xcb_randr_get_output_info_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_output_info_crtcs_end (const xcb_randr_get_output_info_reply_t *R );

xcb_randr_mode_t *
xcb_randr_get_output_info_modes (const xcb_randr_get_output_info_reply_t *R );

int
xcb_randr_get_output_info_modes_length (const xcb_randr_get_output_info_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_output_info_modes_end (const xcb_randr_get_output_info_reply_t *R );

xcb_randr_output_t *
xcb_randr_get_output_info_clones (const xcb_randr_get_output_info_reply_t *R );

int
xcb_randr_get_output_info_clones_length (const xcb_randr_get_output_info_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_output_info_clones_end (const xcb_randr_get_output_info_reply_t *R );

uint8_t *
xcb_randr_get_output_info_name (const xcb_randr_get_output_info_reply_t *R );

int
xcb_randr_get_output_info_name_length (const xcb_randr_get_output_info_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_output_info_name_end (const xcb_randr_get_output_info_reply_t *R );
xcb_randr_get_output_info_reply_t *
xcb_randr_get_output_info_reply (xcb_connection_t *c ,
                                 xcb_randr_get_output_info_cookie_t cookie ,
                                 xcb_generic_error_t **e );

int
xcb_randr_list_output_properties_sizeof (const void *_buffer );
xcb_randr_list_output_properties_cookie_t
xcb_randr_list_output_properties (xcb_connection_t *c ,
                                  xcb_randr_output_t output );
xcb_randr_list_output_properties_cookie_t
xcb_randr_list_output_properties_unchecked (xcb_connection_t *c ,
                                            xcb_randr_output_t output );

xcb_atom_t *
xcb_randr_list_output_properties_atoms (const xcb_randr_list_output_properties_reply_t *R );

int
xcb_randr_list_output_properties_atoms_length (const xcb_randr_list_output_properties_reply_t *R );

xcb_generic_iterator_t
xcb_randr_list_output_properties_atoms_end (const xcb_randr_list_output_properties_reply_t *R );
xcb_randr_list_output_properties_reply_t *
xcb_randr_list_output_properties_reply (xcb_connection_t *c ,
                                        xcb_randr_list_output_properties_cookie_t cookie ,
                                        xcb_generic_error_t **e );

int
xcb_randr_query_output_property_sizeof (const void *_buffer );
xcb_randr_query_output_property_cookie_t
xcb_randr_query_output_property (xcb_connection_t *c ,
                                 xcb_randr_output_t output ,
                                 xcb_atom_t property );
xcb_randr_query_output_property_cookie_t
xcb_randr_query_output_property_unchecked (xcb_connection_t *c ,
                                           xcb_randr_output_t output ,
                                           xcb_atom_t property );

int32_t *
xcb_randr_query_output_property_valid_values (const xcb_randr_query_output_property_reply_t *R );

int
xcb_randr_query_output_property_valid_values_length (const xcb_randr_query_output_property_reply_t *R );

xcb_generic_iterator_t
xcb_randr_query_output_property_valid_values_end (const xcb_randr_query_output_property_reply_t *R );
xcb_randr_query_output_property_reply_t *
xcb_randr_query_output_property_reply (xcb_connection_t *c ,
                                       xcb_randr_query_output_property_cookie_t cookie ,
                                       xcb_generic_error_t **e );

int
xcb_randr_configure_output_property_sizeof (const void *_buffer ,
                                            uint32_t values_len );
xcb_void_cookie_t
xcb_randr_configure_output_property_checked (xcb_connection_t *c ,
                                             xcb_randr_output_t output ,
                                             xcb_atom_t property ,
                                             uint8_t pending ,
                                             uint8_t range ,
                                             uint32_t values_len ,
                                             const int32_t *values );
xcb_void_cookie_t
xcb_randr_configure_output_property (xcb_connection_t *c ,
                                     xcb_randr_output_t output ,
                                     xcb_atom_t property ,
                                     uint8_t pending ,
                                     uint8_t range ,
                                     uint32_t values_len ,
                                     const int32_t *values );

int
xcb_randr_change_output_property_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_randr_change_output_property_checked (xcb_connection_t *c ,
                                          xcb_randr_output_t output ,
                                          xcb_atom_t property ,
                                          xcb_atom_t type ,
                                          uint8_t format ,
                                          uint8_t mode ,
                                          uint32_t num_units ,
                                          const void *data );
xcb_void_cookie_t
xcb_randr_change_output_property (xcb_connection_t *c ,
                                  xcb_randr_output_t output ,
                                  xcb_atom_t property ,
                                  xcb_atom_t type ,
                                  uint8_t format ,
                                  uint8_t mode ,
                                  uint32_t num_units ,
                                  const void *data );
xcb_void_cookie_t
xcb_randr_delete_output_property_checked (xcb_connection_t *c ,
                                          xcb_randr_output_t output ,
                                          xcb_atom_t property );
xcb_void_cookie_t
xcb_randr_delete_output_property (xcb_connection_t *c ,
                                  xcb_randr_output_t output ,
                                  xcb_atom_t property );

int
xcb_randr_get_output_property_sizeof (const void *_buffer );
xcb_randr_get_output_property_cookie_t
xcb_randr_get_output_property (xcb_connection_t *c ,
                               xcb_randr_output_t output ,
                               xcb_atom_t property ,
                               xcb_atom_t type ,
                               uint32_t long_offset ,
                               uint32_t long_length ,
                               uint8_t _delete ,
                               uint8_t pending );
xcb_randr_get_output_property_cookie_t
xcb_randr_get_output_property_unchecked (xcb_connection_t *c ,
                                         xcb_randr_output_t output ,
                                         xcb_atom_t property ,
                                         xcb_atom_t type ,
                                         uint32_t long_offset ,
                                         uint32_t long_length ,
                                         uint8_t _delete ,
                                         uint8_t pending );

uint8_t *
xcb_randr_get_output_property_data (const xcb_randr_get_output_property_reply_t *R );

int
xcb_randr_get_output_property_data_length (const xcb_randr_get_output_property_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_output_property_data_end (const xcb_randr_get_output_property_reply_t *R );
xcb_randr_get_output_property_reply_t *
xcb_randr_get_output_property_reply (xcb_connection_t *c ,
                                     xcb_randr_get_output_property_cookie_t cookie ,
                                     xcb_generic_error_t **e );

int
xcb_randr_create_mode_sizeof (const void *_buffer ,
                              uint32_t name_len );
xcb_randr_create_mode_cookie_t
xcb_randr_create_mode (xcb_connection_t *c ,
                       xcb_window_t window ,
                       xcb_randr_mode_info_t mode_info ,
                       uint32_t name_len ,
                       const char *name );
xcb_randr_create_mode_cookie_t
xcb_randr_create_mode_unchecked (xcb_connection_t *c ,
                                 xcb_window_t window ,
                                 xcb_randr_mode_info_t mode_info ,
                                 uint32_t name_len ,
                                 const char *name );
xcb_randr_create_mode_reply_t *
xcb_randr_create_mode_reply (xcb_connection_t *c ,
                             xcb_randr_create_mode_cookie_t cookie ,
                             xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_randr_destroy_mode_checked (xcb_connection_t *c ,
                                xcb_randr_mode_t mode );
xcb_void_cookie_t
xcb_randr_destroy_mode (xcb_connection_t *c ,
                        xcb_randr_mode_t mode );
xcb_void_cookie_t
xcb_randr_add_output_mode_checked (xcb_connection_t *c ,
                                   xcb_randr_output_t output ,
                                   xcb_randr_mode_t mode );
xcb_void_cookie_t
xcb_randr_add_output_mode (xcb_connection_t *c ,
                           xcb_randr_output_t output ,
                           xcb_randr_mode_t mode );
xcb_void_cookie_t
xcb_randr_delete_output_mode_checked (xcb_connection_t *c ,
                                      xcb_randr_output_t output ,
                                      xcb_randr_mode_t mode );
xcb_void_cookie_t
xcb_randr_delete_output_mode (xcb_connection_t *c ,
                              xcb_randr_output_t output ,
                              xcb_randr_mode_t mode );

int
xcb_randr_get_crtc_info_sizeof (const void *_buffer );
xcb_randr_get_crtc_info_cookie_t
xcb_randr_get_crtc_info (xcb_connection_t *c ,
                         xcb_randr_crtc_t crtc ,
                         xcb_timestamp_t config_timestamp );
xcb_randr_get_crtc_info_cookie_t
xcb_randr_get_crtc_info_unchecked (xcb_connection_t *c ,
                                   xcb_randr_crtc_t crtc ,
                                   xcb_timestamp_t config_timestamp );

xcb_randr_output_t *
xcb_randr_get_crtc_info_outputs (const xcb_randr_get_crtc_info_reply_t *R );

int
xcb_randr_get_crtc_info_outputs_length (const xcb_randr_get_crtc_info_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_crtc_info_outputs_end (const xcb_randr_get_crtc_info_reply_t *R );

xcb_randr_output_t *
xcb_randr_get_crtc_info_possible (const xcb_randr_get_crtc_info_reply_t *R );

int
xcb_randr_get_crtc_info_possible_length (const xcb_randr_get_crtc_info_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_crtc_info_possible_end (const xcb_randr_get_crtc_info_reply_t *R );
xcb_randr_get_crtc_info_reply_t *
xcb_randr_get_crtc_info_reply (xcb_connection_t *c ,
                               xcb_randr_get_crtc_info_cookie_t cookie ,
                               xcb_generic_error_t **e );

int
xcb_randr_set_crtc_config_sizeof (const void *_buffer ,
                                  uint32_t outputs_len );
xcb_randr_set_crtc_config_cookie_t
xcb_randr_set_crtc_config (xcb_connection_t *c ,
                           xcb_randr_crtc_t crtc ,
                           xcb_timestamp_t timestamp ,
                           xcb_timestamp_t config_timestamp ,
                           int16_t x ,
                           int16_t y ,
                           xcb_randr_mode_t mode ,
                           uint16_t rotation ,
                           uint32_t outputs_len ,
                           const xcb_randr_output_t *outputs );
xcb_randr_set_crtc_config_cookie_t
xcb_randr_set_crtc_config_unchecked (xcb_connection_t *c ,
                                     xcb_randr_crtc_t crtc ,
                                     xcb_timestamp_t timestamp ,
                                     xcb_timestamp_t config_timestamp ,
                                     int16_t x ,
                                     int16_t y ,
                                     xcb_randr_mode_t mode ,
                                     uint16_t rotation ,
                                     uint32_t outputs_len ,
                                     const xcb_randr_output_t *outputs );
xcb_randr_set_crtc_config_reply_t *
xcb_randr_set_crtc_config_reply (xcb_connection_t *c ,
                                 xcb_randr_set_crtc_config_cookie_t cookie ,
                                 xcb_generic_error_t **e );
xcb_randr_get_crtc_gamma_size_cookie_t
xcb_randr_get_crtc_gamma_size (xcb_connection_t *c ,
                               xcb_randr_crtc_t crtc );
xcb_randr_get_crtc_gamma_size_cookie_t
xcb_randr_get_crtc_gamma_size_unchecked (xcb_connection_t *c ,
                                         xcb_randr_crtc_t crtc );
xcb_randr_get_crtc_gamma_size_reply_t *
xcb_randr_get_crtc_gamma_size_reply (xcb_connection_t *c ,
                                     xcb_randr_get_crtc_gamma_size_cookie_t cookie ,
                                     xcb_generic_error_t **e );

int
xcb_randr_get_crtc_gamma_sizeof (const void *_buffer );
xcb_randr_get_crtc_gamma_cookie_t
xcb_randr_get_crtc_gamma (xcb_connection_t *c ,
                          xcb_randr_crtc_t crtc );
xcb_randr_get_crtc_gamma_cookie_t
xcb_randr_get_crtc_gamma_unchecked (xcb_connection_t *c ,
                                    xcb_randr_crtc_t crtc );

uint16_t *
xcb_randr_get_crtc_gamma_red (const xcb_randr_get_crtc_gamma_reply_t *R );

int
xcb_randr_get_crtc_gamma_red_length (const xcb_randr_get_crtc_gamma_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_crtc_gamma_red_end (const xcb_randr_get_crtc_gamma_reply_t *R );

uint16_t *
xcb_randr_get_crtc_gamma_green (const xcb_randr_get_crtc_gamma_reply_t *R );

int
xcb_randr_get_crtc_gamma_green_length (const xcb_randr_get_crtc_gamma_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_crtc_gamma_green_end (const xcb_randr_get_crtc_gamma_reply_t *R );

uint16_t *
xcb_randr_get_crtc_gamma_blue (const xcb_randr_get_crtc_gamma_reply_t *R );

int
xcb_randr_get_crtc_gamma_blue_length (const xcb_randr_get_crtc_gamma_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_crtc_gamma_blue_end (const xcb_randr_get_crtc_gamma_reply_t *R );
xcb_randr_get_crtc_gamma_reply_t *
xcb_randr_get_crtc_gamma_reply (xcb_connection_t *c ,
                                xcb_randr_get_crtc_gamma_cookie_t cookie ,
                                xcb_generic_error_t **e );

int
xcb_randr_set_crtc_gamma_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_randr_set_crtc_gamma_checked (xcb_connection_t *c ,
                                  xcb_randr_crtc_t crtc ,
                                  uint16_t size ,
                                  const uint16_t *red ,
                                  const uint16_t *green ,
                                  const uint16_t *blue );
xcb_void_cookie_t
xcb_randr_set_crtc_gamma (xcb_connection_t *c ,
                          xcb_randr_crtc_t crtc ,
                          uint16_t size ,
                          const uint16_t *red ,
                          const uint16_t *green ,
                          const uint16_t *blue );

int
xcb_randr_get_screen_resources_current_sizeof (const void *_buffer );
xcb_randr_get_screen_resources_current_cookie_t
xcb_randr_get_screen_resources_current (xcb_connection_t *c ,
                                        xcb_window_t window );
xcb_randr_get_screen_resources_current_cookie_t
xcb_randr_get_screen_resources_current_unchecked (xcb_connection_t *c ,
                                                  xcb_window_t window );

xcb_randr_crtc_t *
xcb_randr_get_screen_resources_current_crtcs (const xcb_randr_get_screen_resources_current_reply_t *R );

int
xcb_randr_get_screen_resources_current_crtcs_length (const xcb_randr_get_screen_resources_current_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_screen_resources_current_crtcs_end (const xcb_randr_get_screen_resources_current_reply_t *R );

xcb_randr_output_t *
xcb_randr_get_screen_resources_current_outputs (const xcb_randr_get_screen_resources_current_reply_t *R );

int
xcb_randr_get_screen_resources_current_outputs_length (const xcb_randr_get_screen_resources_current_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_screen_resources_current_outputs_end (const xcb_randr_get_screen_resources_current_reply_t *R );

xcb_randr_mode_info_t *
xcb_randr_get_screen_resources_current_modes (const xcb_randr_get_screen_resources_current_reply_t *R );

int
xcb_randr_get_screen_resources_current_modes_length (const xcb_randr_get_screen_resources_current_reply_t *R );

xcb_randr_mode_info_iterator_t
xcb_randr_get_screen_resources_current_modes_iterator (const xcb_randr_get_screen_resources_current_reply_t *R );

uint8_t *
xcb_randr_get_screen_resources_current_names (const xcb_randr_get_screen_resources_current_reply_t *R );

int
xcb_randr_get_screen_resources_current_names_length (const xcb_randr_get_screen_resources_current_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_screen_resources_current_names_end (const xcb_randr_get_screen_resources_current_reply_t *R );
xcb_randr_get_screen_resources_current_reply_t *
xcb_randr_get_screen_resources_current_reply (xcb_connection_t *c ,
                                              xcb_randr_get_screen_resources_current_cookie_t cookie ,
                                              xcb_generic_error_t **e );

int
xcb_randr_set_crtc_transform_sizeof (const void *_buffer ,
                                     uint32_t filter_params_len );
xcb_void_cookie_t
xcb_randr_set_crtc_transform_checked (xcb_connection_t *c ,
                                      xcb_randr_crtc_t crtc ,
                                      xcb_render_transform_t transform ,
                                      uint16_t filter_len ,
                                      const char *filter_name ,
                                      uint32_t filter_params_len ,
                                      const xcb_render_fixed_t *filter_params );
xcb_void_cookie_t
xcb_randr_set_crtc_transform (xcb_connection_t *c ,
                              xcb_randr_crtc_t crtc ,
                              xcb_render_transform_t transform ,
                              uint16_t filter_len ,
                              const char *filter_name ,
                              uint32_t filter_params_len ,
                              const xcb_render_fixed_t *filter_params );

int
xcb_randr_get_crtc_transform_sizeof (const void *_buffer );
xcb_randr_get_crtc_transform_cookie_t
xcb_randr_get_crtc_transform (xcb_connection_t *c ,
                              xcb_randr_crtc_t crtc );
xcb_randr_get_crtc_transform_cookie_t
xcb_randr_get_crtc_transform_unchecked (xcb_connection_t *c ,
                                        xcb_randr_crtc_t crtc );

char *
xcb_randr_get_crtc_transform_pending_filter_name (const xcb_randr_get_crtc_transform_reply_t *R );

int
xcb_randr_get_crtc_transform_pending_filter_name_length (const xcb_randr_get_crtc_transform_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_crtc_transform_pending_filter_name_end (const xcb_randr_get_crtc_transform_reply_t *R );

xcb_render_fixed_t *
xcb_randr_get_crtc_transform_pending_params (const xcb_randr_get_crtc_transform_reply_t *R );

int
xcb_randr_get_crtc_transform_pending_params_length (const xcb_randr_get_crtc_transform_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_crtc_transform_pending_params_end (const xcb_randr_get_crtc_transform_reply_t *R );

char *
xcb_randr_get_crtc_transform_current_filter_name (const xcb_randr_get_crtc_transform_reply_t *R );

int
xcb_randr_get_crtc_transform_current_filter_name_length (const xcb_randr_get_crtc_transform_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_crtc_transform_current_filter_name_end (const xcb_randr_get_crtc_transform_reply_t *R );

xcb_render_fixed_t *
xcb_randr_get_crtc_transform_current_params (const xcb_randr_get_crtc_transform_reply_t *R );

int
xcb_randr_get_crtc_transform_current_params_length (const xcb_randr_get_crtc_transform_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_crtc_transform_current_params_end (const xcb_randr_get_crtc_transform_reply_t *R );
xcb_randr_get_crtc_transform_reply_t *
xcb_randr_get_crtc_transform_reply (xcb_connection_t *c ,
                                    xcb_randr_get_crtc_transform_cookie_t cookie ,
                                    xcb_generic_error_t **e );
xcb_randr_get_panning_cookie_t
xcb_randr_get_panning (xcb_connection_t *c ,
                       xcb_randr_crtc_t crtc );
xcb_randr_get_panning_cookie_t
xcb_randr_get_panning_unchecked (xcb_connection_t *c ,
                                 xcb_randr_crtc_t crtc );
xcb_randr_get_panning_reply_t *
xcb_randr_get_panning_reply (xcb_connection_t *c ,
                             xcb_randr_get_panning_cookie_t cookie ,
                             xcb_generic_error_t **e );
xcb_randr_set_panning_cookie_t
xcb_randr_set_panning (xcb_connection_t *c ,
                       xcb_randr_crtc_t crtc ,
                       xcb_timestamp_t timestamp ,
                       uint16_t left ,
                       uint16_t top ,
                       uint16_t width ,
                       uint16_t height ,
                       uint16_t track_left ,
                       uint16_t track_top ,
                       uint16_t track_width ,
                       uint16_t track_height ,
                       int16_t border_left ,
                       int16_t border_top ,
                       int16_t border_right ,
                       int16_t border_bottom );
xcb_randr_set_panning_cookie_t
xcb_randr_set_panning_unchecked (xcb_connection_t *c ,
                                 xcb_randr_crtc_t crtc ,
                                 xcb_timestamp_t timestamp ,
                                 uint16_t left ,
                                 uint16_t top ,
                                 uint16_t width ,
                                 uint16_t height ,
                                 uint16_t track_left ,
                                 uint16_t track_top ,
                                 uint16_t track_width ,
                                 uint16_t track_height ,
                                 int16_t border_left ,
                                 int16_t border_top ,
                                 int16_t border_right ,
                                 int16_t border_bottom );
xcb_randr_set_panning_reply_t *
xcb_randr_set_panning_reply (xcb_connection_t *c ,
                             xcb_randr_set_panning_cookie_t cookie ,
                             xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_randr_set_output_primary_checked (xcb_connection_t *c ,
                                      xcb_window_t window ,
                                      xcb_randr_output_t output );
xcb_void_cookie_t
xcb_randr_set_output_primary (xcb_connection_t *c ,
                              xcb_window_t window ,
                              xcb_randr_output_t output );
xcb_randr_get_output_primary_cookie_t
xcb_randr_get_output_primary (xcb_connection_t *c ,
                              xcb_window_t window );
xcb_randr_get_output_primary_cookie_t
xcb_randr_get_output_primary_unchecked (xcb_connection_t *c ,
                                        xcb_window_t window );
xcb_randr_get_output_primary_reply_t *
xcb_randr_get_output_primary_reply (xcb_connection_t *c ,
                                    xcb_randr_get_output_primary_cookie_t cookie ,
                                    xcb_generic_error_t **e );

int
xcb_randr_get_providers_sizeof (const void *_buffer );
xcb_randr_get_providers_cookie_t
xcb_randr_get_providers (xcb_connection_t *c ,
                         xcb_window_t window );
xcb_randr_get_providers_cookie_t
xcb_randr_get_providers_unchecked (xcb_connection_t *c ,
                                   xcb_window_t window );

xcb_randr_provider_t *
xcb_randr_get_providers_providers (const xcb_randr_get_providers_reply_t *R );

int
xcb_randr_get_providers_providers_length (const xcb_randr_get_providers_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_providers_providers_end (const xcb_randr_get_providers_reply_t *R );
xcb_randr_get_providers_reply_t *
xcb_randr_get_providers_reply (xcb_connection_t *c ,
                               xcb_randr_get_providers_cookie_t cookie ,
                               xcb_generic_error_t **e );

int
xcb_randr_get_provider_info_sizeof (const void *_buffer );
xcb_randr_get_provider_info_cookie_t
xcb_randr_get_provider_info (xcb_connection_t *c ,
                             xcb_randr_provider_t provider ,
                             xcb_timestamp_t config_timestamp );
xcb_randr_get_provider_info_cookie_t
xcb_randr_get_provider_info_unchecked (xcb_connection_t *c ,
                                       xcb_randr_provider_t provider ,
                                       xcb_timestamp_t config_timestamp );

xcb_randr_crtc_t *
xcb_randr_get_provider_info_crtcs (const xcb_randr_get_provider_info_reply_t *R );

int
xcb_randr_get_provider_info_crtcs_length (const xcb_randr_get_provider_info_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_provider_info_crtcs_end (const xcb_randr_get_provider_info_reply_t *R );

xcb_randr_output_t *
xcb_randr_get_provider_info_outputs (const xcb_randr_get_provider_info_reply_t *R );

int
xcb_randr_get_provider_info_outputs_length (const xcb_randr_get_provider_info_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_provider_info_outputs_end (const xcb_randr_get_provider_info_reply_t *R );

xcb_randr_provider_t *
xcb_randr_get_provider_info_associated_providers (const xcb_randr_get_provider_info_reply_t *R );

int
xcb_randr_get_provider_info_associated_providers_length (const xcb_randr_get_provider_info_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_provider_info_associated_providers_end (const xcb_randr_get_provider_info_reply_t *R );

uint32_t *
xcb_randr_get_provider_info_associated_capability (const xcb_randr_get_provider_info_reply_t *R );

int
xcb_randr_get_provider_info_associated_capability_length (const xcb_randr_get_provider_info_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_provider_info_associated_capability_end (const xcb_randr_get_provider_info_reply_t *R );

char *
xcb_randr_get_provider_info_name (const xcb_randr_get_provider_info_reply_t *R );

int
xcb_randr_get_provider_info_name_length (const xcb_randr_get_provider_info_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_provider_info_name_end (const xcb_randr_get_provider_info_reply_t *R );
xcb_randr_get_provider_info_reply_t *
xcb_randr_get_provider_info_reply (xcb_connection_t *c ,
                                   xcb_randr_get_provider_info_cookie_t cookie ,
                                   xcb_generic_error_t **e );
xcb_void_cookie_t
xcb_randr_set_provider_offload_sink_checked (xcb_connection_t *c ,
                                             xcb_randr_provider_t provider ,
                                             xcb_randr_provider_t sink_provider ,
                                             xcb_timestamp_t config_timestamp );
xcb_void_cookie_t
xcb_randr_set_provider_offload_sink (xcb_connection_t *c ,
                                     xcb_randr_provider_t provider ,
                                     xcb_randr_provider_t sink_provider ,
                                     xcb_timestamp_t config_timestamp );
xcb_void_cookie_t
xcb_randr_set_provider_output_source_checked (xcb_connection_t *c ,
                                              xcb_randr_provider_t provider ,
                                              xcb_randr_provider_t source_provider ,
                                              xcb_timestamp_t config_timestamp );
xcb_void_cookie_t
xcb_randr_set_provider_output_source (xcb_connection_t *c ,
                                      xcb_randr_provider_t provider ,
                                      xcb_randr_provider_t source_provider ,
                                      xcb_timestamp_t config_timestamp );

int
xcb_randr_list_provider_properties_sizeof (const void *_buffer );
xcb_randr_list_provider_properties_cookie_t
xcb_randr_list_provider_properties (xcb_connection_t *c ,
                                    xcb_randr_provider_t provider );
xcb_randr_list_provider_properties_cookie_t
xcb_randr_list_provider_properties_unchecked (xcb_connection_t *c ,
                                              xcb_randr_provider_t provider );

xcb_atom_t *
xcb_randr_list_provider_properties_atoms (const xcb_randr_list_provider_properties_reply_t *R );

int
xcb_randr_list_provider_properties_atoms_length (const xcb_randr_list_provider_properties_reply_t *R );

xcb_generic_iterator_t
xcb_randr_list_provider_properties_atoms_end (const xcb_randr_list_provider_properties_reply_t *R );
xcb_randr_list_provider_properties_reply_t *
xcb_randr_list_provider_properties_reply (xcb_connection_t *c ,
                                          xcb_randr_list_provider_properties_cookie_t cookie ,
                                          xcb_generic_error_t **e );

int
xcb_randr_query_provider_property_sizeof (const void *_buffer );
xcb_randr_query_provider_property_cookie_t
xcb_randr_query_provider_property (xcb_connection_t *c ,
                                   xcb_randr_provider_t provider ,
                                   xcb_atom_t property );
xcb_randr_query_provider_property_cookie_t
xcb_randr_query_provider_property_unchecked (xcb_connection_t *c ,
                                             xcb_randr_provider_t provider ,
                                             xcb_atom_t property );

int32_t *
xcb_randr_query_provider_property_valid_values (const xcb_randr_query_provider_property_reply_t *R );

int
xcb_randr_query_provider_property_valid_values_length (const xcb_randr_query_provider_property_reply_t *R );

xcb_generic_iterator_t
xcb_randr_query_provider_property_valid_values_end (const xcb_randr_query_provider_property_reply_t *R );
xcb_randr_query_provider_property_reply_t *
xcb_randr_query_provider_property_reply (xcb_connection_t *c ,
                                         xcb_randr_query_provider_property_cookie_t cookie ,
                                         xcb_generic_error_t **e );

int
xcb_randr_configure_provider_property_sizeof (const void *_buffer ,
                                              uint32_t values_len );
xcb_void_cookie_t
xcb_randr_configure_provider_property_checked (xcb_connection_t *c ,
                                               xcb_randr_provider_t provider ,
                                               xcb_atom_t property ,
                                               uint8_t pending ,
                                               uint8_t range ,
                                               uint32_t values_len ,
                                               const int32_t *values );
xcb_void_cookie_t
xcb_randr_configure_provider_property (xcb_connection_t *c ,
                                       xcb_randr_provider_t provider ,
                                       xcb_atom_t property ,
                                       uint8_t pending ,
                                       uint8_t range ,
                                       uint32_t values_len ,
                                       const int32_t *values );

int
xcb_randr_change_provider_property_sizeof (const void *_buffer );
xcb_void_cookie_t
xcb_randr_change_provider_property_checked (xcb_connection_t *c ,
                                            xcb_randr_provider_t provider ,
                                            xcb_atom_t property ,
                                            xcb_atom_t type ,
                                            uint8_t format ,
                                            uint8_t mode ,
                                            uint32_t num_items ,
                                            const void *data );
xcb_void_cookie_t
xcb_randr_change_provider_property (xcb_connection_t *c ,
                                    xcb_randr_provider_t provider ,
                                    xcb_atom_t property ,
                                    xcb_atom_t type ,
                                    uint8_t format ,
                                    uint8_t mode ,
                                    uint32_t num_items ,
                                    const void *data );
xcb_void_cookie_t
xcb_randr_delete_provider_property_checked (xcb_connection_t *c ,
                                            xcb_randr_provider_t provider ,
                                            xcb_atom_t property );
xcb_void_cookie_t
xcb_randr_delete_provider_property (xcb_connection_t *c ,
                                    xcb_randr_provider_t provider ,
                                    xcb_atom_t property );

int
xcb_randr_get_provider_property_sizeof (const void *_buffer );
xcb_randr_get_provider_property_cookie_t
xcb_randr_get_provider_property (xcb_connection_t *c ,
                                 xcb_randr_provider_t provider ,
                                 xcb_atom_t property ,
                                 xcb_atom_t type ,
                                 uint32_t long_offset ,
                                 uint32_t long_length ,
                                 uint8_t _delete ,
                                 uint8_t pending );
xcb_randr_get_provider_property_cookie_t
xcb_randr_get_provider_property_unchecked (xcb_connection_t *c ,
                                           xcb_randr_provider_t provider ,
                                           xcb_atom_t property ,
                                           xcb_atom_t type ,
                                           uint32_t long_offset ,
                                           uint32_t long_length ,
                                           uint8_t _delete ,
                                           uint8_t pending );

void *
xcb_randr_get_provider_property_data (const xcb_randr_get_provider_property_reply_t *R );

int
xcb_randr_get_provider_property_data_length (const xcb_randr_get_provider_property_reply_t *R );

xcb_generic_iterator_t
xcb_randr_get_provider_property_data_end (const xcb_randr_get_provider_property_reply_t *R );
xcb_randr_get_provider_property_reply_t *
xcb_randr_get_provider_property_reply (xcb_connection_t *c ,
                                       xcb_randr_get_provider_property_cookie_t cookie ,
                                       xcb_generic_error_t **e );
void
xcb_randr_crtc_change_next (xcb_randr_crtc_change_iterator_t *i );
xcb_generic_iterator_t
xcb_randr_crtc_change_end (xcb_randr_crtc_change_iterator_t i );
void
xcb_randr_output_change_next (xcb_randr_output_change_iterator_t *i );
xcb_generic_iterator_t
xcb_randr_output_change_end (xcb_randr_output_change_iterator_t i );
void
xcb_randr_output_property_next (xcb_randr_output_property_iterator_t *i );
xcb_generic_iterator_t
xcb_randr_output_property_end (xcb_randr_output_property_iterator_t i );
void
xcb_randr_provider_change_next (xcb_randr_provider_change_iterator_t *i );
xcb_generic_iterator_t
xcb_randr_provider_change_end (xcb_randr_provider_change_iterator_t i );
void
xcb_randr_provider_property_next (xcb_randr_provider_property_iterator_t *i );
xcb_generic_iterator_t
xcb_randr_provider_property_end (xcb_randr_provider_property_iterator_t i );
void
xcb_randr_resource_change_next (xcb_randr_resource_change_iterator_t *i );
xcb_generic_iterator_t
xcb_randr_resource_change_end (xcb_randr_resource_change_iterator_t i );
void
xcb_randr_notify_data_next (xcb_randr_notify_data_iterator_t *i );
xcb_generic_iterator_t
xcb_randr_notify_data_end (xcb_randr_notify_data_iterator_t i );
extern xcb_extension_t xcb_xinerama_id;




typedef struct xcb_xinerama_screen_info_t {
    int16_t x_org;
    int16_t y_org;
    uint16_t width;
    uint16_t height;
} xcb_xinerama_screen_info_t;




typedef struct xcb_xinerama_screen_info_iterator_t {
    xcb_xinerama_screen_info_t *data;
    int rem;
    int index;
} xcb_xinerama_screen_info_iterator_t;




typedef struct xcb_xinerama_query_version_cookie_t {
    unsigned int sequence;
} xcb_xinerama_query_version_cookie_t;







typedef struct xcb_xinerama_query_version_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    uint8_t major;
    uint8_t minor;
} xcb_xinerama_query_version_request_t;




typedef struct xcb_xinerama_query_version_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint16_t major;
    uint16_t minor;
} xcb_xinerama_query_version_reply_t;




typedef struct xcb_xinerama_get_state_cookie_t {
    unsigned int sequence;
} xcb_xinerama_get_state_cookie_t;







typedef struct xcb_xinerama_get_state_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_window_t window;
} xcb_xinerama_get_state_request_t;




typedef struct xcb_xinerama_get_state_reply_t {
    uint8_t response_type;
    uint8_t state;
    uint16_t sequence;
    uint32_t length;
    xcb_window_t window;
} xcb_xinerama_get_state_reply_t;




typedef struct xcb_xinerama_get_screen_count_cookie_t {
    unsigned int sequence;
} xcb_xinerama_get_screen_count_cookie_t;







typedef struct xcb_xinerama_get_screen_count_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_window_t window;
} xcb_xinerama_get_screen_count_request_t;




typedef struct xcb_xinerama_get_screen_count_reply_t {
    uint8_t response_type;
    uint8_t screen_count;
    uint16_t sequence;
    uint32_t length;
    xcb_window_t window;
} xcb_xinerama_get_screen_count_reply_t;




typedef struct xcb_xinerama_get_screen_size_cookie_t {
    unsigned int sequence;
} xcb_xinerama_get_screen_size_cookie_t;







typedef struct xcb_xinerama_get_screen_size_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
    xcb_window_t window;
    uint32_t screen;
} xcb_xinerama_get_screen_size_request_t;




typedef struct xcb_xinerama_get_screen_size_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint32_t width;
    uint32_t height;
    xcb_window_t window;
    uint32_t screen;
} xcb_xinerama_get_screen_size_reply_t;




typedef struct xcb_xinerama_is_active_cookie_t {
    unsigned int sequence;
} xcb_xinerama_is_active_cookie_t;







typedef struct xcb_xinerama_is_active_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
} xcb_xinerama_is_active_request_t;




typedef struct xcb_xinerama_is_active_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint32_t state;
} xcb_xinerama_is_active_reply_t;




typedef struct xcb_xinerama_query_screens_cookie_t {
    unsigned int sequence;
} xcb_xinerama_query_screens_cookie_t;







typedef struct xcb_xinerama_query_screens_request_t {
    uint8_t major_opcode;
    uint8_t minor_opcode;
    uint16_t length;
} xcb_xinerama_query_screens_request_t;




typedef struct xcb_xinerama_query_screens_reply_t {
    uint8_t response_type;
    uint8_t pad0;
    uint16_t sequence;
    uint32_t length;
    uint32_t number;
    uint8_t pad1[20];
} xcb_xinerama_query_screens_reply_t;
void
xcb_xinerama_screen_info_next (xcb_xinerama_screen_info_iterator_t *i );
xcb_generic_iterator_t
xcb_xinerama_screen_info_end (xcb_xinerama_screen_info_iterator_t i );
xcb_xinerama_query_version_cookie_t
xcb_xinerama_query_version (xcb_connection_t *c ,
                            uint8_t major ,
                            uint8_t minor );
xcb_xinerama_query_version_cookie_t
xcb_xinerama_query_version_unchecked (xcb_connection_t *c ,
                                      uint8_t major ,
                                      uint8_t minor );
xcb_xinerama_query_version_reply_t *
xcb_xinerama_query_version_reply (xcb_connection_t *c ,
                                  xcb_xinerama_query_version_cookie_t cookie ,
                                  xcb_generic_error_t **e );
xcb_xinerama_get_state_cookie_t
xcb_xinerama_get_state (xcb_connection_t *c ,
                        xcb_window_t window );
xcb_xinerama_get_state_cookie_t
xcb_xinerama_get_state_unchecked (xcb_connection_t *c ,
                                  xcb_window_t window );
xcb_xinerama_get_state_reply_t *
xcb_xinerama_get_state_reply (xcb_connection_t *c ,
                              xcb_xinerama_get_state_cookie_t cookie ,
                              xcb_generic_error_t **e );
xcb_xinerama_get_screen_count_cookie_t
xcb_xinerama_get_screen_count (xcb_connection_t *c ,
                               xcb_window_t window );
xcb_xinerama_get_screen_count_cookie_t
xcb_xinerama_get_screen_count_unchecked (xcb_connection_t *c ,
                                         xcb_window_t window );
xcb_xinerama_get_screen_count_reply_t *
xcb_xinerama_get_screen_count_reply (xcb_connection_t *c ,
                                     xcb_xinerama_get_screen_count_cookie_t cookie ,
                                     xcb_generic_error_t **e );
xcb_xinerama_get_screen_size_cookie_t
xcb_xinerama_get_screen_size (xcb_connection_t *c ,
                              xcb_window_t window ,
                              uint32_t screen );
xcb_xinerama_get_screen_size_cookie_t
xcb_xinerama_get_screen_size_unchecked (xcb_connection_t *c ,
                                        xcb_window_t window ,
                                        uint32_t screen );
xcb_xinerama_get_screen_size_reply_t *
xcb_xinerama_get_screen_size_reply (xcb_connection_t *c ,
                                    xcb_xinerama_get_screen_size_cookie_t cookie ,
                                    xcb_generic_error_t **e );
xcb_xinerama_is_active_cookie_t
xcb_xinerama_is_active (xcb_connection_t *c );
xcb_xinerama_is_active_cookie_t
xcb_xinerama_is_active_unchecked (xcb_connection_t *c );
xcb_xinerama_is_active_reply_t *
xcb_xinerama_is_active_reply (xcb_connection_t *c ,
                              xcb_xinerama_is_active_cookie_t cookie ,
                              xcb_generic_error_t **e );

int
xcb_xinerama_query_screens_sizeof (const void *_buffer );
xcb_xinerama_query_screens_cookie_t
xcb_xinerama_query_screens (xcb_connection_t *c );
xcb_xinerama_query_screens_cookie_t
xcb_xinerama_query_screens_unchecked (xcb_connection_t *c );

xcb_xinerama_screen_info_t *
xcb_xinerama_query_screens_screen_info (const xcb_xinerama_query_screens_reply_t *R );

int
xcb_xinerama_query_screens_screen_info_length (const xcb_xinerama_query_screens_reply_t *R );

xcb_xinerama_screen_info_iterator_t
xcb_xinerama_query_screens_screen_info_iterator (const xcb_xinerama_query_screens_reply_t *R );
xcb_xinerama_query_screens_reply_t *
xcb_xinerama_query_screens_reply (xcb_connection_t *c ,
                                  xcb_xinerama_query_screens_cookie_t cookie ,
                                  xcb_generic_error_t **e );
