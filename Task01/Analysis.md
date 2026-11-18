# Task 1 – Class Design Review

## Task 1.1 – Diagnose the Design

The original payroll program contains several design deficiencies:

1. **Repeated data members:** Professor and LabAssistant contain common fields such as name, id and basic salary.
2. **Repeated pay calculation:** Professor and LabAssistant use the same basic salary and DA calculation.
3. **Public data members:** All data members are public, so they can be modified directly without proper validation.
4. **Inconsistent naming:** Professor and LabAssistant use `name` and `id`, whereas GuestFaculty uses `nm` and `code` for the same information.
5. **Unused DA field:** The `da` data member is declared but is not used in the pay calculation.
6. **Magic number:** The value `0.42` is directly written in the pay function instead of being declared as a named constant.
7. **Difficult extension:** Adding a new staff category requires creating another independent class and possibly duplicating existing code.
8. **No common processing:** All staff objects cannot be processed uniformly through a common base-class pointer.

## Conclusion

The original design contains duplication, poor data protection and limited extensibility. Inheritance and runtime polymorphism can solve these problems by introducing a common Staff base class.
