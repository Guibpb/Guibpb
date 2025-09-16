(defun quadrados (&rest nums)
    (mapcar (lambda(x) (expt x 2)) nums)
)

(defun somas (&rest nums)
    (apply #'+ nums)
)

(defun sao_numeros(&rest lista)
    (block bloco
        (dolist (x lista)
            (unless (numberp x)
                (return-from bloco "Não são todos números")
            )
        )
    "São todos números"
    )
)

(defun fibonacci (n &optional (soma-ant 1) (soma 0) (resultado '()))
    (if (= n 0)
        (reverse (cons soma resultado))
        (fibonacci (- n 1) soma (+ soma-ant soma) (cons soma resultado))
    )
)

