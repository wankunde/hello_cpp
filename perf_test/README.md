# Cache miss

## Perf stat

* LLC-loads-misses : last-level-cache load misses

More detail in https://www.brendangregg.com/perf.html

```
make

$ perf stat -e cache-misses ./build/cache_misses_test1

 Performance counter stats for './build/cache_misses_test1':

            38,747      cache-misses

       1.034864693 seconds time elapsed

       1.030978000 seconds user
       0.004011000 seconds sys


$ perf stat -e cache-misses ./build/cache_misses_test2

 Performance counter stats for './build/cache_misses_test2':

             8,151      cache-misses

       0.128977861 seconds time elapsed

       0.129166000 seconds user
       0.000000000 seconds sys
```

## perf report
```
$ perf record -e cache-misses ./build/cache_misses_test2
$ perf report

Samples: 786  of event 'cache-misses', Event count (approx.): 103577
Overhead  Command          Shared Object         Symbol
  69.91%  cache_misses_te  cache_misses_test1    [.] add
   8.42%  cache_misses_te  [kernel.kallsyms]     [k] mm_release
   2.91%  cache_misses_te  [kernel.kallsyms]     [k] clear_page_erms
   1.36%  cache_misses_te  [kernel.kallsyms]     [k] vma_interval_tree_insert
   1.36%  cache_misses_te  ld-linux-x86-64.so.2  [.] _dl_relocate_object
   1.35%  cache_misses_te  [kernel.kallsyms]     [k] add_mm_counter_fast
   1.35%  cache_misses_te  ld-linux-x86-64.so.2  [.] init_cpu_features.constprop.0
   1.32%  cache_misses_te  [kernel.kallsyms]     [k] __hrtimer_run_queues
   1.18%  cache_misses_te  ld-linux-x86-64.so.2  [.] _dl_fini
   1.17%  cache_misses_te  [kernel.kallsyms]     [k] vma_interval_tree_remove
   1.00%  cache_misses_te  [kernel.kallsyms]     [k] hrtimer_interrupt
   0.93%  cache_misses_te  [kernel.kallsyms]     [k] raw_notifier_call_chain
   0.60%  cache_misses_te  [kernel.kallsyms]     [k] tick_do_update_jiffies64
   0.56%  cache_misses_te  [kernel.kallsyms]     [k] rcu_sched_clock_irq
   0.52%  cache_misses_te  [kernel.kallsyms]     [k] move_page_tables
   0.50%  cache_misses_te  [kernel.kallsyms]     [k] timekeeping_update
   0.48%  cache_misses_te  [kernel.kallsyms]     [k] cpuacct_charge
   0.43%  cache_misses_te  [kvm]                 [k] pvclock_gtod_notify


$ perf record -e cache-misses ./build/cache_misses_test2
$ perf report

Samples: 19  of event 'cache-misses', Event count (approx.): 11964
Overhead  Command          Shared Object         Symbol
  56.15%  cache_misses_te  [kernel.kallsyms]     [k] __tlb_remove_page_size
  13.79%  cache_misses_te  libc.so.6             [.] __unregister_atfork
   5.55%  cache_misses_te  [kernel.kallsyms]     [k] __raw_spin_lock_irqsave
   5.53%  cache_misses_te  cache_misses_test2    [.] add
   3.38%  cache_misses_te  [kernel.kallsyms]     [k] vmacache_find
   3.38%  cache_misses_te  ld-linux-x86-64.so.2  [.] _dl_fini
   2.57%  cache_misses_te  [kernel.kallsyms]     [k] timerqueue_del
   2.28%  cache_misses_te  [kernel.kallsyms]     [k] __free_one_page
   1.40%  cache_misses_te  [kernel.kallsyms]     [k] blk_mq_complete_request_remote
   1.36%  cache_misses_te  [kernel.kallsyms]     [k] __update_blocked_fair
   1.20%  cache_misses_te  [kernel.kallsyms]     [k] folio_rotate_reclaimable
```

[Link1](https://blog.csdn.net/trochiluses/article/details/17346803)
