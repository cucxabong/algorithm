package ds

import (
	"testing"
)

func TestEnqueue(t *testing.T) {
	var q Queue
	q.Enqueue(1)

	if q.IsEmpty() {
		t.Errorf("Queue size 0 not equal to expected 1")
	}

	item := q.Front()

	if item != nil && *item != 1 {
		t.Errorf("Output %d not equal to expected %d", *item, 1)
	}

	q.Enqueue(2)
	q.Enqueue(3)
	q.Enqueue(4)
	item = q.Front()
	if item != nil && *item != 1 {
		t.Errorf("Output %d not equal to expected %d", *item, 1)
	}
}

func TestDequeue(t *testing.T) {
	var q Queue
	q.Enqueue(1)
	q.Enqueue(2)

	item := q.Dequeue()
	if item != 1 {
		t.Errorf("Output %d not equal to expected %d", item, 1)
	}

	item = q.Dequeue()
	if item != 2 {
		t.Errorf("Output %d not equal to expected %d", item, 2)
	}

	if !q.IsEmpty() {
		t.Errorf("Queue size of %d not equal to expected %d", q.Size(), 0)
	}
}
