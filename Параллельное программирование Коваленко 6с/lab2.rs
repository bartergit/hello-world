use std::time::{Instant};
// use std::rand::{task_rng, Rng};


use std::thread;
fn do_thread_comp(thread_number: usize, size: usize) {
    let mut handles = vec![];
    for i in 0..thread_number{
        let handle = thread::spawn(move || {
            let new_size = size/thread_number;
            let mut array = vec![0; new_size];
            for j in 0..new_size {
                array[j] = i;
            }
            array
        });
        handles.push(handle);
    }
    let now = Instant::now();
    for handle in handles {
        let _res = handle.join().unwrap();
    }
    println!("thread_number: {}; time in millis: {}", thread_number, now.elapsed().as_millis());
}
fn main() {
    for i in 1..30 {
        do_thread_comp(i, 12_000_000);
    }
}