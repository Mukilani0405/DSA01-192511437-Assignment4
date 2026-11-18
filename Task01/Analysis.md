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
## Task 1.3 – Design Defence

The Staff base class stores common details such as name and ID, avoiding duplication. Professor, LabAssistant and GuestFaculty inherit from Staff and implement their own pay() function. If a new staff category is introduced, we only need to create a new derived class and override pay(). The existing classes do not need to be modified. Runtime polymorphism allows all staff objects to be processed using a common Staff pointer.
## Alternative Concept – Single Staff Class with Switch

An alternative approach is to create a single Staff class containing all possible staff details, such as basic salary, DA, research allowance, working hours and hourly rate. A type variable can identify the staff category, and a switch statement inside pay() can calculate the salary.

### Pseudocode

```text
FUNCTION pay()
    SWITCH staffType
        CASE PROFESSOR:
            RETURN basic + da + research
        CASE LAB_ASSISTANT:
            RETURN basic + da
        CASE GUEST_FACULTY:
            RETURN hours * rate
    END SWITCH
END FUNCTION
```

### Complexity Analysis

| Factor | Inheritance approach | Single class with switch |
|---|---|---|
| Time per pay() call | O(1) | O(1) |
| Space per object | Stores common and category-specific fields | Stores fields for all categories, including unused fields |
| Adding a new staff type | Add a new derived class | Modify the Staff class and switch statement |
| Code maintenance | Easier to extend | Becomes more difficult as categories increase |

### Comparison

Both approaches require constant time, O(1), for one pay() calculation. However, the single-class approach wastes memory because every object stores fields that may not be needed. It also requires changes to the existing class and switch statement when a new category is introduced.

The inheritance approach is more reusable and extensible because each staff category has its own class and salary calculation.

## Result

The payroll system was redesigned using inheritance and runtime polymorphism. The common Staff base class reduces duplication, while derived classes implement their own salary calculations.
