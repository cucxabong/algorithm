package ds

import (
	"sync"
)

type Queue struct {
	mu   sync.RWMutex
	data []int
}

func (q *Queue) Enqueue(item int) {
	q.mu.Lock()
	defer q.mu.Unlock()
	q.data = append(q.data, item)
}

func (q *Queue) Dequeue() int {
	q.mu.Lock()
	defer q.mu.Unlock()
	item := q.data[0]
	q.data = q.data[1:]
	return item
}

func (q *Queue) IsEmpty() bool {
	q.mu.RLock()
	defer q.mu.RUnlock()
	return len(q.data) == 0
}

func (q *Queue) Size() int {
	q.mu.RLock()
	defer q.mu.RUnlock()
	return len(q.data)
}

func (q *Queue) Front() *int {
	q.mu.RLock()
	defer q.mu.RUnlock()
	if len(q.data) > 0 {
		return &q.data[0]
	}

	return nil
}
