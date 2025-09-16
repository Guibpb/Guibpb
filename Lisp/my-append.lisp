(defun my-append (L1 L2)
    (if (null L1)
        L2
        (cons (car L1) (my-append (cdr L1) L2))
    )
)   