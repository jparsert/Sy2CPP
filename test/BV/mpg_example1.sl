; default grammar added
(set-logic BV)
(synth-fun ex((x (_ BitVec 32))(y (_ BitVec 32)))
 (_ BitVec 32)
(( NTnonbool (_ BitVec 32))(NTbool Bool))
((NTnonbool (_ BitVec 32)(x y (_ bv0 32) (_ bv1 32) (_ bv2 32) (_ bv3 32)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))
(NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))

)
)

(declare-var x (_ BitVec 32))
(declare-var y (_ BitVec 32))
( constraint  (or (and (bvuge x (_ bv5 32)) (= (ex x y ) (bvadd (bvadd (bvadd (bvadd (bvadd (bvadd x x) x) x) x) (bvadd (bvadd y y) y)) (_ bv17 32)))) (and (not (bvuge x (_ bv5 32))) (= (ex x y ) (bvadd (bvadd (bvadd x x) x) (_ bv1 32))))) ) 
(check-synth)
